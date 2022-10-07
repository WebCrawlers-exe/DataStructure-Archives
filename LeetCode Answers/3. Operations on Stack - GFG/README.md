# 3. Operations on Stack
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a <strong>stack </strong>of <strong>integers </strong>and <strong>Q</strong> queries. The task is to perform the operation on stack according to the query.</span></p>

<p><span style="font-size:18px">The queries can be of 4 types:</span></p>

<ol>
	<li dir="ltr">
	<p dir="ltr"><span style="font-size:18px"><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"><strong>i x:</strong> (<strong>adds </strong>element x in the stack)</span>.</span></p>
	</li>
	<li dir="ltr">
	<p dir="ltr"><span style="font-size:18px"><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"><strong>r:</strong> (<strong>removes </strong>the topmost element from the stack).</span></span></p>
	</li>
	<li dir="ltr">
	<p dir="ltr"><span style="font-size:18px"><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"><strong>h:</strong> </span>Prints the topmost element.</span></p>
	</li>
	<li dir="ltr">
	<p dir="ltr"><span style="font-size:18px"><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"><strong>f y:</strong> (check if the <strong>element </strong>y is <strong>present or not </strong>in the stack).</span> Print "<strong>Yes</strong>" if present, else "<strong>No</strong>".</span><br>
	&nbsp;</p>
	</li>
</ol>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: 
</strong>Q = 6 
Queries = {(i, 2), (i, 4), (i, 3),
(i, 5), (h), (f, 8)}
<strong>Output: 
</strong>5
No<strong>
Explanation: 
</strong>Inserting 2, 4, 3, and 5 
onto the stack. Returning top element 
which is 5. Finding 8 will give No, 
as 8 is not in the stack.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
Q = 4
Queries = {(i, 3), (i, 4), (r), (f, 3)}
<strong>Output: 
</strong>Yes
<strong>Explanation: 
</strong>Inserting 3 and 4 onto the 
stack. Finding 3 will give Yes as output 
because 3 is available in the stack.</span></pre>

<p>&nbsp;</p>

<p dir="ltr"><span style="font-size:18px"><strong>Your Task:</strong><br>
Your task is to complete functions <strong>insert()</strong>, <strong>remove()</strong>, <strong>headOf_Stack()&nbsp;</strong>which takes a stack as input parameter, and <strong>find() </strong>which takes a stack and value as input parameter, to insert, remove returning top element, and finding the element in stack respectively.</span></p>

<p dir="ltr">&nbsp;</p>

<p dir="ltr"><span style="font-size:18px"><strong>Expected Time Complexity: </strong><br>
For find(): O(N),<br>
For others: O(1).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1).</span></p>

<p dir="ltr"><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ Number of queries ≤ 10<sup style="">3</sup></span></p>
 <p></p>
            </div>