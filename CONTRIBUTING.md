# Contributing
1. Please create a branch for your changes.

2. Once you have committed the changes to your personal branch, head back to the GitHub website to create a pull request. You can also click [here](/alesan99/eecs348project/compare/) to be taken directly to compare branches. Ensure you have the base  set to dev, and the comparison target as your new branch. Hit the green **Create Pull Request** button to enter info about your pull request. Please include the overall objective of your new code, and any potential issues you have identified with it. Once you have written the description, hit the **Create Pull Request** button one final time to complete the process.

3. In a timely manner, we will go over the pull requests as a team and discuss the changes within each PR. Please do not create and merge your own pull request. 

# Helpful information on git
The following commands and info can be helpful when working with multiple branches.<br>
Check current **local** branches:
```
$ git branch
    dev
  * main
```
Switch to a different branch: 
```
$ git switch dev
  Switched to branch 'dev'
```
Create and switch to a new branch:
```
$ git switch -C my_new_branch
  Switched to a new branch 'my_new_branch'
```
*More info on [switch](https://git-scm.com/docs/git-switch) and [branch](https://git-scm.com/docs/git-branch)*

### Important
The new branches contents will initially be identical to the previous branch you had selected. If you currently have main selected, your new branch (my_new_branch) will be a 1:1 copy of main. For this project, please ensure you are creating new branches based off of the dev branch, and not main.
