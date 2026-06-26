1). repo-creation, version 	//done-2026.01.28
	//student-apna college
	1.1) 	$git --version 		//done-2026.01.28 - git version 2.49.0.windows.1
			$git -v 			//done-2026.01.28 - git version 2.49.0.windows.1
	1.2)	$git config --list  //done-2026.01.28 - shows all credentials and many more 
			$git config --global --unset code.editor		//to unset anything in git config - this is an example to unset default code.editor
						// --global - for all repo		- applicable in all git config commands
						// --local  - for current repo	- applicable in all git config commands
			$git config --global init.defaultBranch main	//to set default branch name as main(instead of master)
			// There are three levels of configuration:
				//System(all users): 	git config --system
				//Global(current user): git config --global
				//Local(current repo): 	git config --local
	1.3)	$mkdir git_v3	
			//create an empty directory in vs-code	
			//we r going to clone the repo from GitHub into this directory
			//now create HVAC_Test_v3 - a repo on git hub, just add/edit readme.md there
			$cd git_v3
			$git clone url			//it will clone the entire repo(HVAC_Test_v3) into git_v3 directory
			$git clone url myfolder	//to specify a specific folder to clone to, add the name of the folder after the repository URL
			$ls
			$cd HVAC_Test_v3
			$ls				//it'll show .git(hidden dir) & readme.md, so it is a git repo now. 
			$pwd			//done-2026.01.28
	1.4)	$git remote -v 	//A version of your repository hosted on the internet or network
							//it will display remote repo where current local-repo synced, if not synced, it won't display anything
							//for this example - it shows the synced repo(HVAC_Test_v3) with current git-local dir(git_v3)
	1.5) 	$git init		//first make dir & then init it for making it a git-local-repo, so now d directory will be git-dir
			$git remote add origin url	//it will sync the mentioned url-repo to current git-local-repo 
										//the default name for your main remote repo. 
										//you can rename or have multiple remotes if needed.
	1.6)	$git status --help	//opens the manual page for git status.
	//Info: 
		//we can simply go to git-hub -> setting -> repo and invite other team-mates for collabration
		//u - untracked file(in VSCode)
		//A - tracking enabled(in VSCode)
		//M - Modified file - need to add_n_commit(in VSCode)
		//as directory converted into git-local-repo(by $git init) - extentions will be added as .u/.A/.M etc.
		//then, as we use $git add fileName - .u converted into .A, now if we modify this file, then .A into .M

2). add, commit & tag 	//done-2026.01.28
	2.1)	$git add fileName	-(1)
			$git add *			-(1)	//all
			$git add --all		-(1)
			$git add -A			-(1)	//all
			$git add .			-(1) - 	//all - to add file in staging area
			$git rm fileName 	//to remove file from git working dir 	//done-2026.01.28
								//now that file does not exist on the branch where we have fired this command 
								//Be careful- this command delete the entire file, it will not even remain in Git Local also
			$git restore --staged fileName //to unstaged a fileName (if, Staged the wrong file) //done-2026.01.28
	2.2)	$git commit -m "commit message"
	2.3)	$git commit -a -m "commit message" //to add & commit altogether - but it works on all files - Be-careful
	2.4)	$git log 	//to get history of git all commits with commitId
			$git log --oneline
			$git show commitId //show the changes done in this commit
			->	Info: While viewing the log, you can search for a word(add after colon(:)) by typing /wordToBeFind
				(for example, /fix), then press n to jump to the next match.
				Use the arrow keys to scroll, and press q to quit
	2.5)	$git status 				//when we save in file, it indicates file is modified, we should/have to add & commit
	2.6)	$git diff 					//shows modifications
			$git diff commit_1 commit_2	//changes between any two specific commits
			$git diff --staged			//different between your staged files and the last commit	//done-2026.01.28
	2.7)	$git show 					//details and changes for a latest commit					//done-2026.01.28
			$git show commitId			//details and changes for a specific commitId				//done-2026.01.28
	2.8)	$git blame fileName			//shows the changes by each auther - with time-line 		//done-2026.01.28
	2.9)	advance:
			->	git log --author="Alice"			//See only the commits made by a specific author														//done-2026.01.28
			->	git log --since="2 weeks ago"		//See only commits made in the last two weeks			
				git log --since="10 minutes ago"	//See only commits made in the last two weeks															//done-2026.01.28 "1 hour ago"
			->	git log --stat						//summary of particular changes in each commits															//done-2026.01.28
			->	git log --graph						//a simple graph of your branch and merge history(great for visualizing merges)							//remaining-2026.01.28
			-> 	if you forgot to add a file in your last commit, it can be added to your last commit
				->	$git commit --amend --no-edit				//quickly add staged changes to last commit, keep message as it was						//done-2026.01.28
				->	$git commit --amend 						//to add it to your last commit, same as above, but it prompt to edit commit message	//done-2026.01.28
				->	$git commit --amend -m "Corrected message" 	//to fix the last commit message														//done-2026.01.28
			->	Accidentally committed the wrong files?
				->	$git reset --soft prevCommitId	//to undo the last commit and keep your changes staged												//done-2026.01.28
													//KIM: we have to select previous commitId here
	2.10)	advance: tag //done-2026.01.28
			->	A tag in Git is like a label or bookmark for a specific commit.
			->	Tags are most often used to mark important points in your project history, like releases(v1.0 or v2.0).
				use tags to mark releases, major milestones, or stable points in your project.
			->	always use annotated tags(with -a -m) for anything public or shared.
			->	by, $git log --oneline, we can get idea of tag associated with which particular commitId
			->	KIM:
				->	if we reset a branch to some previous commit, the tags will not be deleted, we have to delete all the existing tags explicitly
				->	even if we delete an entire branch, tags will not be deleted 
			$git tag v1.0 							//a simple light tag //just a name for a commit, quick and simple, but does not store extra information				//done-2026.01.28
			$git tag -a v1.0 -m "Ver 1.0 release"	//stores author, date, and message, recommended for releases and sharing with others								//done-2026.01.28
			$git tag v1.1 1a2b3c4d					//to tag older commit by specifying its hash, 																		//done-2026.01.28
													//we can not edit tag here, we have to use another non-used tag
			$git tag -f v1.0 <new-commit-hash>		//to edit a tag (to assign tag to some-other commitId)																//done-2026.01.28
			$git tag 								//see all tags in your repository																					//done-2026.01.28
			git tag -d v1.0							//delete a tag locally																								//done-2026.01.28
			$git show v1.0 							//details about a tag																								//done-2026.01.28
			//add & commit trial
			//this must be not included
			->	Push Tags to Remote					
				-> 	By default, tags exist only on your local computer
					If you want others to see your tags, you need to push them to remote.
					If you do not push your tags, only you will see them, and only locally.
				->	$git push origin v1.0				//push a single tag to your remote repository(for example, after creating a release tag)	//done-2026.01.28
					info: 	Pushing commits with git push does not push your tags!
							You must push tags explicitly as shown above.
				->	git push --tags 					//push all your local tags to the remote at once											//done-2026.01.28
				->	git push origin --delete tag v1.0	//delete a tag from the remote repository, but tag will exist on local-repo					//done-2026.01.28
				->	Update or Replace a Tag(on git-local)
					->	If you need to move a tag to a different commit, use --force:
						$git tag -f v1.0 <new-commit-hash>	//first, update the tag with some-other commitId											//done-2026.01.28
				->	Update or Replace a Tag(on git-remote(git-hub))
					->	first, delete the tag on remote by
						$git git push origin --delete tag v1.0
					->	second, update/replace the tag on git-local
						$git tag -f v1.0 <new-commit-hash>
					->	third, push this by tag	
					->	$git push origin v1.0
			->	Info: 
				->	Tag already exists? Use git tag -d <tagname> to delete it, then re-create.
				->	Pushed the wrong tag? Delete it locally and remotely, then push the correct tag.
				->	Tag not showing on remote? Remember to push tags with git push origin <tagname> or git push --tags.
				->	Need to overwrite a tag on the remote? 
					You can force-push a tag with git push --force origin <tagname>, 
					but be careful! This will overwrite the tag for everyone using the remote.
						
3). reset, revert & restore 		//done-2026.01.28
	3.1)	$git revert commitId	//added will be deleted and/or deleted will be added 										//done-2026.01.28
									//commit history will be remained, so we can go forward/reverse in particular commit		
									//if we need to delete commit history, then do it by $git reset --hard commitId
									//KIM: whichever commitId selected to revert, it will revert entirely for that commitId, so we have to sel commitId of prevCommitId
										//e.g. 
											//comments_0 added	//commitId_0_Hash
											//comments_1 added	//commitId_1_Hash
											//comments_2 added	//commitId_2_Hash
											//comments_3 added	//commitId_3_Hash
											//$git log --oneline	//to see commit logs
												//commitId_3_Hash
												//commitId_2_Hash
												//commitId_1_Hash
												//commitId_0_Hash
											//$git revert commitId_2_Hash	//it will delete upto comments_2 added, comments_1 added will be the last line 
	3.2)	$git reset --hard CommitId		//it will remove all the commits after CommitId												//done-2026.01.28
	3.3)	git restore fileName 			//Undo changes in your git-local-repo(just an UNDO) 										//done-2026.01.28
			$git restore --staged fileName 	//to unstaged a fileName(if, Staged the wrong file) 										//done-2026.01.28
	Info:	//Info: Base_Node -> Node -> Node -> .. -> Node(Head) - last node is called head											//done-2026.01.28			
			//Info: HEAD is a reference to the current commit your working directory is based on. Usually points to the latest commit on your current branch
			//head is pointing to last/latest commit
			//just imagine we've - commitId_1 -> commitId_2 -> commitId_3 -> commitId_4(head)

