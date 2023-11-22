# 7677. Fibonacci (Gold II) 

[Problem Link](https://www.acmicpc.net/problem/7677) 

## Tags

exponentiation by squaring, mathematics, number theory

## Problem Description

<p>In the Fibonacci integer sequence, F<sub>0</sub> = 0, F<sub>1</sub> = 1, and F<sub>n</sub> = F<sub>n−1</sub> + F<sub>n−2</sub> for n ≥ 2. For example, the first ten terms of the Fibonacci sequence are:</p>

<p>0, 1, 1, 2, 3, 5, 8, 13, 21, 34, . . .</p>

<p>An alternative formula for the Fibonacci sequence is</p>

<p>\[\begin{bmatrix} F_{ n+1 } & F_{ n } \\ F_{ n } & F_{ n-1 } \end{bmatrix}=\begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix}^n\]</p>

<p>Given an integer n, your goal is to compute the last 4 digits of F<sub>n</sub>.</p>

## Input

 <p>The input test file will contain multiple test cases. Each test case consists of a single line containing n (where 0 ≤ n ≤ 1,000,000,000). The end-of-file is denoted by a single line containing the number -1.</p>

## Output

 <p>For each test case, print the last four digits of Fn. If the last four digits of Fn are all zeros, print ‘0’; otherwise, omit any leading zeros (i.e., print F<sub>n</sub> mod 10000).</p>

## Submission Date

2021년 1월 30일 04:54:26

