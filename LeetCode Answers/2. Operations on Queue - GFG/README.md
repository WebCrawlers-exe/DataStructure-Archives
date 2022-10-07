# 2. Operations on Queue
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a queue of <strong>integers </strong>and <strong>Q</strong> queries. The task is to perform operations on queue according to the query.&nbsp;</span></p>

<p><span style="font-size:18px">Queries are as:</span></p>

<ol>
	<li dir="ltr">
	<p dir="ltr"><span style="font-size:18px"><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"><strong>i x :</strong> (<strong>adds </strong>element x in the queue from rear)</span>.</span></p>
	</li>
	<li dir="ltr">
	<p dir="ltr"><span style="font-size:18px"><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"><strong>r :</strong> (<strong>Removes</strong><strong> </strong>the <strong>front</strong> element of queue).</span></span></p>
	</li>
	<li dir="ltr">
	<p dir="ltr"><span style="font-size:18px"><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"><strong>h :</strong>&nbsp;(<strong>Returns</strong></span>&nbsp;the <strong>front</strong> element).</span></p>
	</li>
	<li dir="ltr">
	<p dir="ltr"><span style="font-size:18px"><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"><strong>f y :</strong> (check if the element<strong> </strong>y is <strong>present or not </strong>in the queue).</span> Return&nbsp;"<strong>Yes</strong>" if present, else "<strong>No</strong>".</span></p>
	</li>
</ol>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>Q = 6
Queries = i 2 i 4 i 3 i 5 h f 8
<strong>Output:
</strong>2
No<strong>
Explanation: </strong>Inserting 2, 4, 3, and 5
onto the queue: 2 4 3 5. h means front
So front is 2. f is find. 8 is not in
queue so No.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>Q = 4
Queries = i 3 i 4 r f 3
<strong>Output: </strong>No<strong>
Explanation: </strong>Inserting 3 and 4 . When
we return and remove 3 and then when
we find 3 , it will return NO as
output as 3 is not present in the
queue.</span></pre>

<p dir="ltr"><span style="font-size:18px"><strong>Your Task:</strong><br>
Your task is to complete functions <strong>enqueue()</strong>, <strong>dequeue()</strong>, <strong>front()</strong> and <strong>find()&nbsp;</strong>which performs the operations described above in the problem description.</span></p>

<p dir="ltr"><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(1) for&nbsp;<strong>enqueue(), dequeue()&nbsp;</strong>and&nbsp;<strong>front()</strong>; O(N) for&nbsp;<strong>find().<br>
Expected Auxiliary Space:&nbsp;</strong>O(1) for all the 4 functions.&nbsp;</span></p>

<p dir="ltr"><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= Q &lt;= 10<sup style="">3</sup></span></p>
 <p></p>
            </div>