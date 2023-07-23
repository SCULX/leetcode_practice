![GitHub Workflow Status (with event)](https://img.shields.io/github/actions/workflow/status/SCULX/leetcode_practice/lcpractice.yml?logo=buddy&link=https%3A%2F%2Fgithub.com%2FSCULX%2Fleetcode_practice%2Factions%2Fworkflows%2Flcpractice.yml)


# leetcode_practice
Use leetcode to learn algorithms

## Attention
1.If you want to check the whole leetcode exercises, just see the `main` branch.<br>
2.The `mid` branch is only a simplify version of the medium difficulty problem, with only the solution and no other compilation information included.<br>
3.Future, I may creat a new branch called `hard`,which is the collection of hard difficulty questions and have the similar function with `mid` branch.<br>

## Workflow Intro
1. This branch has integrated `github flow` workflow, and uses the official `ubuntu` online environment to continuous integration and test code. The detailed operation steps are as follows:

***
1. Click `Actions` in the navigation bar on the `main` branch, then you may see
![image](https://github.com/SCULX/leetcode_practice/assets/75171632/14facf15-112f-448a-8ef8-6325f36650c6)
 
 In the above figure, you can see a `wokrflow` in the red box named `lcpractice`.
 
 2. Then click the `lcpractice` to manually run and you may see
![image](https://github.com/SCULX/leetcode_practice/assets/75171632/454b1a27-e6c0-4713-b5b9-b69f558c5280)
 
 Click ①`Run workflow` first, then click ②`run workflow`.
 
 3. Wait for the system to automatically run and test, or click on it to enter the details page like this
 ![image](https://github.com/SCULX/leetcode_practice/assets/75171632/9068d5e8-9ca6-4822-a217-bd5718da447b)

In this image, you can see that 5 steps need to be executed, and **Set up job** and **Complete job** are system self-taking.<br>
Others such as **clone**、**install**、**run**、**test**、**test** are self-set. These run on the ubuntu system provided by github.

4. Due to the writing environment is `Windows` and testing environment is `Linux`, there may be many file format issues, so the execution of the. exe file was not carried out in the `test`.
