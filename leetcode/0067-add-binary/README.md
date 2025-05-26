<h2><a href="https://leetcode.com/problems/add-binary">67. Add Binary</a></h2>

## 풀이 및 느낀점

- 뒤에서부터 문자열을 생성해야 할 경우는 `reverse()` 를 사용하는 게 낫다.
    1. 매번 `append()` 하기
        1. string 복사가 매번 일어난다. 
    2. 내가 제출한 방법 - fill하고 `insert()` 해서 필요한 index만 수정
        1. insert 인덱스를 찾는 연산이 0을 만들 때 마다 일어난다.
    3. 개선안: (100%) - 그냥 문자열 만들고 `reverse()`
        1. reverse 할 때만 순회 + 복사가 일어난다.

<h3>Easy</h3><hr><p>Given two binary strings <code>a</code> and <code>b</code>, return <em>their sum as a binary string</em>.</p>


<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> a = "11", b = "1"
<strong>Output:</strong> "100"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> a = "1010", b = "1011"
<strong>Output:</strong> "10101"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>4</sup></code></li>
	<li><code>a</code> and <code>b</code> consist&nbsp;only of <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code> characters.</li>
	<li>Each string does not contain leading zeros except for the zero itself.</li>
</ul>

