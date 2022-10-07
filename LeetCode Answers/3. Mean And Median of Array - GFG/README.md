# 3. Mean And Median of Array
## Easy 
<div class="problem-statement">
                <p></p><p dir="ltr"><span style="font-size:18px">Given an array <strong>a[ ]</strong> of size <strong>N</strong>. The task is to find the <strong>median</strong> and <strong>mean</strong> of the array elements. Mean is average of the numbers and median is the element which is smaller than half of the elements and greater than remaining half.&nbsp; If there are odd elements, the median is simply the middle element in the sorted array. If there are even elements, then the median is floor of average of two middle numbers in the sorted array. If mean is floating point number, then we need to print floor of it.</span></p>

<p dir="ltr"><strong><span style="font-size:18px">Note: </span></strong><span style="font-size:18px">To find the <strong>median</strong>, you might need to <strong>sort </strong>the array. Since sorting is covered in later tracks, we have already provided the sort function to you in the code.</span></p>

<p dir="ltr"><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
a[] = {1, 2, 19, 28, 5}
<strong>Output: </strong>11 5<strong>
Explanation: </strong>For array of 5 elements,
mean is (1 + 2 + 19&nbsp; + 28&nbsp; + 5)/5 = 11.
Median is 5 (middle element after 
sorting)</span></pre>

<p dir="ltr"><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4
a[] = {2, 8, 3, 4}
<strong>Output: </strong>4 3<strong>
Explanation: </strong>For array of 4 elements,
mean is floor((2 + 8 + 3 + 4)/4) = 4.
Median is floor((4 + 3)/2) = 3</span>
</pre>

<p dir="ltr"><strong><span style="font-size:18px">Your Task:</span></strong><br>
<span style="font-size:18px">You don't need to read input or print anything.. You just need to complete the following two function:</span></p>

<ul dir="ltr">
	<li><span style="font-size:18px"><strong>mean():</strong> It takes the <strong>array </strong>and its <strong>size </strong>N as <strong>parameters </strong>and <strong>returns </strong>the <strong>mean </strong>as an <strong>integer</strong>.</span></li>
	<li><span style="font-size:18px"><strong>median():</strong> It takes the <strong>array </strong>and its <strong>size </strong>N as parameters and <strong>returns </strong>the <strong>median </strong>as an <strong>integer</strong>.</span></li>
</ul>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N log(N)).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p dir="ltr"><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10</span><sup style=""><span style="font-size:15px">6</span></sup><br>
<span style="font-size:18px">1 &lt;= a[i] &lt;= 10<sup style="">6</sup></span></p>
 <p></p>
            </div>