# \_ETC\_

## 목차

## ...로 글자 줄이기

```css
div {
  overflow: hidden;
  text-overflow: ellipsis;
  white-space: nowrap;
}
```

## ??

https://codingeverybody.kr/css-text-align-%ec%86%8d%ec%84%b1/

<div style="display: flex;">
  <div class="lbox" style="
    width: 40vw;
    aspect-ratio: 1/1;
    display: flex;
    flex-wrap: nowrap;
    align-items: center;
    background: gray;
    overflow: visible;
    position: relative;
  ">
    <div class="lbox-bar-1" style="
      width: 35vw;
      height: 100px;
      background: red;
      flex-shrink: 0;
    "></div>
    <div class="lbox-bar-2" style="
      width: 10vw;
      height: 100px;
      background: green;
      flex-shrink: 0;
    "></div>
    <div class="lbox-bar-3" style="
      width: 10vw;
      height: 100px;
      background: blue;
      position: absolute;
      top: 100px;
      left: 100px;
      z-index: 100;
    "></div>
  </div>
  <div class="rbox" style="
    width: 40vw;
    aspect-ratio: 1/1;
    background: lightgray;
    z-index: -1;
  "></div>
</div>

## 접기 / 펼치기

<details>
    <summary>자세히</summary>

<!-- summary 아래 한칸 공백 두고 내용 삽입 -->

테스트 00<br />
관련 정보

</details>
