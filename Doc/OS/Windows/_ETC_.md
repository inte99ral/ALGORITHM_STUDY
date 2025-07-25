# _ETC_：윈도우 기타 항목

## 속도 및 보안성 개선

- `설정 > 네트워크 및 인터넷 > 프록시` 에서 `자동으로 설정 검색` 끄기
- `설정 > 개인 설정 > 시작` 에서 `팁, 바로가기, 새 앱 등에 대한 권장 사항 표시` 끄기
- `설정 > 개인 정보 및 보안 > 일반` 에서
  - `내 광고 ID를 사용하여 앱에서 개인 설정된 광고를 표시하도록 허용` 끄기
  - `Windows에서 앱 시작을 추적해서 시작 및 검색 결과를 개선할 수 있게 해 주세요.` 끄기 (대신 명령어 목록 같은 것이 남지 않게되서 불편할 수는 있습니다)
  - `앱 설정 시 제안되는 내용 표시` 끄기

## 윈도우 터미널 단축키 설정

- 시작에서 powershell or cmd 중 선호하는 터미널 검색
- 우클릭 "파일 위치 열기"
- 해당 파일에 우클릭->추가옵션표시->바로가기 파일을 두 개를 만들어줍니다.
- 첫번째 바로가기 파일에<br/>`-⇀`우클릭 속성 `-⇀` 바로가기 키를 클릭하고 단축키 Crtl + Alt + T 를 입력합니다.
- 두번째 바로가기 파일에<br/>`-⇀`우클릭 속성 `-⇀` 바로가기 키를 클릭하고 단축키 Crtl + Alt + Shift + T 를 입력합니다.<br/>`-⇀`우클릭 속성 `-⇀` 고급에 관리자 권한으로 실행 체크합니다.
- 파워쉘이 켜지면 우클릭 `-⇀` 속성의 편집옵션 항목에서 Ctrl+Shift+C/V 복사 붙여넣기 항목에 체크해주면 복사 붙여넣기를 쉽게 할 수 있습니다.

## 윈도우 무결성 확인

- 관리자 권한으로 터미널창을 띄워 SFC(System File Checker)의 도움을 받으면 됩니다.
- ```bash
  sfc /scannow
  ```

## 임시 데이터 정리

- `Win + R` 입력으로 실행창 키고 `temp` 입력, 폴더 정리
- `Win + R` 입력으로 실행창 키고 `%temp%` 입력, 폴더 정리

## 프린터 대기열 걸림 문제 해결

- [printspool 재구성](https://support.hp.com/kr-ko/document/c04746618)