4). branch - 49:30 onwards in apnacollege-video	//done-2026.01.28
	Info:	In Git, a branch is like a separate workspace where you can make changes and try new ideas without affecting the main project. 
			Think of it as a "parallel universe" for your code.
			Common Reasons to Create a Branch
				->	Developing a new feature
				->	Fixing a bug
				->	Experimenting with ideas
			Merging points:
				->	Combine changes from different branches is merging 
				->	Regularly merge into the main branch from your feature branch to minimize conflicts.
				->	Read and resolve conflicts carefully—do not just accept all changes blindly.
				->	Write clear and descriptive merge commit messages.
				->	Always commit or stash your changes before starting a merge
				->	Write clear and descriptive merge commit messages
	4.1)	$git branch newBranch			//create a newBranch											//done-2026.01.28
			$git branch --sh				//show current branch 											//done-2026.01.28
			$git branch --list				//show all branches with current branch highlighted(green*)		//done-2026.01.28
			$git branch -a					//show all branches(along-with git-remote branches also) - best command of all flavours
			$git branch 					//shows current branch(greeen*) & other branches(of git-local)	//done-2026.01.28
			$git checkout newBranch			//checkout into newBranch										//done-2026.01.28
			$git switch newBranch			//to switch a branch											//done-2026.01.28
			$git checkout -b branchName 	//to create & checkout altogether								
			$git branch -m newBranchName	//to rename a current branch 									
			$git branch -m old-name new-name	//to rename a branch(from another branch is also possible)	
			//change_0_in_branch_dev_0
			//change_1_in_branch_dev_0
			//change_2_in_branch_dev_0
			//change_3_in_branch_dev_0
			//change_4_in_branch_dev_0
			//change_5_in_branch_dev_0
	4.2)	$git branch -d branchName		//to delete branchName branch 									//done-2026.01.28
											//to delete branch, first exit from that branch, 
											//go to parent branch, then only we can delete this branch
	4.3)	$git diff main/parentBranch		//to get diff between current branch & main/parentBranch branch //done-2026.01.28
	4.4) 	$git merge branch_1				//to merge from branch_1 into master(first checkout into master branch)	//done-2026.01.28
			//e.g., step_1: git checkout master		//First, we need to change to the master branch
					step_2: git merge emergency-fix //Now emergency-fix branch will be merged into master branch 
			//Info:	branch name - wip, feature, bug, junk etc. 
			//e.g. git branch feature/add-chat-support 	- example of brachName
			//e.g. git branch bug/login-not-works		- example of branchName
			->	flovour of merging 	//done-2026.01.28
				->	$git merge branchName			//if your branch can be merged with a fast-forward(no new commits on the base)
													//git just moves the branch pointer forward.
				->	$git merge --no-ff branch		//Non-fast-forward merge: preserving branch history & create a merge commit too 
				->	$git merge --squash branchName	//combine all the changes from a branch into a single commit(instead of keeping every commit)
													//KIM - not updating HEAD
				->	$git merge --abort				//if you run into trouble during a merge(like a conflict you do not want to resolve), 
													//you can cancel the merge and go back to how things were before
				->	$git config --local merge.ff false	//set non-fast-forward merging as the default behavior in a repository using a configuration option
	4.5)	$git push -u origin newBranch 	//when we create a new branch in our git-local, 				//done-2026.01.28
											//we can not use only git push to upload all the commits of that newly created branch, 
											//first we have to use/set upstraem(-set-upstream(-u)), so we can push on GitHub
											//now, refresh on git-hub to check newly created branch & its commits - it will be on GitHub 
			//info: when we commits in local-repo, it shows your local-repo is x commits ahead than GitHub, do use git push to push all your commits exist on git-local(i.e. to sync with GitHub)
	4.7)	$git push -f 	//-f = forcefully - if we used git reset --hard commitId previously, 			//done-2026.01.28
							//console will propmt message that your repo is few commits behind than remote, use git pull to sync with remote
							//but, we have purposly reset head to some previous commitId
							//so, here git-hub(remote) set at other head than that of our local-repo, so we have to use -f here
	4.8)	$git push -f -u origin newBranch	//if we have hard reset in our git-local, then we need to use this for -f & -u altogether	//done-2026.01.28
			//let say we have created a pull request on remote, merged the pull request in base/parent branch, so we have to pull these latest changes to our git-local,
			//for this we have to first checkout to base/parent branch, after that "$git pull" to get latest changes from the git-hub(remote) to our git-local 
			//whenever we use "$git pull" - it will pull the latest chanages from that particular branch, not from the main branch
			//to get all the latest changes from git-hub, first checkout to that branch, then do "$git pull", so our local-repo will be synced with remote
	4.8)	$git branch -D branchName	//to force delete an unmerged branch								//done-2026.01.28
			//When deleting a branch by just using -d, 
			//git do not allow to delete, it shows make sure it's merged first. 
			//If you try to delete an unmerged branch, Git will prevent you from doing
			//so, here we have to use -D to delete the unmerged branchName 
	4.10)	$git pull 	//Fetch and merge changes from a remote

(5). stashing - Temporarily save changes that aren't ready to commit	//done-2026.01.28
	5.1)	->	Sometimes you need to quickly switch tasks or fix a bug, but you're not ready to commit your work
				git stash lets you save your uncommitted changes and return to a clean working directory
				you can come back and restore your changes later.
			->	Switch branches safely: Save your work before changing branches.
			->	Handle emergencies: Stash your work to fix something urgent, then restore it.
			->	Keep your work-in-progress safe: Avoid messy commits or losing changes.
			->	$git stash 	//Save your current changes(both staged and unstaged tracked files)
							//Tracked files(both staged and unstaged) are stashed by default.
				KIM: 	Untracked files(new files not yet added to Git) are not stashed by default.
						To stash untracked files too, use git stash -u(or --include-untracked).
				Info:	This command saves your changes and cleans your working directory so you can safely switch tasks or branches.
						Your working directory is clean, and you can switch branches or pull updates safely
			->	stash stack - 
				Each time you run git stash, your changes are saved on top of a "stack".
				The most recent stash is on top, and you can apply or drop stashes from the top down, or pick a specific one from the list
			->	$git stash push -m "WIP: homepage redesign" //Add a message to remember what you stashed							//done-2026.01.28
			->	$git stash list //shows all the stashes you have saved so far, with their names and messages.						//done-2026.01.28
				response: 	stash@{0}: xxx	- most recent stash 
							stash@{1}: xxx  - second stash
							stash@{2}: xxx 	- first stash
			->	$git stash show		//gives a summary of what files and changes are in your most recent stash						//?
			->	$git stash apply	//Restore your most recent stashed changes(keeps the stash in the stack)						//done-2026.01.28
			->	$git stash apply stash@{n}	//lets you restore a specific stash from your list, not just the most recent one		//done-2026.01.28
			->	$git stash pop		//Apply the latest stash and remove it from the stack- it will remove most recent one only		//done-2026.01.28
			->	$git stash drop		//delete a specific stash when you no longer need it											//done-2026.01.28
			->	$git stash clear	//deletes all your stashes at once. Be careful! This cannot be undone!							//done-2026.01.28
			->	$git stash branch newBranch stashHash	//this command creates a new branch and applies your stashed changes to it.	//done-2026.01.28
					//first stash changes, so we will get stashHash
					//this command creates a new branch and applies your stashed changes to it
					//so now we are automatically switch to newBranch, we have to commit changes here in newBranch
					//if we switch to our previous/parent branch, changes will not be there
					//useful if your stashed work should become its own feature branch
					//useful if you decide your work should become its own feature branch.
			->	notes:
				->	Use clear messages when stashing: git stash push -m "WIP: feature name"
				->	Don't use stashes as long-term storage — commit your work when possible.
				->	Check your stash list regularly and clean up old stashes you no longer need.
				->	Did you lose your changes? Try git stash list and git stash apply to recover stashed work.
				->	Stash did not apply cleanly? You may need to resolve conflicts, just like a merge.
					Git will mark the conflicts in your files for you to resolve.
				->	Untracked files missing? By default, untracked files are not stashed.
					If you need to stash them, use git stash -u next time.
				->	Accidentally cleared all stashes? Unfortunately, git stash clear is permanent.
					Always double-check before running it!
		
6).	undefined
//git marketplace for enclipse-plugin
//git-hub co-pilot
//git merge squash
//git lense
//git sub-module add url path

