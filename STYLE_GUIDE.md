# Style Guide

This is a living document that will morph over time.

## Goals

The goals of this style-guide are:

* To help you minimise compile-time errors.
* To focus on writing code that models best practices.
* To ensure your code optimises for the reader.
* To highlight when the linter or compiler diagnoses a problem.
  * When both the linter and compiler diagnose something, this means you'll see the same diagnostic
    twice.

If something isn't clear, consult the [C++ Core Guidelines][core-guidelines] for guidance.

## Non-goals

This guide doesn't place any emphasis on where braces go, or how many spaces to use per indentation.
That's instead left up to the formatter's config file, and can be customised once you're comfortable
with how to use C++ and understand how the tools work.

## Understanding clang-tidy

A compiler's job is to transform your source code (e.g. C++) into target code (e.g. amd64 assembly).
It does this by first scanning your program in from file, and checking that it meets all the rules
of the programming language. If you break a rule, it'll let you know. We call typically these
compiler errors.

Compilers also sometimes issue warnings. A warning is, more or less, a message to the programmer
that the compiler developers think that the code you've written falls into the realm of "common
mistakes". The compiler emit them has there is a chance this will have unintended side effects.
Even if your code is tested and works, warnings highlight that you may have hidden issues. It is
in your best interest to resolve them, especially if you don't understand the rational behind it;
there is a reason why they are emitted. Together, we call warnings and errors _diagnostics_. We
have turned many warnings on, and also told the compiler to treat all diagnosed warnings as errors
(note: we haven't turned on _all_ the warnings).

While a compiler _can_ diagnose warnings, it's not its primary job. That is secondary, and there are
many more useful checks that a tool could make that would make compilation take a very long time to
complete. We instead defer those to a _linter_ or _static analyser_, which is a way of opting into
expensive checks. clang-tidy is an example of a linter, and the one that we use.

A typical compiler error might look like this:

```cpp
error: declaration shadows a local variable [-Werror,-Wshadow]
        auto x = 0;
             ^
3:10: note: previous declaration is here
    auto x = 0;
         ^
```

clang-tidy will issue the following diagnostic:

```cpp
warning: declaration shadows a local variable [clang-diagnostic-shadow,-warnings-as-errors]
        auto x = 0;
             ^
3:10: note: previous declaration is here
    auto x = 0;
         ^
```

Notice that both tools have a way of telling you what went wrong. In the case of the compiler, it's
`[-Werror,-Wshadow]`, and clang-tidy offers `[clang-diagnostic-shadow,-warnings-as-errors]`. If
you're having a hard time understanding a particular message that the compiler gives you, then you
might like to consult the documentation:

* [Diagnostics for the compiler][diagnostics]
* [clang-tidy checks][clang-tidy]

These checks form an important part of our style guide, but since the list is so vast (and we don't
have a way of distilling it without overwhelming you), it's best to follow lecture and tutorial
materials, and only consult this documentation as the step before contacting your tutor or post on
the forum.

**If you do need to ask for help, be sure to copy your diagnostic so that we can help you.**

## Declarations and scope

### Names

Use this table for guidance when naming objects and functions.

<table>
  <thead>
    <th>Entity</th>
    <th>Naming style</th>
  </thead>
  <tr>
    <td>Template type parameters</td>
    <td><code>PascalCase</code></td>
  </tr>
  <tr>
    <td>Macros</td>
    <td><code>ALL_CAPS</code></td>
  </tr>
  <tr>
    <td>Private member objects</td>
    <td><code>snake_case_</code></td>
  </tr>
  <tr>
    <td>Everything else</td>
    <td><code>snake_case</code></td>
  </tr>
</table>

The linter will diagnose names that don't meet these requirements.

See also:

* [C++ Core Guideline ES.8][es8] _Avoid similar-looking names._
* [C++ Core Guideline ES.9][es9] _Avoid `ALL_CAPS` names._
* [C++ Core Guideline ES.10][es10] _Declare one name (only) per declaration._
* [C++ Core Guideline ES.26][es26] _Don’t use a variable for two unrelated purposes._
* [C++ Core Guideline ES.32][es32] _Use `ALL_CAPS` for all macro names._
* [C++ Core Guideline ES.33][es33] _If you must use macros, give them unique names._
* [C++ Core Guideline ES.45][es45] _Avoid “magic constants”; use symbolic constants._
* [C++ Core Guideline NL.19][nl19] _Avoid names that are easily misread._

The linter will diagnose ES.9, ES.10, and ES.45.

### Scope

See also:

* [C++ Core Guideline ES.5][es5] _Keep scopes small._
* [C++ Core Guideline ES.6][es6] _Declare names in `for`-statement initializers and conditions to
limit scope._
* [C++ Core Guideline ES.7][es7] _Keep common and local names short, and keep uncommon and
non-local names longer._
* [C++ Core Guideline ES.12][es12] _Do not reuse names in nested scopes._
* [C++ Core Guideline ES.12][es22] _Don’t declare a variable until you have a value to initialize
it with._
* [C++ Core Guideline NL.7][nl7] _Make the length of a name roughly proportional to the length of
its scope._

Both the linter and the compiler will diagnose ES.12.

### Always use `auto`

* Place `auto` on the left side of a name you introduce, and the type on the right-hand side of the
  `=`, if necessary.

```cpp
auto const i = 0; // okay, type deduced as int
auto const d = static_cast<double>(0); // prefer 0.0, as we have a literal
auto const v = std::vector<int>{0, 1, 2}; // okay, type on the right

auto const x = square(0); // okay
auto const y = static_cast<int>(square(0)); // okay: explicitly want an int
```

This practice will:

* identify when you declare a name (`auto` becomes a consistent prefix).
* ensure your variables are _always_ initialised (`auto x;` is ill-formed).
* help your code read more mathematically (e.g. "let `y` be a constant object of type `int`, with
  value `square(0)`".).
* minimise the number of times you need to say a name.
* match the syntax for declaring type aliases (`<keyword> <name> = <value>;`).
* match the syntax for names that can _only_ be declared with `auto`.

**Exceptions:**

* function parameters

See also:

* [C++ Core Guideline ES.11][es11] _Use `auto` to avoid redundant repetition of type names._
* [C++ Core Guideline ES.20][es20] _Always initialise an object._

### Consistent `const`

It's best to declare objects and member functions with the `const`-qualifier: the absence of
`const` should communicate to the reader that you intend to modify an object.

```cpp
// Example
auto const x = 42; // we don't intend to modify `x`
auto y = x; // we're starting with `y = x`, but we're communicating that we intend to modify `y`.

class int_wrapper {
public:
  auto value() const -> int; // no intention to change `value_`.
private:
  int value_ = 0;
};
```

C++ lets you put the `const`-qualifier on the left or the right in some cases, but in other cases,
it expressly requires that `const` be placed on the right of whatever it is modifying. As such, we
will always place `const` on the right side of `auto`, to reduce ambiguity.

**Exceptions:**

* Member objects should not be `const`-qualified unless you have a good reason (we instead qualify
  member functions).

See also:

* [C++ Core Guideline ES.25][es25] _Declare an object `const` or `constexpr` unless you want to
modify its value later on._
* [C++ Core Guideline Con.1][con1] _By default, make objects immutable._
* [C++ Core Guideline Con.2][con2] _By default, make member functions `const`._
* [C++ Core Guideline Con.3][con3] _By default, pass pointers  and references to `const`s._
* [C++ Core Guideline Con.4][con4] _Use `const` to define objects with values that do not change
after construction._
* [C++ Core Guideline Con.5][con5] _Use `constexpr` for values that can be computed at compile
time._
* _[Simplifying `const` Syntax][drdobbs-const]_ (Note: read this _after_ you've covered
resource management)

## Functions

### Prefer trailing return types

For historical reasons, C++ supports three ways to declare a function:

```cpp
int f();         // old, seen in Lecture 1
auto f() -> int; // modern: trailing return type
auto f();        // modern: type deduced
```

We prefer the modern approaches because they fit in with the rationale of the Always Auto idiom.
When you can conveniently type out the type of a function, prefer trailing return types to deduced
return types, for clarity.

### Calling functions

Always qualify your function calls to tell the compiler the function you intend to call. Even if it
seems obvious to a human reader, still fully qualify it!

See also:

* [Abseil Tip of the Week #49][totw49] _Argument-Dependent Lookup_ (Note: read only _after_ having
covered templates, or not at all.)

## Abstractions vs primitive language features

Prefer high-level abstractions such as ranges and algorithms to language features. This will help
you express code in a far more declarative and functional manner, and reveal _what_ you intend to
do, rather than _how_ you intend to acheive something.

```cpp
{ // Case 1: good, expresses *what* the programmer wants.
  auto const first100 = ranges::views::iota(0, 100) | ranges::to<std::vector>;
}
{ // Case 2: bad, expresses *how* the programmer wants to achieve their goal.
  // Also misses the opportunity to be made const.
  auto first100 = std::vector<int>{};
  for (auto i = 0; i < 100; ++i) {
    first100.push_back(i);
  }
}
```

See also:

* [C++ Core Guideline ES.1][es1] _Prefer the standard library to other libraries and to
“handcrafted code”._
* [C++ Core Guideline ES.2][es2] _Prefer suitable abstractions to direct use of language features._

## Statements (e.g. `if`, `for`, `while`, `goto`, etc.)

See the Core Guidelines section [ES: Expressions and statements][es], guidelines ES.70 through
ES.87.

Both the linter and compiler will diagnose ES.78. The linter _might_ diagnose ES.87 from time to
time.

## Conversions

It's best to avoid casts wherever possible, but when you inveitably need to make a conversion, make
them casts explicit. This lets you inform the reader that you _intend_ to perform a conversion.

The linter may _sometimes_ diagnose implicit conversions.

```cpp
{ // Case 1
  auto const x = 0;
  auto y = 0.0;

  y = x; // implicit promotion: questionable; did you mean the conversion?
  y = static_cast<double>(x); // explicit: clear you want the conversion.
}
{ // Case 2
  auto const x = 0;
  auto y = 0.0;

  x = y; // implicit narrowing: bad; did you mean to perform a lossy conversion?
  x = gsl_lite::narrow_cast<int>(y); // explicit: clear that you're aware of the narrowing.
}
```

See also:

* [C++ Core Guideline ES.46][es46] _Avoid lossy (narrowing, truncating) arithmetic conversions._
* [C++ Core Guideline ES.48][es48] _Avoid casts._
* [C++ Core Guideline ES.49][es49] _If you must use a cast, use a named cast._

## Interfaces

See the Core Guidelines section [I: Interfaces][interfaces].

## User-defined types

See the Core Guidelines section [C: Classes and class hierarchies][class].

## Comments

<blockquote>
  &ldquo;The compiler doesn't read comments and neither, do I.&rdquo;
  <footer>&#8212;Bjarne Stroustrup (allegedly)</footer>
</blockquote>
<br />
<blockquote>
  &ldquo;If the comment and code disagree, both are probably wrong.&rdquo;
  <footer>&#8212;Norm Schryer</footer>
</blockquote>

Always use comments to help the reader understand why you want to do something, but never to repeat
what your code is already saying. Comments to document what an interface does and expects are okay,
but keep them short and to the point.

See also:

* [C++ Core Guideline NL.1][nl1] _Don't say in comments what can clearly be stated in code._
* [C++ Core Guideline NL.2][nl2] _State intent in comments._
* [C++ Core Guideline NL.3][nl3] _Keep comments crisp._

## Performance

If you're going to write unclear code in the name of "performance", be sure to back up your claim
with a benchmark.

See also:

* [C++ Core Guideline Per.1][per1] _Don’t optimize without reason._
* [C++ Core Guideline Per.2][per2] _Don’t optimize prematurely._
* [C++ Core Guideline Per.3][per3] _Don’t optimize something that’s not performance critical._
* [C++ Core Guideline Per.4][per4] _Don’t assume that complicated code is necessarily faster than
simple code._
* [C++ Core Guideline Per.5][per5] _Don’t assume that low-level code is necessarily faster than
high-level code._
* [C++ Core Guideline Per.6][per6] _Don’t make claims about performance without measurements._
* [C++ Core Guideline Per.7][per7] _Design to enable optimisation._
* [C++ Core Guideline Per.10][per10] _Rely on the static type system._
* [C++ Core Guideline Per.19][per19] _Access memory predictably._

## Safety

Programming languages sometimes need to make tradeoffs between safety, portability, and optimisation
opportunities. Sometimes you can achieve all three, but sometimes you need to have the programmer
follow certain practices in order to meet certain portability or optimisation goals. The advice here
advises you of certain practices you'll need to follow for correctness. The linter or debug run-time
might pick you up on some of these, but it's not guaranteed.

* Exclusively read or write in an expression, but never do both.

See also:

* [C++ Core Guideline ES.43][es43] _Avoid Expressions with undefined order of evaluation._
* [C++ Core Guideline ES.44][es44] _Don't depend on order of evaluation of function arguments._
* [C++ Core Guideline ES.50][es50] _Don't cast away `const`._
* [C++ Core Guideline ES.65][es65] _Don't dereference an invalid pointer._

### `using namespace`

A lot of content on the web demonstrates code using what is called a _using-directive_. This is a
line in your code that looks like `using namespace std;` or `using namespace ranges;`. If you're not
already familiar with these lines, you can stop reading.

While it might seem like a good idea to use _using-directives_ for the brevity it offers, they're
actually a pain-point for many programmers, and especially for programmers who don't know the
intricacies of how a _using-directive_ works behind the scenes. Not only can it confuse a human
reader, but lax usage of it can confuse the compiler too! We find it best to use their cousin, the
_using-declaration_, which is `using std::vector;`. clang-tidy will flag most usages of a
_using-directive_, under `google-build-using-namespace`.

There are certain exceptions, such as `using namespace std::string_literals`, which exposes a single
name that can't otherwise be accessed. clang-tidy won't flag those. In these cases, we only place
these in the tightest scope necessary.

```cpp
// Not allowed (clang-tidy will error)
// using namespace std;
// using namespace absl;
// using namespace ranges;

// Allowed (clang-tidy will not error)
// using namespace std::string_literals;       // global scope, but no global strings: not okay

auto main() -> int {
  // using namespace std::string_literals; // no strings used in this scope: not okay
  {
    using namespace std::string_literals; // a string is declared in this scope; okay
    auto const course_code = "COMP6771"s;
  } // using-directive no longer valid after }
}
```

See also:

* [C++ Core Guideline SF.6][sf6]:
* [C++ Core Guideline SF.7][sf7]: _Don’t write `using namespace` at global scope in a header file._
* [Stack Overflow][stack-overflow-using-directive]: _Why is “using namespace std;” considered bad practice?_
* [Abseil Tip of the Week #49][totw49] _Argument-Dependent Lookup_ (Note: read only _after_ having
covered templates, or not at all.)

[drdobbs-const]: https://www.drdobbs.com/cpp/simplifying-const-syntax/231601151
[diagnostics]: https://clang.llvm.org/docs/DiagnosticsReference.html
[clang-tidy]: https://clang.llvm.org/extra/clang-tidy/checks/list.html
[core-guidelines]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
[totw49]: https://abseil.io/tips/49
[stack-overlow-using-directive]: https://stackoverflow.com/a/1453605/4097528

[interfaces]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-interfaces
[class]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-class

[con1]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconst-immutable
[con2]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconst-fct
[con3]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconst-ref
[con4]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconst-const
[con5]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconst-constexpr

[es1]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-lib
[es2]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-abstr
[es5]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-scope
[es6]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-cond
[es7]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-name-length
[es8]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-name-similar
[es9]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-not-CAPS
[es10]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-name-one
[es11]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-auto
[es12]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-reuse
[es20]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-always
[es22]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-init
[es25]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-const
[es26]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-recycle
[es32]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-ALL_CAPS
[es33]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-MACROS
[es43]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-order
[es44]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-order-fct
[es45]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-magic
[es46]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-narrowing
[es48]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-casts
[es49]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-casts-named
[es50]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-casts-const
[es65]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-deref
[es70]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-switch-if
[es71]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-for-range
[es72]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-for-while
[es73]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-while-for
[es74]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-for-init
[es75]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-do
[es76]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-goto
[es77]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-continue
[es78]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-break
[es79]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-default
[es85]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-empty
[es86]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-loop-counter
[es87]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-if

[per1]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rper-reason
[per2]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rper-Knuth
[per3]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rper-critical
[per4]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rper-simple
[per5]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rper-low
[per6]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rper-measure
[per7]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rper-efficiency
[per10]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rper-type
[per19]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rper-access

[nl1]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rl-comments
[nl2]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rl-comments-intent
[nl3]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rl-comments-crisp
[nl7]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rl-name-length
[nl19]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rl-misread

[sf7]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rs-using-directive
