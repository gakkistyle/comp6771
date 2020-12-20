# Overview

## 1. GitLab

An individual repository for you for this tut has been created for you on the CSE GitLab server. You can find it at this URL (substituting z5555555 for your own zID):

https://gitlab.cse.unsw.edu.au/z5555555/20T2-cs6771-tut01

You will need to log in with your zID and zPass. If you are unable to login please speak to your tutor or lab assistant.

If you're familiar with GitHub then you should find GitLab very similar. You'll observe that there is a copy of these instructions in the repository (`GIT.md`) as well as a few files and folders relating to this lab exercise.

Feel free to browse GitLab in order to familiarise yourself with it. If you're not familiar with git, the following sections should help get you started with learning it.

## 2. Adding Your SSH Key to GitLab

The following steps **must** be performed by running the commands on the CSE system. If you wish to work from your own computer, you must **also** do the same from there.

1. You need to add your CSE ssh key to your gitlab.cse.unsw.edu.au account. Here is how you do that:
First print your CSE ssh key. If you have one, this command should should work.

    ```
    $ cat ~/.ssh/id_rsa.pub
    ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAyNSzIDylSPAAGLzUXdw359UhO+tlN6wWprSBc9gu6t3IQ1rvHhPoD6wcRXnonY6ytb00GpS4XRFuhCghx2JNVkXFykJYt3XNr1xkPItMmXr/DRIYrtxTs5sn9el3hHZIgELY8jJZpgIo303kgnF0MsB7XpqCzg7Iv6JGkv7aEoYC/MNr07hXE8iQjYIHDMdO9HxGI80GyMqb1hF+RSpQTNvXQvH56juu9VXt5OwJjOqSVa4SfsEICqdn+3k9w8Z4EaD93Eeog3hz0RoTrme8h/sJenXydJ0w9ZOs0By4fjqKFYPsYEs1K6SHma+kPByZM9COgKHZwOZHH1m24HOITQ== z5555555@williams
   ```

2. If you couldn't print an ssh key with the above command, you need to generate a new ssh key. You can do it like this (just hit return for each question).

    ```
    $ ssh-keygen
    Generating public/private rsa key pair.
    Enter file in which to save the key (/import/kamen/3/z5555555/.ssh/id_rsa):
    Created directory '/import/kamen/3/z5555555/.ssh'.
    Enter passphrase (empty for no passphrase):
    Enter same passphrase again:
    Your identification has been saved in /import/kamen/3/z5555555/.ssh/id_rsa.
    Your public key has been saved in /import/kamen/3/z5555555/.ssh/id_rsa.pub.
    The key fingerprint is:
    b8:02:31:8b:bf:f5:56:fa:b0:1c:36:89:ad:e1:cb:ad z5555555@williams
    The key's randomart image is:
    ...
    ```

3. To add your key to GitLab go to https://gitlab.cse.unsw.edu.au/profile/keys/
4. If you're asked to log in again, do so.
5. Cut-and-paste your ssh-key (the entire 200+ character line printed by cat ~/.ssh/id_rsa.pub) into the "Key" field. Don't cut-and paste z5555555's ssh key above - cut-and-paste your ssh-key! The title field should be filled in automatically.
6. Click the green **Add Key** button

# Using git

This exercise is intended to help you familiarise yourself with git. If you've not used git before, it can take a while to get used to it and learn how it works. Make sure you understand exactly what you're doing in the following exercise. **DO NOT BLINDLY ENTER IN THE COMMANDS WITHOUT KNOWING WHAT THEY DO.**

## Cloning

Cloning a *repository* (a repository or repo is just a directory that is linked with git) copies to your computer all the files in the repo as well as a complete history of what changes, or *commits*, created those files. Cloning a repo is necessary before you can start making your own changes.

For each lab and assignment in this course, a repo will be created for you on *GitLab*. You will use it to store your work as you complete it. To clone this week's repo run (once again, replacing z5555555 with your own ZID):

```
$ git clone gitlab@gitlab.cse.unsw.EDU.AU:z5555555/20T2-cs6771-tut01.git
$ cd 20T2-cs6771-tut01 # To navigate into the directory
```

Configure git if you have not used it before. The following commands will do that.
    ```bash
    $ git config --global user.name "Your Name"
    $ git config --global user.email "email@example.com"
    $ git config --global push.default simple
    ```

## Making a commit

Now that you have cloned the repo, you are ready to work on the codebase locally.

A commit represents a set of changes to the files in a repository as well as a message describing those changes for human readers. A good use of git involves a lot of commits with detailed messages.

Before you can commit, you have to *stage* your changes, effectively telling git what changes you actually want to commit and what changes you don't.

Making commits doesn't actually replicate your changes to the remote repository on GitLab. For that you need to *push* your commits, uploading them to the remote server. When collaborating with others, it is important not only to commit frequently, but also to push often.

In general, the commands to commit and push are as follows:
```bash
$ git add [files_to_commit] # Stage
$ git commit -m"Detailed message describing the changes" # Commit
$ git push # Push
```

Follow these steps to see them in action:

1. Add a new file called `first.txt` in the repo directory
2. Add a line of text to the first.txt file using your favourite text editor and save.
3. Go back to your terminal and enter the following commands:

    ```bash
    git add first.txt
    git commit -m "Added a line to the first file"
    git push
    ```

4. **MAKE SURE YOU UNDERSTAND THE PURPOSE OF EACH OF THE 3 ABOVE COMMANDS!** If you are unsure about any of them, ask your tutor or lab assistant.
5. Go back to GitLab and confirm that your changes have been pushed to the server.