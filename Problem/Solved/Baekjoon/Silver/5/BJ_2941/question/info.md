# [크로아티아알파벳](https://www.acmicpc.net/problem/2941)

<center>

| 시간 제한 | 메모리 제한 |
| :-------: | :---------: |
|   1 초    |   128 MB    |

</center>
<br />

## 문제

<br />

&nbsp; 예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.

<br/>
<center>

| 크로아티아 알파벳 | 변경 |
| :---------------: | :--: |
|         č         |  c=  |
|         ć         |  c-  |
|        dž         | dz=  |
|         đ         |  d-  |
|        lj         |  lj  |
|        nj         |  nj  |
|         š         |  s=  |
|         ž         |  z=  |

</center>
<br/>

&nbsp; 예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

&nbsp; dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.

<br />

## 입력

<br />

&nbsp; 첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.

&nbsp; 단어는 크로아티아 알파벳으로 이루어져 있다. 문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.

<br />

## 출력

<br />

&nbsp; 입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

<br />
<center>
<style>th {width: 30vw; text-align: center;} td {padding: 1em;}</style>
<table><tr><th>예제 입력 1</th><th>예제 출력 1</th></tr><tr><td><div>

```
ljes=njak
```

</div></td><td>

```
6
```

</td></tr></table><br />
<table><tr><th>예제 입력 2</th><th>예제 출력 2</th></tr><tr><td><div>

```
ddz=z=
```

</div></td><td>

```
3
```

</td></tr></table><br />
<table><tr><th>예제 입력 3</th><th>예제 출력 3</th></tr><tr><td><div>

```
nljj
```

</div></td><td>

```
3
```

</td></tr></table><br />
<table><tr><th>예제 입력 4</th><th>예제 출력 4</th></tr><tr><td><div>

```
c=c=
```

</div></td><td>

```
2
```

</td></tr></table><br />
<table><tr><th>예제 입력 5</th><th>예제 출력 5</th></tr><tr><td><div>

```
dz=ak
```

</div></td><td>

```
3
```

</td></tr></table>
</center>
<br />

## 출처

<br />

Contest > Croatian Open Competition in Informatics > COCI 2008/2009 > Contest #5 1번

<br />

## 알고리즘 분류

<br />

- 구현
- 문자열
