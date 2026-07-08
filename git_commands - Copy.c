just to check 3-way merge
line_0 added
line_1 added
line_2 added
line_3 added
line_4 added
line_5 added


$git fetch origin
$git pull origin main
$git pull --rebase origin main

Please explain me the difference between these three with approapriate examples:
$git fetch origin
$git pull origin main
$git pull --rebase origin main

Also, if possible I wan to hands-on for this. 


git pull origin main:	Merges main into your currently checked-out branch (even if you are not on main).
git pull origin:		Only merges the tracking counterpart of your current branch.

To update your local main branch:
To get the latest main changes into your feature branch:

Difference between $git fetch origin & $git pull origin main & $git pull --rebase origin main:
	1. $git fetch origin: Downloads the cloud updates but does not touch your current working files. It is 100% safe.
	2. git pull origin main: Downloads cloud updates and automatically merges them into your local file system, often creating a 3-way merge commit.
	3. git pull --rebase origin main: Downloads cloud updates and re-roots your local work on top of those updates, keeping your timeline completely straight






1. $git fetch origin, 
2. $git pull origin main & 
3. $git pull --rebase origin main 