7).	Git Workflow
	->	Working Directory - Where you make changes
	->	git add - Stage changes
	->	git commit - Save changes to your repository
	->	git push - Share changes with others
	->	git status - Check what is going on
	->	Undo/Amend - Fix mistakes (git restore, git reset, git commit --amend)
	->	The Three Areas of Git
		-> 	Working Directory: Where you make changes to your files.
		->	Staging Area(Index): Where you prepare changes before committing.
		->	Repository: Where your committed history is stored.
		->	[Working Directory] --git add--> [Staging Area] --git commit--> [Repository]
	->	Undoing and Amending Changes
		Made a mistake? Git lets you fix things before you push!
		->	git restore <file> - Undo changes in your working directory (before staging) - just an UNDO for working_dir 
		->	git restore --staged <file> - Unstage a file (move it out of the Staging Area) 								
		->	git reset HEAD~ - Undo your last commit (keeps changes in your working directory)
		->	git commit --amend - Change the last commit message or add files to your last commit
	->	Summary of Git Best Practices
			->	Commit Often 
					- Make small, frequent commits to capture your progress, also this makes it easier to track changes and find bugs.
			->	Write Clear Commit Messages 
					- Use descriptive messages that explain why a change was made, not just what changed
					- Use the imperative mood: For example, "Add login validation" instead of "Added login validation"
			->	Use Branches 
					- Create branches for features, fixes, and experiments to keep your main branch stable
			->	Pull Before You Push 
					- Always git pull before pushing, this updates your local branch with changes from others. 
					- Why? If someone else has pushed changes since your last pull, your push may be rejected or cause conflicts, also Pulling first lets you fix any issues locally
			->	Review Changes Before Committing 
					- Use git status and git diff to review your changes before you commit
			->	Keep Repositories Small 
					- For large files(like videos or datasets), use Git LFS(Large File Storage) instead of adding them directly to your repo.
			->	Use .gitignore 
					- Exclude files that should not be tracked (like build artifacts, log files, or secrets) by adding them to a .gitignore file
			->	Tag Releases
					- Use tags to mark release points(like v1.0) so you can easily find and reference important versions
					- This helps you keep track of your project's history and make it easier to roll back to previous versions if needed

//remaining
//$git fetch origin - Download changes from a remote repository without merging
//$git fork - A personal copy of someone else's repository, usually on a platform like GitHub

//remaining
$git rebase newBranch 	//it will append all the changes to main commits, observe head & do git log --oneline - try
						//Move or combine a sequence of commits to a new base commit

(8). GitHub - A remote repository is a version of your project hosted on the internet. GitHub is a popular platform for hosting remote repositories, enabling you to collaborate with others and back up your code.
	8.1)	SSH:
			->	SSH (Secure Shell) is a way to connect securely to remote computers and services, like Git repositories.
				SSH uses a pair of keys (public and private) to make sure only you can access your code.
				SSH keys come in pairs: a public key (like a lock) and a private key (like your own key).
				You share the public key with the server (like GitHub or Bitbucket), but keep the private key safe on your computer.
				Only someone with the private key can access what is locked by the public key.
			->	SSH key pair - A public and private key for secure access
				Commands: 
					ssh-keygen - Generate a new SSH key pair
					ssh-add - Add your private key to the SSH agent
					ssh -T git@github.com - Test SSH connection
					ssh-add -l - List loaded SSH keys
					ssh-add -d - Remove a key from agent
			->	First-Time SSH Key Setup:
					8.1.1). Enable SSH Agent
					8.1.2). Generate an SSH Key Pair
					8.1.3).	Add Your Key to the SSH Agent & GitHub Account
					8.1.4).	Test Your SSH Connection
					8.1.5).	Get Your Repository's SSH Address
					8.1.6).	Add or Update the Remote Origin
			->	You have generated your public SSH key, you need to add your public key to your GitHub account.
				you have generated your private SSH key, you need to add your private key to your SSH agent.
				To use SSH with Git hosting services, you need to copy your public key and add it to your account settings on GitHub, GitLab, or Bitbucket.
				
			->	Troubleshooting SSH & Tips:
				->	If you get "Permission denied", make sure your public key is added to your Git host and your private key is loaded in the agent.
				->	If your private key is ever exposed, generate a new key pair and update your Git host immediately.
	8.2)	Edit Code in GitHub:
			->	GitHub lets you edit files directly in your browser.
				This is useful for making quick changes without needing to use Git on your computer.			
			-> 	After editing, scroll down to the Commit changes section.
				Add a short, clear description of what you changed in the Commit message box.
				This helps others understand your update.
			->	By default, you can commit directly to the main (or master) branch.
				For bigger changes, it is best to create a new branch.
				When you choose to create a new branch, GitHub will automatically suggest a branch name.
				After committing, you can open a pull request to propose your changes.
				That is how you edit code directly in GitHub!
	8.3)	Pull from Remote
			->	In the past, we made an account on GitHub and set up SSH.
				Then we made some changes directly on GitHub.
				Now we want to update our local repository with the changes from GitHub.
			->	When working as a team on a project, it is important that everyone stays up to date.
				Any time you start working on a project, you should get the most recent changes to your local copy.
				With Git, you can do that with pull.
			->	pull is a combination of 2 different commands:
					->	fetch &
					->	merge
			->	Let's take a closer look into how fetch, merge, and pull works.
			->	git fetch downloads new data from a remote repository, but does not change your working files or branches. It lets you see what others have pushed before you merge or pull.
				Now that we have the recent changes, we can check our status: $git status
				We are behind the origin/master by 1 commit. That should be the updated README.md, but lets double check by viewing the log: $git log origin/master
				That looks as expected, but we can also verify by showing the differences between our local master and origin/master: $git diff origin/master
				That looks precisely as expected! Now we can safely merge.
			->	Git Pull: But what if you just want to update your local repository, without going through all those steps?	pull is a combination of fetch and merge.
				It is used to pull all changes from a remote repository into the branch you are working on.
	8.4)	Git Push to GitHub
			->	When we have made changes locally, we want to update our remote repository with the changes.
				Transferring our local changes to our remote is done with a push command.
			->	There are several commands we can use to push changes to GitHub.
				Basic Push
				Force Push
				Push Tags
			->	Basic Push: This command pushes your current branch to the remote repository named origin
			->	Basic Push: This command pushes your current branch to the remote repository named origin
				Warning: This can overwrite changes on the remote repository. Use with caution!
				e.g., git push --force origin feature-branch
			->	Push Tags: To push all local tags to GitHub. 
				i.e., 
				$git push --tags		//To push all local tags to GitHub
				git push origin v1.0	//to push specific tag
			->	Troubleshooting
				->	Non-fast-forward error: Happens if someone else pushed to the branch. Run git pull --rebase before pushing again.
				->	Authentication failed: Make sure you have access to the repository and your credentials are correct.
	8.5)	Git GitHub Branch
			->	On GitHub, access your repository and click the "master" branch button.
				There you can create a new Branch. Type in a descriptive name, and click Create branch
			->	To delete a branch on GitHub, go to the branches page, find your branch, and click the delete icon (trash can).
				$git branch -d branch-name				//To delete a branch using the command line - local
				$git push origin --delete branch-name	//To delete a remote branch
				$git branch -m old-name new-name		//To rename a branch using the command line
			->	Merge Branch
				->	To merge a branch into another on GitHub, open a Pull Request (PR) and follow the prompts to merge.
				->	$git merge branch-name				//To merge using the command line
			->	Protected Branches
				Some branches (like main) may be protected, meaning you cannot delete or force-push to them without special permissions.
				This helps prevent accidental changes to important branches.
	8.6)	Git Pull Branch from GitHub
			->	imagine:
				Confirm which branches we have, and where we are working at the moment
				$git branch
					* master
				So, we do not have the new branch on our local Git. But we know it is available on GitHub. So we can use the -a option to see all local and remote branches:
				$git branch -a	//for all branch
					* master
					remotes/origin/html-skeleton
					remotes/origin/master
				($git branch -r 	//for remote branches only
					remotes/origin/html-skeleton
					remotes/origin/master)
				We see that the branch html-skeleton is available remotely, but not on our local git. Lets check it out:
				$git checkout html-skeleton
					Switched to a new branch 'html-skeleton'
					Branch 'html-skeleton' set up to track remote branch 'html-skeleton' from 'origin'.
				And check if it is all up to date
					$git pull
						Already up to date.
				Which branches do we have now, and where are we working from?
					$git branch
						* html-skeleton
						master
				Now, open your favourite editor and confirm that the changes from the GitHub branch carried over.
				That is how you pull a GitHub branch to your local Git.
	8.7)	Git Push Branch to GitHub
			->	$git checkout -b update-readme
					Switched to a new branch 'update-readme'
				Now, Edit a file, then check the status, then add, commit
				Push your branch to GitHub
					$git push origin update-readme
					$git push --set-upstream origin update-readme	//Use this if your branch doesn't exist on GitHub yet, and you want to track it
					$git push --force origin update-readme			//force push, Warning: This overwrites the branch on GitHub with your local changes. Only use if you understand the risks.
					$git push origin --delete update-readme			//Remove a branch from GitHub(Remove a branch from GitHub)
					$git push --all origin							//Push all your local branches to GitHub
					$git push --tags								//Push all your tags to GitHub
			->	Troubleshooting:
					Rejected push (non-fast-forward): Someone else pushed changes before you. Run git pull --rebase first, then try again.
					Authentication failed: Make sure you are logged in and have permission to push to the repository.
					Remote branch not found: Double-check the branch name and spelling.
	8.8)	Git GitHub Flow
			->	The GitHub Flow is a simple, effective workflow for collaborating on code using Git and GitHub.
				It helps teams work together smoothly, experiment safely, and deliver new features or fixes quickly.
			->	Here's how the GitHub Flow works, step by step:
					Create a Branch: Start new work without affecting the main code.
					Make Commits: Save progress as you make changes.
					Open a Pull Request: Ask others to review your work.
					Review: Discuss and improve the changes together.
					Deploy: Test your changes before merging.
					Merge: Add your finished work to the main branch.
					This workflow is designed to be easy for beginners and powerful for teams of any size.
			-> 	Create a New Branch
					Branching is the key concept in Git. And it works around the rule that the master branch is ALWAYS deployable.
					That means, if you want to try something new or experiment, you create a new branch!
					Branching gives you an environment where you can make changes without affecting the main branch.
					When your new branch is ready, it can be reviewed, discussed, and merged with the main branch when ready.
					When you make a new branch, you will(almost always) want to make it from the master branch.						
					Note: Keep in mind that you are working with others.
						Using descriptive names for new branches, so everyone can understand what is happening.
			->	Make Changes and Add Commits
					After the new branch is created, it is time to get to work.
					Make changes by adding, editing and deleting files.
					Whenever you reach a small milestone, add the changes to your branch by commit.
					Adding commits keeps track of your work.
					Each commit should have a message explaining what has changed and why.
					Each commit becomes a part of the history of the branch, and a point you can revert back to if you need to.
					Note: commit messages are very important! Let everyone know what has changed and why.
						Messages and comments make it so much easier for yourself and other people to keep track of changes.
			->	Open a Pull Request
					Pull requests are a key part of GitHub.
					A Pull Request notifies people you have changes ready for them to consider or review.
					You can ask others to review your changes or pull your contribution and merge it into their branch.
			->	Review
					When a Pull Request is made, it can be reviewed by whoever has the proper access to the branch.
					This is where good discussions and review of the changes happen.
					Pull Requests are designed to allow people to work together easily and produce better results together!
					If you receive feedback and continue to improve your changes, you can push your changes with new commits, making further reviews possible.
					Note: GitHub shows new commit and feedback in the "unified Pull Request view".
			->	Deploy
					When the pull request has been reviewed and everything looks good, it is time for the final testing.
					GitHub allows you to deploy from a branch for final testing in production before merging with the master branch.
					If any issues arise, you can undo the changes by deploying the master branch into production again!
					Note: Teams often have dedicated testing environments used for deploying branches.
			->	Merge
					After exhaustive testing, you can merge the code into the master branch!
					Pull Requests keep records of changes to your code, and if you commented and named changes well, you can go back and understand why changes and decisions were made.
					Note: You can add keywords to your pull request for easier searching!
	8.9)	Git GUI Clients
			->	must Try
			->	Why use a GUI client?
				Git GUI clients let you use Git with buttons and menus instead of typing commands.
				They are great for beginners, make it easier to see what's happening, and help you avoid common mistakes.
					See your branches and changes visually
					Stage, commit, and push with clicks
					Handle merge conflicts with helpful tools
					No need to remember command-line options
			->	Popular Git GUI Clients
					GitHub Desktop
					GitKraken
					Sourcetree
					Git GUI
					VS Code Git
					Other Clients
					GitHub Desktop
			->	GitHub Desktop is a free, beginner-friendly app for Windows and Mac.
				It works best with GitHub, but you can use it with other repositories too.
				Pros: Simple, clean interface. Great for GitHub users.
				Cons: Fewer advanced features. Not as flexible for non-GitHub platforms.
				Example workflow
					1. Clone a repository from GitHub
					2. Make changes to files
					3. See changes in the app
					4. Stage and commit with a message
					5. Push to GitHub with one click
					GitKraken
			->	GitKraken is a powerful, cross-platform Git client with a modern interface.
				It supports GitHub, GitLab, Bitbucket, and more.
				Pros: Visual commit graph, built-in merge/conflict tools, works with many platforms.
				Cons: Some features require a paid license.
				Example workflow
					1. Open a repository
					2. Drag and drop to create branches
					3. View history and merge visually
					4. Resolve conflicts with built-in tools
					5. Push changes to remote
			-> 	Sourcetree
				Sourcetree is a free Git client from Atlassian, popular for Bitbucket but works with any Git repository.
				Pros: Free, full-featured, good for advanced users.
				Cons: Interface can be overwhelming for beginners.
				Example workflow
					1. Add a repository
					2. Stage and commit changes
					3. Use the log/history view to see all commits
					4. Push and pull with buttons
			->	Git GUI
				Git GUI is a basic graphical tool that comes with Git for Windows.
				It's simple, but covers the basics.
				Pros: Always available, lightweight, no extra install needed.
				Cons: Basic interface, fewer features than other clients.
				Example workflow
					1. Open Git GUI from the Start menu
					2. Select your repository folder
					3. Stage files, write a commit message, and commit
					4. Push to remote using the menu
			->	VS Code Git
				Visual Studio Code has built-in Git support.
				You can use the Source Control panel to stage, commit, push, pull, and resolve conflicts-all inside your code editor.
				Pros: Integrated with your editor, easy to use, works with extensions.
				Cons: Not as visual for history/branches as dedicated apps.
				Example workflow
					1. Open a folder in VS Code
					2. Make changes to files
					3. Use the Source Control panel to stage and commit
					4. Push and pull with buttons
			->	Other Clients
				There are many other Git GUI clients, including:
					Fork
					Tower
					SmartGit
					Aurora
					Git-Cola
				Most work in similar ways: you open a repo, see your changes, and use buttons for Git actions.

			->	Troubleshooting
					Authentication issues: Make sure you've set up SSH keys or personal access tokens if needed.
					Changes not showing: Refresh or re-scan your repo in the client.
					Conflicts: Use the merge/conflict tools built into your client, or fall back to the command line if stuck.

