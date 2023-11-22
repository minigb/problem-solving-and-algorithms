# 3745. 오름세 (Gold II) 

[Problem Link](https://www.acmicpc.net/problem/3745) 

## Tags

binary search, longest increasing sequence in o(n log n)

## Problem Description

<p>주식투자를 좋아하는 정인이는 주가의 오름세를 살펴보려고 한다.</p>

<p>정인이는 n일 동안 매일 주가를 적어놓았고, 여기서 오름세를 찾아보려고 한다.</p>

<p>n일 동안의 주가를 p<sub>1</sub>, p<sub>2</sub>, ..., p<sub>n</sub>이라고 했을 때, 오름세란 부분수열 p<sub>i<sub>1</sub></sub> < p<sub>i<sub>2</sub></sub> < ... < p<sub>i<sub>k</sub></sub> (i<sub>1</sub> < i<sub>2</sub> < ... i<sub>k</sub>)을 말한다.</p>

<p>n일 동안 주가가 주어졌을 때, 가장 긴 오름세를 찾는 프로그램을 작성하시오.</p>

## Input

 <p>입력은 여러개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 주가를 관찰한 날의 수 N (N ≤ 100000)이 주어진다. 둘째 줄에는 관찰한 주가가 첫 날부터 순서대로 주어진다. 주가는 한 개 이상의 공백으로 구분되어 있으며, 그 외의 위치에서도 자유롭게 나올 수 있다. 주가는 100,000보다 작거나 같은 자연수이다.</p>

## Output

 <p>각 테스트 케이스에 대해서 입력으로 주어진 주가의 가장 긴 오름세의 길이를 출력한다.</p>

## Submission Date

2020년 7월 30일 14:30:09

