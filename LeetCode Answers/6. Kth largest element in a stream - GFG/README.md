# 6. Kth largest element in a stream
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an input stream of <strong>n</strong> integers, find the <strong>k<sup>th</sup></strong> largest element each time when&nbsp;an new element is added to the stream.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>k = 4, n = 6
arr[] = {1,2,3,4,5,6}
<strong>Output: </strong>-1 -1 -1 1 2 3<strong>
Explanation: </strong>k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1
{1, 2, 3, 4}
For 5, the 4th largest element is 2
{2, 3, 4 ,5}
For 6, the 4th largest element is 3
{3, 4, 5, 6}</span>

</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>k = 1, n = 2
arr[] = {3,4}
<strong>Output: </strong>3 4&nbsp;</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You are required to complete the&nbsp;method&nbsp;<strong>kthLargest()</strong> which takes 3 arguments and prints kth largest&nbsp;element <strong>-1</strong>.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= n &lt;= 10<sup>6</sup><br>
1 &lt;= k&nbsp;&lt;= n<br>
1 &lt;= arr[i] &lt;= 10<sup>5</sup></span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(n*Log(k))<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(k)</span></p>
 <p></p>
            </div>