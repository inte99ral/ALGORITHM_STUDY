# \_ETC\_

https://codingeverybody.kr/css-text-align-%ec%86%8d%ec%84%b1/

<div style="
  display: flex;
">
  <div class="lbox" style="
    width: 40vw;
    aspect-ratio: 1/1;
    display: flex;
    justify-content:center;
    background: gray;
    overflow: visible;
  ">
    <div class="lbox-bar-1" style="
      width: 10vw;
      aspect-ratio:1/1;
      background: red;
    "></div>
    <div class="lbox-bar-2" style="
      width: 10vw;
      height: 5vw;
      aspect-ratio:1/1;
      background: green;
    "></div>
  </div>
  <div class="rbox" style="
    width: 40vw;
    aspect-ratio: 1/1;
    background: lightgray;
  "></div>
</div>

gantt
title A Gantt Diagram
dateFormat YYYY-MM-DD
section Section
A task :a1, 2014-01-01, 30d
Another task :after a1, 20d
section Another
Task in Another :2014-01-12, 12d
another task :24d
