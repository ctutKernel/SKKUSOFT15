
#The maximum-subarray problem
##**"buy low, sell high!"**
###문제 내용
당신이 어떤 불안한 화학 회사에 투자를 할 기회가 생겼다고 가정해보자. 이 회사의 주식은 매우 불안정하여 당신은 주식을 한번만 사고 다시 되팔아 이익을 보기로 결정했다. 

투자를 하기전 당신은 회사의 주식 시세 그래프를 분석하여 어떤 기간에 최대 차익을 얻을 수 있는지 알아보고자 한다. 그래프는 날짜별로 그날 주식 시장이 닫힐때, 주식의 가격이 기록되어 있다. 어떻게 하면 차익이 최대가 되는 기간을 구할 수 있을까?

###Input
 - 주식 시세 그래프
	 - 날짜
	 - 가격

###Output
 - 주식의 차익이 가장 클 수 있는 기간
###풀이 방법
maximum-subarray 문제를 푸는 방법에는 2가지가 있다.

 - A brute-force solution
 - divde & conquer

>###**brute-force solution**
>brute-force solution은 가능한 모든 케이스들을 모두 확인해 보는 것을 뜻한다.  n개의 값에 대해 조합할 수 있는 경우의 수는 `Θ(n^2)`이고, 각각의 케이스에 대한 계산을 constant time안에 끝낸다고 가정했을 때, 이 접근법은 `Ω(n^2)` 이다.
>###**divide & conquer**
>1. divide : array를 start == end가 될 때까지 나눈다.
>2. conquer : 
 * **[Base case]** array가 start == end일 때
>가능한 경우의 수는 1, 자기 자신을 return 하는 것
 * **[Recursive case]** array가 start != end일 때
>가능한 경우의 수는 3, left Max, right Max, mid include Max 3가지 중 가장 큰 것을 return
>3. combine 
>bottom out 되면서 문제 해결
>
> from [Introduction to Algorithm](http://bayanbox.ir/view/4177858657730907268/introduction-to-algorithms-3rd-edition.pdf)

