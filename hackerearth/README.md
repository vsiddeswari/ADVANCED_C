<h1>problem</h1>

After getting her PhD, Christie has become a celebrity at her university, and her facebook profile is full of friend requests. Being the nice girl she is, Christie has accepted all the requests.
Now Kuldeep is jealous of all the attention she is getting from other guys, so he asks her to delete some of the guys from her friend list.

To avoid a 'scene', Christie decides to remove some friends from her friend list, since she knows the popularity of each of the friend she has, she uses the following algorithm to delete a friend.

Algorithm Delete(Friend): DeleteFriend=false for i = 1 to Friend.length-1 if (Friend[i].popularity < Friend[i+1].popularity) delete i th friend DeleteFriend=true break if(DeleteFriend == false) delete the last friend

<h2>Input:</h2>
First line contains T number of test cases. First line of each test case contains N, the number of friends Christie currently has and K ,the number of friends Christie decides to delete. Next lines contains popularity of her friends separated by space.
<h2>Output:</h2>
For each test case print N-K numbers which represent popularity of Christie friend's after deleting K friends.
<h2>Constraints</h2>
1<=T<=1000 1<=N<=100000 0<=K< N 0<=popularity_of_friend<=100
<b>NOTE:</b>
Order of friends after deleting exactly K friends should be maintained as given in input.
<h3>Sample Input</h3>
3

3 1 

3 100 1

5 2 

19 12 3 4 17 

5 3 

23 45 11 77 18

<h3>Sample Output</h3>

100 1 

19 12 17

 77 18