(9). Git Contribute - 
	9.1)	GitHub Fork - Add to Someone Else's Repository
			->	At the heart of Git is collaboration.
				However, Git does not allow you to add code to someone else's repository without access rights.
				In these next 3 chapters we will show you how to copy a repository, make changes to it, and suggest those changes be implemented to the original repository.
				At the end of these chapters, you will have the opportunity to add a message to our public GitHub page: https://w3schools-test.github.io/
			->	Fork a Repository - A fork is a copy of a repository.
				This is useful when you want to contribute to someone else's project or start your own project based on theirs.
				fork is not a command in Git, but something offered in GitHub and other repository hosts.
				Let's start by logging in to GitHub, and fork our repository:
				https://github.com/w3schools-test/w3schools-test.github.io
				Fork is done by clicking in GitHub repo, so entire repo will be copied into our GitHub.
	9.2)	Git Clone from GitHub
			->	Clone a Fork from GitHub
				Now we have our own fork, but only on GitHub. 
				We also want a clone on our local Git to keep working on it.
				A clone is a full copy of a repository, including all logging and versions of files.
				Move back to the original repository, and click the green "Code" button to get the URL to clone
			->	Open your Git bash and clone the repository
				$git clone https://github.com/w3schools-test/w3schools-test.github.io.git
				Note: To specify a specific folder to clone to, add the name of the folder after the repository URL, like this: 
				$git clone https://github.com/w3schools-test/w3schools-test.github.io.git myfolder
			->	Now we have a full copy of the original repository.
			->	Configuring Remotes	
				Basically, we have a full copy of a repository, whose origin we are not allowed to make changes to.
				Let's see how the remotes of this Git is set up
			->	$git remote -v
					origin  https://github.com/w3schools-test/w3schools-test.github.io.git (fetch)
					origin  https://github.com/w3schools-test/w3schools-test.github.io.git (push)
			->	We see that origin is set up to the original "w3schools-test" repository, we also want to add our own fork.
				First, we rename the original origin remote
			->	$git remote rename origin upstream
				$git remote -v
					upstream        https://github.com/w3schools-test/w3schools-test.github.io.git (fetch)
					upstream        https://github.com/w3schools-test/w3schools-test.github.io.git (push)
			->	Then fetch the URL of our own fork - get our url from GUI(copy url)
				And add that as origin
				$git remote add origin https://github.com/kaijim/w3schools-test.github.io.git
				$git remote -v
					origin  https://github.com/kaijim/w3schools-test.github.io.git (fetch)
					origin  https://github.com/kaijim/w3schools-test.github.io.git (push)
					upstream        https://github.com/w3schools-test/w3schools-test.github.io.git (fetch)
					upstream        https://github.com/w3schools-test/w3schools-test.github.io.git (push)
				Note: According to Git naming conventions, it is recommended to name your own repository origin, and the one you forked for upstream
			->	Now we have 2 remotes:
					origin - our own fork, where we have read and write access
					upstream - the original, where we have read-only access
				Now we are going to make some changes to the code. 
				In the next chapter, we will cover how we suggest those changes to the original repository.
	9.3)	GitHub Send Pull Request - Push Changes to Our GitHub Fork
			->	We have made a lot of changes to our local Git.
				Now we push them to our GitHub fork:
				commit the changes
			->	$git push origin
				Go to GitHub, and we see that the repository has a new commit. And we can send a Pull Request to the original repository.
			->	Click that and create a pull request
				Remember to add an explanation for the administrators.
			->	Approving Pull Requests
				Now any member with access can see the Pull Request when they see the original repository and they can see the proposed changes
			->	Comment on the changes(like; This looks good! Changes approved!) and merge - Merge pull request
			->	Confirm merge - And changes have been merged with master. 
 
(10). Git Undo - 
	10.1)	Git Revert 
			->	What Does Git Revert Do?
				The git revert command undoes a previous commit by creating a new commit that reverses the changes.
				This keeps your commit history intact and is the safest way to undo changes in a shared repository.
			->	Summary of Git Revert Commands and Options
					git revert HEAD - Revert the latest commit
					git revert <commit> - Revert a specific commit
					git revert HEAD~2 - Revert a commit further back in history
					git revert --no-edit - Skip commit message editor
					git log --oneline - Show commit history
			->	How to Find the Commit to Revert
				First, you need to find the commit you want to undo.
				$git log --oneline	//Use git log --oneline to see a summary of your commit history
			->	Run Git Revert
				Once you've found the commit you want to undo, use git revert to create a new commit that reverses the changes
				$git revert HEAD --no-edit //to create a new commit that reverses the changes - just try to get idea
			->	Review Changes After Git Revert
				After running git revert, review the changes to make sure everything is as expected:
				$git log --oneline
			->	Tips & Best Practices
				Here are some tips and best practices to keep in mind when using Git Revert:
				Use git revert instead of git reset when you want to undo a previous commit, but still keep the commit history intact.
				Use git log --oneline to find the commit you want to undo.
				Use git revert HEAD --no-edit to create a new commit that reverses the changes.
			->	Troubleshooting
				Here are some common issues you may encounter when using Git Revert:
				If you get an error message saying "error: could not revert...", try using git revert --abort to abort the revert process.
				If you get an error message saying "error: could not apply...", try using git revert --continue to continue the revert process.
	10.2)	Git Reset 
			->	What Does Git Revert Do?
				The git reset command moves your current branch (HEAD) to a different commit.
				Depending on the option, it can also change which changes are staged or even delete changes from your working directory.
				Use it to undo commits, unstage files, or clean up your history.
			->	Summary of Git Reset Commands and Options
					git reset --soft <commit> - Move HEAD to commit, keep changes staged
					git reset --mixed <commit> - Move HEAD to commit, unstage changes (default)
					git reset --hard <commit> - Move HEAD to commit, discard all changes
					git reset <file> - Unstage a file
					git log --oneline - Show commit history
			->	How to Find the Commit to Reset To
				First, you need to find the commit you want to go back to
				Use git log --oneline to see a summary of your commit history:
				So let's find the point we want to reset to
			->	Git Reset --soft
				git reset --soft <commit> moves HEAD to the specified commit, but keeps all your changes staged (in the index).
				This is useful if you want to combine several commits into one, or just want to rewrite history but keep your work ready to commit.
				e.g. 
					$git reset --soft 9a9add8
					All changes after 9a9add8 are now staged, ready for a new commit.
			->	Git Reset --mixed (default)
				git reset --mixed <commit> (or just git reset <commit>) moves HEAD to the specified commit and unstages any changes, but keeps them in your working directory.
				This is the default option and is useful if you want to "undo" a commit but keep your changes for editing or recommitting.
				e.g.
					$git reset --mixed 9a9add8
					All changes after 9a9add8 are now unstaged, but still in your files.
			->	Review Changes
				After running Git Reset, review your changes to make sure everything is as expected.
			->	Tips & Best Practices
				Use Git Reset with caution, as it can rewrite your commit history.
				Make sure to communicate with your team before making changes to the remote repository.
				Make sure to use it only when necessary.
			->	Troubleshooting
				If you encounter issues with Git Reset, try using git status to see the current state of your repository.
	10.3)	Git Amend 
			->	What is Git Amend?
				Git Amend is a command that allows you to modify the most recent commit.
				You can use it to fix typos, add or remove files, or change the commit message.
			->	When to Use Git Amend
				Use Git Amend when you need to make small changes to your last commit.
				It's perfect for fixing mistakes, adding forgotten files, or updating the commit message.
			->	Fix Last Commit Message
				To change the last commit message, follow these steps:
				Open your terminal and navigate to your repository.
				Type git commit --amend -m "New message" to change the commit message.
				$git commit --amend -m "Corrected commit message"
				Press Enter to save the changes.
			->	Add Files to Last Commit
				To add files to the last commit, follow these steps:
					Open your terminal and navigate to your repository.
					Type git add <file> to add the file to the staging area.
					Type git commit --amend to add the file to the last commit.
					Press Enter to save the changes.	
					e.g.
						#git add forgotten.txt
						$git commit --amend
			->	Remove Files from Last Commit
				To remove files from the last commit, follow these steps:
					Open your terminal and navigate to your repository.
					Type git reset HEAD^ -- <file> to remove the file from the staging area.
					Type git commit --amend to remove the file from the last commit.
					Press Enter to save the changes.
					e.g.
						$git reset HEAD^ -- unwanted.txt
						$git commit --amend
							1 file changed, 3 insertions(+), 1 deletion(-)
			->	Now let's check the log
				$git log --oneline
				Oh no! the commit message is full of spelling errors.
				Embarrassing. Let's amend that:
				$git commit --amend -m "Added lines to README.md"
			->	And re-check the log:
				$git log --oneline
				We see the previous commit is replaced with our amended one!
			->	Warning: Messing with the commit history of a repository can be dangerous.
				It is usually ok to make these kinds of changes to your own local repository.
				However, you should avoid making changes that rewrite history to remote repositories, especially if others are working with them.
			->	Git Amend Files
				Adding files with --amend works the same way as above.
				Just add them to the staging environment before committing.
	10.4)	Git Rebase
			->	What is Git Rebase?
				Rebasing moves or combines a sequence of commits to a new base commit.
				It is often used to keep a clean, linear project history.
				Rebasing can make your commit history easier to read by avoiding unnecessary merge commits.
			->	When to Use Git Rebase
				Use Git Rebase to:
					Keep a clean, linear project history
					Avoid unnecessary merge commits
					Combine multiple commits into one
					Edit or reorder commits
			->	Basic Rebase
				To move your current branch on top of another branch (e.g., update your feature branch with latest main)
				$git checkout feature-branch
				$git rebase main
					This re-applies your feature branch changes on top of the latest main branch.
			->	Interactive Rebase
				git rebase -i <base> lets you edit, reorder, squash, or fix up commits before a certain point.
				This is useful for cleaning up your commit history before sharing it with others.
				Example: Start Interactive Rebase
				git rebase -i HEAD~3		//c?
				This opens an editor where you can:
					pick: keep the commit as is
					squash: combine commits together
					edit: pause to change a commit
					reword: change just the commit message
				Follow these steps:
					Edit the commit message or choose an action (pick, squash, edit, reword)
					Save and close the editor
					Git will apply the changes and let you review the results
			->	Continue, Abort, or Skip
				If you hit a conflict or need to finish editing a commit, use git rebase --continue after resolving the issue.
				This tells Git to keep going with the rebase process.
				e.g. 
					$git add fixed_file.txt
					$git rebase --continue
				If something goes wrong or you want to stop the rebase, use git rebase --abort.
				This will put your branch back to how it was before you started rebasing.
				e.g.
					$git rebase --abort
				If you can not fix a commit during a rebase (for example, if a conflict can not be resolved), you can skip it with git rebase --skip.
				Git will leave out that commit and move on to the next one.
				e.g.
					$git rebase --skip
			->	Review Changes
				After completing the rebase, review your changes to ensure everything is correct.
			->	Tips & Best Practices
				Rebasing rewrites commit history.
				Avoid rebasing commits that you have already pushed to a shared repository.
				Use git rebase -i to edit, reorder, squash, or fix up commits before a certain point.
				Use git rebase --continue to continue a rebase after resolving conflicts.
				Use git rebase --abort to cancel a rebase in progress.
			->	Troubleshooting
				If you encounter conflicts during a rebase, resolve them and then use git rebase --continue to continue the rebase process.
				If you can't fix a commit during a rebase, use git rebase --skip to skip it.
	10.5)	Git Reflog
			->	What is Git Reflog?
				git reflog records updates to the tip of branches and HEAD.
				It lets you see where your branch and HEAD have been, even changes you made by mistake.
				This is useful for recovering lost commits or undoing a reset.
			->	When to Use Git Reflog
				Use git reflog when you need to:
					Recover lost commits or changes
					Undo a reset or a merge
					See the history of your branch and HEAD
			->	Show the Reflog
				To see the history of where HEAD and branches have pointed, use:
				$git reflog	//below response if just for ref
					e56ba1f (HEAD -> master) HEAD@{0}: commit: Revert "Just a regular update, definitely no accidents here..."
					52418f7 HEAD@{1}: commit: Just a regular update, definitely no accidents here...
					9a9add8 (origin/master) HEAD@{2}: commit: Added .gitignore
					81912ba HEAD@{3}: commit: Corrected spelling error
					3fdaa5b HEAD@{4}: merge: Merge pull request #1 from w3schools-test/update-readme
					836e5bf HEAD@{5}: commit: Updated readme for GitHub Branches
				This lists recent positions of HEAD, so you can see actions like commits, resets, merges, and checkouts.
			->	Find and Recover Lost Commits
				If you accidentally reset or deleted commits, you can use the reflog to find the commit and restore it.
				Each entry in the reflog has a reference like HEAD@{2}.
				$git reflog
					e56ba1f (HEAD -> master) HEAD@{0}: commit: Revert "Just a regular update, definitely no accidents here..."
					52418f7 HEAD@{1}: commit: Just a regular update, definitely no accidents here...
					9a9add8 (origin/master) HEAD@{2}: commit: Added .gitignore
					81912ba HEAD@{3}: commit: Corrected spelling error
					...
				$git reset --hard HEAD@{2}
					HEAD is now at 9a9add8 Added .gitignore
				This puts your branch back to the state it was in at that point.
			->	Clean Up the Reflog
				The reflog is automatically cleaned by Git, but you can manually expire old entries if needed:
				$git reflog expire --expire=30.days refs/heads/main
				This removes reflog entries older than 30 days for the main branch and runs garbage collection.
			->	Tips & Best Practices
					Use git reflog regularly to keep track of your changes
					Use git reflog to recover lost commits or changes
					Use git reflog expire to clean up old entries
			->	Troubleshooting
				If you encounter issues with git reflog, try:
					Checking the Git documentation for more information
					Searching online for solutions to specific issues
					Seeking help from a Git expert or community
			->	Warnings
					Be careful when using git reflog to recover lost commits or changes, as it can overwrite existing changes.
	10.6)	Git Recovery
			->	What is Git Recovery?
				Git recovery means getting back lost commits, branches, or files.
				Git keeps a record of recent changes so you can undo mistakes-even after a reset or delete.
			->	When to Use Git Recovery
				Use Git recovery when you:
					Accidentally delete a branch or file
					Reset your branch to a previous commit and lose changes
					Need to recover lost commits or changes
					Recover Lost Commits with git reflog
			->	git reflog records changes to the tip of branches and lets you find lost commits.
				$git reflog	//c below response is just for ref
					e56ba1f (HEAD -> master) HEAD@{0}: commit: Revert "Just a regular update, definitely no accidents here..."
					52418f7 HEAD@{1}: commit: Just a regular update, definitely no accidents here...
					9a9add8 (origin/master) HEAD@{2}: commit: Added .gitignore
					81912ba HEAD@{3}: commit: Corrected spelling error
					3fdaa5b HEAD@{4}: merge: Merge pull request #1 from w3schools-test/update-readme
					836e5bf HEAD@{5}: commit: Updated readme for GitHub Branches
				Find the commit hash you want to recover from the list.
			->	Restore a Deleted Branch
				If you deleted a branch but the commits are still in reflog, you can recreate it:
				$git checkout -b branch-name <commit-hash>
					Switched to a new branch 'branch-name'
				This brings back the branch at the commit you specify.
			->	Recover a Deleted or Changed File
				If you deleted or changed a file and want to get it back, use git restore:
				Example: Restore a File
				$git restore filename.txt
				This brings back the file from the latest commit.
			->	Recover from a Hard Reset
				If you used git reset --hard and lost commits, you can use the reflog to find and restore them:	
				$git reflog
					e56ba1f (HEAD -> master) HEAD@{0}: commit: Revert "Just a regular update, definitely no accidents here..."
					52418f7 HEAD@{1}: commit: Just a regular update, definitely no accidents here...
					9a9add8 (origin/master) HEAD@{2}: commit: Added .gitignore
					81912ba HEAD@{3}: commit: Corrected spelling error
					3fdaa5b HEAD@{4}: merge: Merge pull request #1 from w3schools-test/update-readme
					836e5bf HEAD@{5}: commit: Updated readme for GitHub Branches
					...
				$git reset --hard HEAD@{2}
				HEAD is now at 9a9add8 Added .gitignore
				This puts your branch back to the state it was in at that point.
			->	Tips & Best Practices
					Regularly commit your changes to avoid losing work
					Use git reflog to find lost commits
					Use git restore to recover deleted or changed files

(11). Git Advance 
	11.1)	Git .gitignore 
			->	What is .gitignore?
				The .gitignore file tells Git which files and folders to ignore (not track).
				This is useful for keeping log files, temporary files, build artifacts, or personal files out of your repository.
				Examples of files to ignore: log files, temporary files, hidden files, personal files, OS/editor files, etc.
				The .gitignore file itself is tracked by Git, so everyone using the repository ignores the same files.
			->	When to Use .gitignore
					When you want to keep sensitive, local, or unnecessary files out of your repository
					When sharing a project with others and want to avoid cluttering Git history
					When working with build tools or editors that create extra files
			->	Create a .gitignore File
				Go to the root of your local Git repository.
				Create a file named .gitignore:
				$touch .gitignore
			->	Ignoring Folders
				To ignore a folder and everything inside it, use a trailing slash:
				temp/ 
				This ignores any folder named temp anywhere in your project.
			->	Wildcards & Patterns
				Wildcards let you match many files or folders at once:
					* matches any number of characters
					? matches a single character
					[abc] matches any character in the set
					[!abc] matches any character not in the set
					e.g.
						*.tmp      		//all .tmp files
						my?ile.txt 		//matches my1ile.txt, myAile.txt, etc.
						log[0-9].txt 	//log1.txt, log2.txt, ... log9.txt 
			->	Negation (!)
				Use ! to not ignore something that would otherwise be ignored. This is called an exception:
				*.log
				!important.log 
				This ignores all .log files except important.log.
			->	Comments and Blank Lines
				Lines starting with # are comments and are ignored by Git. Blank lines are also ignored. Use comments to explain your rules:
				# Ignore log files
				*.log
				# Ignore temp folders
				temp/ 
			->	Local & Personal Ignore Rules
				If you want to ignore files only for yourself (not for everyone who uses the repository), add them to .git/info/exclude. This works just like .gitignore but is not shared.
			->	Global .gitignore(User Level)
				You can set up a global .gitignore file for all your projects. This is great for ignoring OS or editor files everywhere(like .DS_Store or Thumbs.db):
				$git config --global core.excludesfile ~/.gitignore_global	//c?
				Then add your patterns to ~/.gitignore_global.
			->	How to Stop Tracking a File
				If you add a file to .gitignore but Git is still tracking it, you need to tell Git to stop:
				$git rm --cached filename.txt
				This removes the file from the repository but keeps it on your computer. Next time you commit, Git will ignore it.
			->	Tips & Troubleshooting
					Check for typos-.gitignore is case-sensitive!
					If a file is already tracked, use git rm --cached to stop tracking it.
					Use comments (#) to explain tricky rules for your teammates.
					Use git status to see if your ignored files are being tracked.
					Remember: .gitignore only affects files that are not already tracked by Git.
			->	Pattern Syntax - to be visited
	11.2)	Git .gitattributes //c go if needed - not much imp at beginers level			
			->	What is .gitattributes?
				The .gitattributes file is a special file that tells Git how to handle specific files in your repository.
				It controls things like line endings, file types, merge behavior, custom diff tools, and more.
				Everyone on your team gets the same settings because this file is versioned with your project.
			->	When to Use .gitattributes
					To enforce consistent line endings across different operating systems
					To mark files as binary(so Git doesn't try to merge or change them)
					To enable Git LFS for large files
					To set up custom diff or merge tools for special file types
					To control how files are exported in archives
			->	Create or Edit .gitattributes
					Go to the root of your repository(or a subfolder for local rules).
					Create or edit the .gitattributes file.
					Add rules, one per line, for how Git should treat files.
				Example: Force Unix Line Endings for All Text Files
					*.txt text eol=lf
			->	Handle Line Endings
				Standardize line endings to avoid merge conflicts and broken files across different OSes.
				Example: Set LF for Shell Scripts
					*.sh text eol=lf
			->	Mark Files as Binary
				Tell Git which files are binary(not text).
				This prevents Git from trying to merge or change line endings for these files.
				Example: Mark PNG Files as Binary
					*.png binary
			->	Enable LFS for File Types
				Use Git LFS for large files like images or datasets.
				This tells Git to use LFS for these files:
				Example: Track PSD Files with LFS
					*.psd filter=lfs diff=lfs merge=lfs -text
			->	Custom Diff Settings
				Tell Git to use a special tool to compare certain file types(like Markdown or Jupyter notebooks):
				Example: Custom Diff for Markdown
					*.md diff=markdown
			->	Check Attributes
				See what attributes are set for a file:
				Example: Check Attributes of a File
					git check-attr --all README.md
			->	Advanced Usage
					Merge Strategies: Set custom merge drivers for tricky files(like lock files or notebooks).
					Export-ignore: Exclude files from tar/zip archives created by git archive:
					Example: Ignore Files on Export
						//docs/* export-ignore		/c in this line '//' added to avoid multiline comments symbol here
			->	Tips & Best Practices
					Patterns work like .gitignore(wildcards, etc).
					Put .gitattributes in subfolders for rules that only apply there.
					Changing .gitattributes will not retroactively fix files already committed-re-add files to update them.
					Use git check-attr to debug attribute issues.
			->	Note: .gitattributes is versioned with your project, so everyone on your team gets the same settings.
	11.3)	Git LFS	//c go if needed - not much imp at beginers level			
			->	What is Git LFS?
				Git LFS(Large File Storage) is an extension for Git that helps you manage large files (like videos, images, or datasets) efficiently.
				Instead of storing big files directly in your repository, LFS stores a small pointer file in your repo and keeps the real content on a separate LFS server.
				This keeps your repository fast and small, even if you work with huge files.
				Everyone who clones the repo gets the pointer, and Git LFS fetches the real file content as needed.
			->	When to Use Git LFS
					When you need to version large files(media, datasets, binaries)
					When your project exceeds the file size limits of standard Git hosting
					When you want to keep your repository size manageable and fast
			->	Install Git LFS
				Download and install Git LFS from git-lfs.github.com.
				Initialize LFS in your repository:
				Example
					$git lfs install
			->	Track Files with LFS
				Tell Git LFS which files to manage by "tracking" them. For example, to track all Photoshop files:
				Example: Track .psd Files
					$git lfs track "*.psd"
				You can track any file type. Here are more examples:
					$git lfs track "*.zip"
					$git lfs track "data/*.csv"
					$git lfs track "images/*.{png,jpg}"
			->	How LFS Works(.gitattributes & Pointers)
				When you track a file type with LFS, Git adds a rule to the .gitattributes file. This tells Git to use LFS for those files.
				Example: .gitattributes Entry
				*.psd filter=lfs diff=lfs merge=lfs -text 
				When you add and commit a tracked file, Git stores a small "pointer" file in your repo. The real content is uploaded to the LFS server.
				If you clone or pull a repo with LFS files, Git will download the real content from the LFS server(if you have LFS installed).
			->	Add, Commit, and Push LFS Files
					Add files as usual: git add largefile.psd
					Commit: git commit -m "Add large file"
					Push: git push origin main
				The actual file data is stored on the LFS server, while your repo contains a pointer file.
			->	Check LFS Status
				See which files are managed by LFS in your repo:
				Example: List LFS Files
					$git lfs ls-files
			->	Untrack/Remove Files from LFS
					Edit .gitattributes and remove or change the relevant line.
					Run the untrack command:
				Example: Untrack a File
					$git lfs untrack "*.psd"
					$git add .gitattributes
				Commit the change. The file will no longer be managed by LFS(but existing versions are still stored in LFS).
			->	Tips & Best Practices
					Use LFS only for files that are too large or change too often for regular Git.
					Check if your hosting provider supports LFS before using it(especially for private repos).
					Monitor your LFS storage quota. Free plans are often limited.
			->	Troubleshooting
					If you clone a repo and see pointer files instead of real content, make sure Git LFS is installed and run git lfs pull.
					If you push to a remote that does not support LFS, you will get an error.
					Some files may not upload if you exceed your LFS quota.
			->	Warnings
					Not all hosting providers support LFS. Check before using it.
					LFS storage is often limited on free plans.
	11.4)	Git Signing Commits/Tags
			->	What is Commit Signing?
				Signing a commit is like putting your personal signature on your work.
				It proves that you really made the change, and helps others trust your code.
				On platforms like GitHub or GitLab, signed commits often get a Verified badge.
			->	What is GPG?
				GPG(GNU Privacy Guard) is a tool that lets you create a digital key, kind of like a secret password, to sign things.
				Git uses GPG keys to sign commits and tags.
				This helps prove your identity and ensures your code has not been tampered with.
			->	Why and When Should You Sign Commits?
					To prove your commits really came from you
					To help others trust your code(especially in open source projects)
					Some companies or projects require signed commits for security
					If you do not sign, your commits are still valid, just not verified
			->	How to Set Up Commit Signing
				->	Create a GPG key (if you do not have one):
						Example: Generate a New GPG Key
						$gpg --full-generate-key
					Follow the prompts to create your key.
				->	Find your key ID:
						Example: List GPG Keys
						$gpg --list-secret-keys --keyid-format=long
					Look for a line like sec rsa4096/1234ABCD5678EFGH. The part after the slash is your key ID.
				->	Tell Git to use your key:
					Example: Set Signing Key
					git config --global user.signingkey <your-key-id>
			->	How to Sign Commits and Tags
					->	To sign a commit, use:
							$git commit -S -m "message"
					->	To sign a tag, use:
							$git tag -s v1.0 -m "version 1.0"
			->	Sign All Commits Automatically
				If you want Git to sign every commit by default, run:
					$git config --global commit.gpgSign true
			->	How to Check if a Commit is Signed
				To check in Git, run:
					$git log --show-signature
					On GitHub or GitLab, look for a Verified badge next to your commit or tag.
				Example: Signed Commit in Git Log
					commit 1234abcd5678efgh
					gpg: Signature made ...
					gpg: Good signature from "Your Name "
					Author: Your Name 
					Date:   ...
			->	Troubleshooting Signed Commits
					GPG failed to sign the data: Make sure your GPG agent is running and your key is loaded.
					Wrong key used: Double-check the key ID you set in Git.
					Still stuck? Try searching for the error message online or check your Git and GPG installation.
			->	Note: Signed commits and tags help ensure your code has not been tampered with and confirm your identity as the author.
					Some platforms may require additional setup to recognize your signature (for example, uploading your public key to GitHub or GitLab).
	11.5)	Git Cherry-pick & Patch
			->	What is Cherry-pick?
				Cherry-pick lets you copy a single commit from one branch to another. It is useful when you want just one(or a few) changes, not everything from another branch.
			->	What is a Patch?
				A patch is a file with changes from one or more commits. You can share a patch or apply it to another repository, even if it is unrelated to your own.
			->	When to Use Each
					Use cherry-pick to copy a commit between branches in the same repository.
					Use patches to share changes as files, or when working across different repositories.
			->	How to Cherry-pick a Commit
				Copy a specific commit from another branch to your current branch:
				Example: Cherry-pick a Commit
					$git cherry-pick abc1234
					This creates a new commit on your branch with the same changes.
			->	Edit the Commit Message
				Use --edit to change the commit message while cherry-picking:
				Example: Edit Commit Message
					$git cherry-pick abc1234 --edit
			->	Apply Without Committing
				Use --no-commit (or -n) to apply the changes, but not create a commit yet. This lets you make more changes before committing:
				Example: Cherry-pick Without Commit
					$git cherry-pick abc1234 --no-commit
			->	Add Commit Origin
				Use -x to add a line to the commit message showing where the commit came from:
				Example: Cherry-pick With Origin
					$git cherry-pick abc1234 -x
			->	Handling Conflicts
				If there are conflicts, Git will pause and ask you to fix them. After fixing, run:
				Example: Continue After Conflict
					$git add .
					$git cherry-pick --continue
				To cancel the cherry-pick, use:
				Example: Abort Cherry-pick
					$git cherry-pick --abort
			->	How to Create a Patch
				Make a patch file from a commit:
				Example: Create Patch
					git format-patch -1 abc1234
				For multiple commits:
				Example: Multiple Commits
					$git format-patch HEAD~3
			->	How to Apply a Patch
				Apply a patch file to your current branch:
				Example: Apply Patch
					$git apply 0001-some-change.patch
			->	Apply a Patch and Keep Metadata
				Use git am to apply a patch and keep the original author and message:
				Example: Apply Patch with Metadata
					$git am 0001-some-change.patch
			->	Reverse a Patch
				Undo the changes in a patch file:
				Example: Reverse Patch
					$git apply -R 0001-some-change.patch
			->	Tip: 
					Use cherry-pick for copying a single commit in the same repository.
					Use patches to share changes as files or work across repositories.
					If you want to keep commit history and authors, use "git am" instead of "git apply".
			->	Troubleshooting & Best Practices
					Cherry-pick conflicts: If you get conflicts, fix them, then run git cherry-pick --continue.
					Abort with git cherry-pick --abort if needed.
					Patch doesn't apply cleanly: Make sure the patch matches your codebase. Sometimes you may need to adjust manually.
					Keep your branches up to date: Before cherry-picking or applying patches, pull the latest changes.
	11.6)	Git Merge Conflicts
			->	What is a Merge Conflict?
				A merge conflict happens when two branches change the same part of a file.
				Git ca not decide which change to keep, so you have to choose.
				You must resolve the conflict before you can finish the merge.
			->	Why Do Merge Conflicts Happen?
				Merge conflicts usually happen when you merge branches that changed the same lines in a file.
				This is common in collaborative projects or when working on long-lived branches.
			->	How to See and Resolve Merge Conflicts
				When you merge a branch and there are conflicting changes, Git will pause and mark the files with conflicts.
				Example: Merge a Branch
					$git merge feature-branch
				If there are conflicts, Git will tell you which files are affected.
				See Which Files Have Conflicts
				Use git status to see which files need your attention:
				Example: Check Status
					$git status
			->	See the Differences
				Use git diff to see what changed and help you decide how to resolve the conflict:
				Example: See Differences
					$git diff
			->	Edit the Conflict Markers
				Open the conflicted file. You'll see sections like this:
				Conflict Markers
					<<<<<<< HEAD
					Your changes here
					=======
					Other branch's changes
					>>>>>>> feature-branch 
				Edit the file to keep what you want, then remove the conflict markers (<<<<<<<, =======, >>>>>>>).
			->	Mark as Resolved
				After fixing the file, mark it as resolved:
				Example: Mark Resolved
					$git add filename.txt
			->	Complete the Merge
				Finish the merge with a commit (if Git does not do it automatically):
				Example: Finish Merge
					$git commit
			->	Cancel the Merge
				If you want to stop and undo the merge:
				Example: Abort Merge
					$git merge --abort
			->	Use a Visual Merge Tool
				If you prefer, you can use a visual tool to resolve conflicts:
				Example: Use Mergetool
					$git mergetool
			->	Pick One Side's Changes
				If you want to keep only your changes or only the other branch's changes:
				Example: Keep Our Changes
					$git checkout --ours filename.txt
				Example: Keep Their Changes
				$git checkout --theirs filename.txt
			->	Troubleshooting & Best Practices
					If you're stuck, you can always use git merge --abort to start over.
					Make sure you remove all conflict markers before marking as resolved.
					If you use git mergetool and do not like the result, you can still edit the files by hand.
	11.7)	Git CI/CD
			->	What is CI/CD?
				CI/CD stands for Continuous Integration and Continuous Deployment/Delivery.
				It means your code is automatically tested and deployed every time you push.
				This helps you catch bugs early and deliver features faster, with less manual work.
			->	Why Use CI/CD?
				CI/CD automates the process of testing and deploying your code. This means:
					Find bugs before they reach users
					Deploy changes faster and more safely
					Reduce manual steps and mistakes
					Get quick feedback on every push
			->	How Does CI/CD Work with Git?
				Every time you push code to your Git repository:
					The CI/CD service(like GitHub Actions or GitLab CI) detects the change
					It runs tests, builds your project, and can deploy automatically
					If something fails, you get notified right away
				Example Workflow
					[Developer] --push--> [Git Repository] --triggers--> [CI/CD Pipeline: Test, Build, Deploy] 
				Popular CI/CD Services
					GitHub Actions: Built into GitHub, uses YAML files in .github/workflows/
					GitLab CI/CD: Built into GitLab, uses .gitlab-ci.yml
					CircleCI: Works with GitHub/GitLab, easy setup for many languages
					Travis CI: Popular for open-source, uses .travis.yml
					Azure Pipelines: Works with Azure DevOps and GitHub, supports many platforms
				Key CI/CD Concepts
				Here are some important terms:
					Workflow: A series of jobs that run together
					Job: A group of steps that run together
					Step: A single task, like checking out code or running tests
					Runner: The computer/server that runs your jobs
					Trigger: Decides when your workflow runs
					Environment Variables: Settings for your workflow
					Secrets: Passwords or API keys
			->	if needed, visit https://www.w3schools.com/
	11.8)	Git Hooks
			->	What are Git Hooks?
				Git hooks are scripts that run automatically when certain Git events happen, like making a commit or pushing code.
			->	Why Use Hooks?
				Hooks help you automate repetitive tasks, enforce coding standards, and catch problems early.
				For example, you can:
					Run tests before every commit or push
					Check code style automatically
					Block bad commit messages
					Enforce rules for everyone on your team
			-> 	Where Do Hooks Live?
				Hooks are stored in .git/hooks inside your repository.
				By default, you'll see sample scripts ending with .sample.
				Example: List Available Hooks
					$ls .git/hooks
			->	if needed, visit https://www.w3schools.com/
	11.9)	Git Submodules
			->	What Are Git Submodules?
				Git submodules let you include one Git repository inside another as a subdirectory.
				This is useful for adding libraries or dependencies managed in separate repositories, while keeping their commit history separate.
			->	Why Use Submodules?
				Submodules are helpful when you want to:
					Reuse code from another project
					Track a library or dependency at a specific commit
					Keep histories of projects separate
			->	How to Add a Submodule
					To add a submodule to your project, use:
					Example: Add a Submodule
					$git submodule add https://github.com/example/library.git libs/library
						This creates a subdirectory libs/library and updates .gitmodules with the submodule info.
			->	How to Clone a Repo with Submodules
				When you clone a repository with submodules, you need to fetch their contents separately:
				Example: Init and Update Submodules
					$git submodule init
					$git submodule update
				Or do it all at once when cloning:
				Example: Clone with Submodules
					$git clone --recurse-submodules https://github.com/user/repo.git
			->	How to Check Submodule Status
				To see the current commit and state of your submodules, use:
				Example: Submodule Status
					$git submodule status
			->	How to Run Commands in All Submodules
				You can run a command in every submodule. For example, to check their status:
				Example: foreach
					$git submodule foreach git status
			->	How to Update Submodules
				To update submodules to the latest commit from their remote repository:
				Example: Update All Submodules
					$git submodule update --remote
			->	How to Remove a Submodule
				To remove a submodule:
					Delete the relevant section from .gitmodules
					Remove the submodule directory from your working tree
					Run git rm --cached path/to/submodule
			->	About .gitmodules
				The .gitmodules file keeps track of all submodules and their paths. Edit this file if you move or remove submodules.
				Example: .gitmodules File
				[submodule "libs/library"]
					path = libs/library
					url = https://github.com/example/library.git 
			->	Troubleshooting and Best Practices
					If submodules are empty after cloning, run git submodule update --init --recursive.
					If you change a submodule's URL, update both .gitmodules and .git/config.
					Submodules always point to a specific commit, not always the latest-remember to update if you want new changes.
					Keep submodules for external projects you want to track at a fixed version. For simpler needs, consider alternatives like Git subtree or copying files.
			->	Note: Submodules are powerful, but can be tricky to manage.
					Only use them if you really need to track another project at a specific commit.
	11.10)	Git Rmote Advance
			->	What Are Git Remotes?
				Remotes are references to remote repositories.
				They let you collaborate, fetch, and push code to shared projects on services like GitHub, GitLab, or Bitbucket.
			->	Why Use Multiple Remotes?
					You can add more than one remote to your project. This is useful for:
					Collaborating with different teams(e.g., your fork and the main project)
					Mirroring repositories
					Maintaining backups
			->	How to Add a Remote
				To add a new remote repository:
				Example: Add a Remote
					$git remote add upstream https://github.com/other/repo.git
			->	How to Remove a Remote
				To remove a remote repository:
				Example: Remove a Remote
					$git remote remove upstream
			->	How to Rename a Remote
				To change the name of an existing remote(for example, renaming origin to main-origin):
				Example: Rename a Remote
					$git remote rename origin main-origin
			->	How to List All Remotes
				See all remotes and their URLs:
				Example: List Remotes
					$git remote -v
			->	How to Show Remote Details
				Get detailed information about a specific remote(such as fetch/push URLs and tracked branches):
				Example: Show Remote Info
					$git remote show upstream
			->	How to Fetch from a Remote
				Fetch changes from any remote:
				Example: Fetch from Upstream
					$git fetch upstream
			->	How to Push to a Remote
				Push your local branch to a specific remote repository:
				Example: Push to a Remote
					$git push upstream main
			->	How to Track a Remote Branch
				To set up a local branch to track a branch from a remote:
				Example: Track a Remote Branch
					$git checkout -b new-feature upstream/new-feature
			->	Note: 
					Managing multiple remotes is common in open source projects(e.g., origin for your fork, upstream for the main project).
			->	Troubleshooting and Best Practices
					If you get "remote not found", check the spelling of the remote name with git remote -v.
					If fetch or push fails, make sure you have access to the remote repository.
					Use git remote show <name> to see details and troubleshoot issues.
					Check your network connection if you cannot reach a remote server.
					Use clear, descriptive names for remotes(e.g., origin, upstream, backup).
					Remove unused remotes to keep your project tidy.
Extra: 	->	In Git, "diverged" means that two branches (usually your local branch and its remote tracking counterpart) have split onto separate paths of commit history after a shared starting point.
		->	Fast-Forward Merge: If the base branch has not changed since you branched off, Git simply moves the branch pointer forward to your latest commit. 
			No merge commit is created because no divergence occurred.
				->	Imagine there is a branch
					Master : A---> B ---> 
					There are two commits on it, A and B There is another feature branch, from B, it has the following commit History
					Feature : C--->D---->E
					So the present it looks like this
					`A--->B`
						 `C--->D--->E `
					So when you want to merge it, you can do it by fast forward merge by moving the head from B to E and incorporating the feature branch in the main branch and it looks like this
					A--->B--->C--->D--->E with the header at E.
		->	A merge commit is a unique type of Git commit that integrates changes from two or more diverging branches into a single.
			If the base branch has received new commits since you originally branched off, the history has diverged. Git automatically creates a merge commit to bridge the two trajectories.
		->	in git(even in linux terminal), when colon(:) occurs on console, we can type n for next & q for quit		
		->	-f & --force are dentical	
					
#if 0	
				exe	- target	tutorial
	2026.02	1st	all				linux
			2nd	all				linux
			3rd	all				linux
			4th	all 			linux
	2026.03	1st	all				ad. linux
			2nd	all				ad. linux
			3rd	all	- dChin		ad. linux
			4th	all - swim		ad. linux
	2026.04	1st	all				MCU_1
			2nd	all				MCU_1
			3rd	all				MCU_1
			4th	all - swim		MCU_1
	2026.05	1st	all				MCU_2
			2nd	all				MCU_2
			3rd	all				MCU_2
			4th	all - swim		MCU_2
	2026.06	1st	all				nothing
			2nd	all				nothing
			3rd	all				esp
			4th	all - reg		esp
#endif