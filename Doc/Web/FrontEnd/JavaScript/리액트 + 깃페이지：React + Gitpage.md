# 리액트 + 깃페이지：React + Gitpage

## VS code Extension

- Auto Rename Tag
- ES7+ React/Redux/React-Native snippets
- ESLint
- Prettier
- vscode-styled-components
- TODO Highlight

## Convention

### Directory Structure

```text

```

## 기본 환경 조성

### Gitpage.io

#### Gitpage.io > 사전준비

- Github 에 계정이 있으셔야 합니다.
- 계정을 생성했거나 이미 계정이 있으시다면, 이제 여러분의 깃허브 계정명 `<GITHUB_ID>` 를 아셔야합니다.<br />
  프로필 화면에서 닉네임 밑에 씌여있으며, 프로필 페이지 주소를 봐도 `https://github.com/『GITHUB_ID』` 형식이므로 확인할 수 있습니다.

#### Gitpage.io > 『GITHUB_ID』.github.io 배포용 프로젝트 생성

- 깃허브에 `『GITHUB_ID』.github.io` 라는 이름으로 프로젝트를 만듭니다.

  - 예를들어 『GITHUB_ID』 가 inte99ral 인 유저는 inte99ral.github.io 라는 이름의 프로젝트를 만들면됩니다. <b>(다른 이름이면 안됩니다!)</b>
  - 이 프로젝트에 올린 index.html 페이지가 그대로 여러분의 페이지가 됩니다.
  - 프로젝트 `『GITHUB_ID』.github.io` 에 index.html 파일을 생성한 뒤에 넣어봅시다.<br />
    Hello, world! 라는 글씨가 한가운데에 적혀있는 페이지 예시 입니다.

    ```html
    <!-- 『GITHUB_ID』.github.io/index.html -->
    <!DOCTYPE html>
    <html>
      <head>
        <title>테스트용 HTML 페이지</title>
        <style>
          body {
            width: 100vw;
            height: 100vh;

            text-align: center;
            line-height: 100vh;
            overflow: hidden;
          }
        </style>
      </head>
      <body>
        <h1>Hello, World!</h1>
      </body>
    </html>
    ```

- 적용되기에 1~2 분의 정도 시간은 걸리지만 인터넷 브라우저를 키고 `https://『GITHUB_ID』.github.io/` 라는 주소로 접속하시면 hello, world! 라는 문구가 띄어진 것을 볼 수 있습니다.

#### Gitpage.io > 『GITHUB_ID』.github.io.dev 개발용 프로젝트 생성

- 깃허브에 `『GITHUB_ID』.github.io.dev` 라는 프로젝트를 만듭니다.
- 이 프로젝트는 개발용으로 쓰일 공간입니다.
- 여기서 개발을 한 뒤, 빌드한 완제품을 `『GITHUB_ID』.github.io` 배포용 프로젝트로 옮깁니다.
- 이렇게 분리를 하는 이유는 수많은 코드, 개발용 에셋들과 배포용 제품이 섞이지 않게 하기 위한 목적과 개발 진행 사항에 배포되어 있는 사이트가 영향을 받게하지 않기 위함입니다.

### npm (Node Package Manager) 환경 구현

#### npm 환경 구현 > node.js 설치

우선 JavaScript 생태계인 node.js 와 npm 이 설치되어 있어야 합니다.

- nvm(node version manager)을 [깃허브 링크](https://github.com/coreybutler/nvm-windows/) 에서 설치하여 node.js 설치 및 버전 관리를 하거나

  - `nvm list available` 명령어로 설치가능한 node.js 들을 볼 수 있습니다.

    ```bash
    nvm list available
    ```

  - `nvm install v<VERSION_NUMBER>` 명령어로 원하는 버전을 설치할 수 있습니다.

    ```bash
    # 예시용 옛날 버전
    nvm install v12.18.2

    # 가장 최신 LTS(장기간 관리 보장) 버전을 설치하기
    nvm install --lts
    ```

  - `nvm ls` 명령어로 설치되어있는 node.js 들을 볼 수 있습니다.

    ```bash
    nvm ls
    ```

  - `nvm use v<VERSION_NUMBER>` 명령어로 해당 버전을 쓸 수 있습니다.

    ```bash
    nvm use v12.18.2
    ```

- node.js 를 [공식 배포 사이트](https://nodejs.org/en) 에서 직접 원하는 버전을 설치하는 방법도 있습니다.

  - 설치 중에 "npm 설치" 체크박스를 꼭 확인해주세요.

- $\color{#FF9922} \footnotesize \textnormal{이 시스템에서 스크립트를 실행할 수 없으므로} \sim \textnormal{파일을 로드할 수 없습니다🚨}$

  - 윈도우즈 powershell 의 실행 정책 보안 때문에 발생한 것 입니다.
  - 파워쉘을 관리자 모드로 실행합니다. (작업표시줄 윈도우로고 우클릭 -> 터미널(관리자))
  - `Get-ExecutionPolicy` 명령어를 입력하여 현재 실행 정책을 확인합니다.
  - 출력값이 Restricted(파일 실행 금지) 이라면 RemoteSigned(인증기관 서명이 된 것 까지는 허용) 로 바꿔주셔야 합니다.
  - `Set-ExecutionPolicy <EXECUTION_POLICY>` 명령어로 바꿔줍시다.

    ```powershell
    Set-ExecutionPolicy RemoteSigned
    ```

- npm 업데이트

  ```bash
  npm install -g npm@latest
  ```

- npm module 업데이트

  ```bash
  # npm 모듈 버전 확인
  npm show <MODULE_NAME> version

  # 특정 모듈 최신 업데이트
  npm update <MODULE_NAME>

  # 특정 모듈 특정 버전 업데이트

  npm install 『MODULE_NAME』@『VERSION_NUMBER』.『VERSION_MINOR_NUMBER』

  # 특정 모듈 특정 버전의 최신 버전 업데이트

  npm install 『MODULE_NAME』@^『VERSION_NUMBER』

  # package.json 모듈 전체 업데이트
  npm install -g npm-check-updates

  # NCU (NPM CHECK UPDATES) 도구로 최신 버전 전체 확인
  ncu

  # NCU (NPM CHECK UPDATES) 도구로 최신 버전으로 전체 업데이트
  ncu -u

  ```

- $\color{#FF9922} \footnotesize \textnormal{ERESOLVE could not resolve 에러 🚨}$

  &nbsp; npm 7 버전 이후부터는 패키지간의 의존성을 체크하는 peerDependencies를 자동 설치하는 기능 때문이 생깁니다. peer Dependencies를 자동으로 설치할 때, 이미 설치되어있는 의존성(direct dependencies of the root project)과 동일하지만 버전이 다른 peerDependencies가 존재하면 충돌이 일어나서 위와 같은 에러가 발생합니다.

  &nbsp; 이 경우엔 `npm install <MODULE_NAME> --force` install 명령어에 --force 옵션으로 충돌이 일어난 peerDependencies의 설치를 강행합니다.

  &nbsp; 위 방법으로 해결이 안되었을 경우엔 `npm install <MODULE_NAME> --legacy-peer-deps` 명령어를 통하여 npm 4~6버전 처럼 peerDependencies를 자동으로 설치하지 않도록 설정합니다.

- $\color{#FF9922} \footnotesize \textnormal{Try creating one first with: npm i --package-lock-only 🚨}$

  &nbsp; package-lock.json 파일이 필요한 상황에 해당 파일이 없을 경우 나오는 에러 경보문 입니다.

  &nbsp; `npm i --package-lock-only` 명령어는 package-lock.json 파일만 생성하거나 업데이트하며, npm install 처럼 실제로 패키지를 설치하거나 수정하지 않습니다.

### react & typescript

#### react & typescript > 설치

- `<GITHUB_ID>`.github.io.dev 개발용 프로젝트에서 react 를 설치할 것 입니다.
- 리액트 설치 명령 (타입스크립트 기반) 을 입력해주세요

  ```bash
  npx create-react-app 『PROJECT_NAME』 --template typescript
  ```

- 잘 설치가 되었는지 확인하기 위해서 `npm start` 명령어를 실행해봅시다.

  ```bash
  npm start
  ```

##### react & typescript > 설치 > $\color{#FF9922} \footnotesize \textnormal{npm error code ERESOLVE 🚨}$

&nbsp; 가끔 다음의 메세지 이후 create-react-app 설치가 오류를 만드는 경우가 있습니다.

```bash
Installing template dependencies using npm...
npm error code ERESOLVE
npm error ERESOLVE unable to resolve dependency tree
```

&nbsp; 이는 npm 7 이상에서 피어 의존성(peer dependencies) 처리 방식이 변경되어 이전 버전과 호환성 문제가 발생하는 부분에서 발생합니다.

&nbsp; 이 경우 프로젝트를 삭제해주시고 다음의 세 가지 방법중 하나로 진행해주세요.

1. legacy-peer-deps 옵션 활성화

- npm 7 의 피어 의존성 출동을 무시하고 설치를 진행합니다.
- 이 설정을 사용하면 npm 7 이전 버전의 알고리즘을 사용하여 의존성 문제를 해결합니다.

```bash
npm config set legacy-peer-deps true
```

2. npm 캐시 정리 후, 프로젝트 설치 재시도

```bash
npm cache clean --force
```

3. npm 의존성 무시 옵션을 사용합니다.

```bash
npx create-react-app 『PROJECT_NAME』 --use-npm --legacy-peer-deps
```

4. npm 강제 설치 옵션을 사용합니다.

```bash
npx create-react-app 『PROJECT_NAME』 --use-npm --force
```

5. create-react-app 대신 Vite 를 대신 사용합니다.

```bash
npm create vite@latest 『PROJECT_NAME』 -- --template react
```

##### react & typescript > 설치 > $\color{#FF9922} \footnotesize \textnormal{모듈 'react'에 대한 선언 파일을 찾을 수 없습니다. 🚨}$

- 가끔 typescript 와 eslint, react 간에 의존성 및 호환성 문제로 설치가 제대로 진행되지 않을 때가 있습니다.
- 별도로 react에 대한 typescript type 설정을 설치해주세요

```bash
npm install --save-dev @types/react @types/react-dom
```

##### react & typescript > 설치 > $\color{#FF9922} \footnotesize \textnormal{package.json 확인 🚨}$

&nbsp; warning 이 뜨고 npm audit (npm 에서 코드 취약점을 파악하는 명령어) 를 쳤을 시에 nth-check 가 나온다면 걱정하지 하세요. npm 으로 패키지를 다운로드 받고 있다면 원래 나와야 하는 게 맞습니다. 문제의 원인은 package.json 안에 있는 react 스크립트 패키지 `"react-scripts"` 입니다. 이 오류에서는 리액트 자체가 문제인 상황입니다.

&nbsp; `npm audit fix --force` 로는 해결할 수 없습니다. npm 은 해당 코드로 Node.js 앱을 돌릴 때 생기는 취약점을 경고하고 수정하는 기능(npm audit)을 가지고 있습니다. 하지만 CRA(create-react-app)는 정적 빌드 툴이고, Node.js와 같은 방식으로 작동하지 않습니다. 때문에 npm audit은 CRA의 몇몇 부분을 취약점으로 오탐지하곤 합니다.

&nbsp; 따라서 npm audit 에게 `"react-scripts"` 패키지는 완성품에 포함되어서 Node.js 위에서 구동하는 용도가 아니라 개발용으로 쓰이는 패키지라는 것을 명시해준다면 문제를 해결할 수 있습니다.

&nbsp; 다음과 같이 package.json 안의 "dependencies" 안에 있는 "react-scripts" 을 "devDependencies" 로 이동시켜서 개발-의존성 패키지 임을 명시해주세요.

```json
{
  // ...

  "dependencies": {
    // ...
    // "react-scripts": "^5.0.1" <-- 삭제해주세요
    // ...
  },
  "devDependencies": {
    // ...
    "react-scripts": "^5.0.1"
    // ...
  }

  // ...
}
```

&nbsp; 그 후, npm audit 대신 (구버전)`npm audit --production` 또는 (신버전)`npm audit --omit=dev` 을 사용하면 됩니다.

- `npm audit --omit=dev` 과 `npm audit --production`은 실질적으로 동일한 기능을 수행합니다. 두 명령어 모두 개발 의존성(devDependencies)을 제외하고 프로덕션 의존성만을 대상으로 보안 감사를 실행합니다. 최신 버전에서는 의존성에 대하여 더 유연하게 접근하기 위하여 --omit 명령어 쪽을 권장합니다. 이 경우엔 다른 종류의 의존성도 --omit=optional 같이 통일성 있는 명령어로 배제할 수 있기 때문입니다.

&nbsp; npm이 node_modules 트리나 package-lock.json 의 수정시엔 의존성 라이브러리 버전을 상세하게 고정한 정보인 package-lock.json 이 자동생성되나 가끔 수정이 안될때가 있습니다. package-lock.json이 우선시 되므로 이 경우 package-lock.json을 삭제하거나 직접 수정해주세요

##### react & typescript > 설치 > $\color{#FF9922} \footnotesize \textnormal{nth-check 🚨}$

&nbsp; react-script 가 devDependencies 로 이동했어도 이미 기존 의존성에 연결되어있는 nth-check 가 여전히 오류을 일으킬 경우가 있습니다.

&nbsp; -D 플래그는 --save-dev의 축약형으로, 이 패키지가 개발 과정에서만 필요하고 프로덕션 환경에서는 필요하지 않음을 나타냅니다.

&nbsp; 이 -D 명령어로 devDependencies 로 nth-check 의존성 설정을 변경해주세요.

```bash
npm install -D npm-force-resolutions
```

##### react & typescript > 설치 > $\color{#FF9922} \footnotesize \textnormal{Error: error:0308010C:digital envelope routines::unsupported 🚨}$

&nbsp; 이 오류는 주로 Node.js 버전과 React 프로젝트의 react-scripts 버전 간의 호환성 문제로 발생합니다.

&nbsp; 글 작성 시점 기준으로 react-scripts 최신 버전은 5.0.1 입니다. 적절한 버전으로 설치해주세요.

```bash
npm install --save react-scripts@5.0.1 --force
```

#### react & typescript > 구조정리

&nbsp; 개인적으로 선호하는 구조를 맞추기 위해서 구조를 변경합니다. atomic design 등 다른 구조를 쓰실 분들은 이 단락은 전부 무시하셔도 좋습니다.

&nbsp; 이 구조의 목표는 파일의 용량 효율을 포기하는 대신 정크 파일의 생성을 최소로 하는 것입니다.

##### 1단계. css 를 통합하지 않습니다.

&nbsp; 상위의 css style 양식을 받아오지 않습니다. 모든 컴포넌트 index.tsx 마다 본인 만의 style.tsx 를 가지고 있도록 구조를 유지합니다.

&nbsp; 이를 통해서 더미파일, 삭제되거나 변경된 컴포넌트의 style 정보가 남아있지 않도록 할 수 있습니다.

- src/component/ 빈 폴더를 생성합니다.
  - 앞으로 하위 컴포넌트를 만들 경우 이 곳에 정리합니다.
- theme.css 파일을 생성합니다.
- index.css 와 App.css 파일의 내용을 theme.css 에 복사합니다.

  ```css
  /* # front-end\src\theme.css */

  /* ## index.css ============================================================== */

  body {
    margin: 0;
    font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', 'Roboto', 'Oxygen', 'Ubuntu',
      'Cantarell', 'Fira Sans', 'Droid Sans', 'Helvetica Neue', sans-serif;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
  }

  code {
    font-family: source-code-pro, Menlo, Monaco, Consolas, 'Courier New', monospace;
  }

  /* ## App.css ================================================================ */

  .App {
    text-align: center;
  }

  .App-logo {
    height: 40vmin;
    pointer-events: none;
  }

  @media (prefers-reduced-motion: no-preference) {
    .App-logo {
      animation: App-logo-spin infinite 20s linear;
    }
  }

  .App-header {
    background-color: #282c34;
    min-height: 100vh;
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    font-size: calc(10px + 2vmin);
    color: white;
  }

  .App-link {
    color: #61dafb;
  }

  @keyframes App-logo-spin {
    from {
      transform: rotate(0deg);
    }
    to {
      transform: rotate(360deg);
    }
  }
  ```

- index.tsx 파일에 theme.css 를 임포트합니다.

  ```typescript
  // # API & Library ==================================================
  import React from 'react';
  import ReactDOM from 'react-dom/client';
  import reportWebVitals from './reportWebVitals';

  // # Style ==========================================================
  import './theme.css';

  // # Component ======================================================
  import App from './App';

  const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);
  root.render(
    <React.StrictMode>
      <App />
    </React.StrictMode>,
  );

  reportWebVitals();
  ```

- index.css 와 App.css 파일을 삭제합니다.

##### 2단계. asset 를 따로 정리합니다.

&nbsp; 상위의 asset 을 가져오지 않습니다. 모든 컴포넌트에서 사용되는 에셋은 각각 자신 기준 옆에 있는 asset 폴더 내에서 가져옵니다.

&nbsp; 이를 통해서 더미파일, 삭제되거나 변경된 컴포넌트의 asset들이 남아있지 않도록 할 수 있습니다.

- asset 폴더를 생성합니다.
- logo.svg 를 asset 폴더로 옮겨줍니다.
- logo.svg 를 사용하고 있는 App.tsx 의 경로를 수정해줍시다.

  ```typescript
  // # API & Library ==================================================
  import React from 'react';

  // # Asset ==========================================================
  // import logo from "./logo.svg";
  import logo from './asset/logo.svg';

  function App() {
    return (
      <div className="App">
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <p>
            Edit <code>src/App.tsx</code> and save to reload.
          </p>
          <a
            className="App-link"
            href="https://reactjs.org"
            target="_blank"
            rel="noopener noreferrer"
          >
            Learn React
          </a>
        </header>
      </div>
    );
  }

  export default App;
  ```

##### 3단계. api 와 api 관련 함수는 폴더에 묶어서 정리합니다.

&nbsp; api 같이 외부 패키지 및 외부 함수를 참조하는 코드들은 최상단 src/api 폴더 내에서 관리하는 구조를 가능한 한 유지합니다.

&nbsp; 더 이상 사용되지 않는 외부 참조를 api 폴더에서만 제거하는 것으로 모든 영역에서 제거할 수 있습니다.

- src/api 폴더를 만들어주세요.
- 예시를 위하여 webVitals 진단기를 api 폴더 안에 정리하겠습니다.
- src/api/webVitals 폴더를 만들어주세요.
- src/api/webVitals 폴더 내부에 index.ts 를 생성합니다.

  ```typescript
  // # src/api/webVitals/index.ts

  // ## Import Declaration =====================================================

  // ### API & Library:

  import { ReportHandler } from 'web-vitals';

  // ## Function ===============================================================

  // ### reportWebVitals
  /**
   * @description
   *
   * If you want to start measuring performance in your app, pass a function
   *
   * to log results (for example: reportWebVitals(console.log)) or send to an analytics endpoint.
   *
   * @see Learn more: https://bit.ly/CRA-vitals
   */
  export const reportWebVitals = (onPerfEntry?: ReportHandler) => {
    if (onPerfEntry && onPerfEntry instanceof Function) {
      import('web-vitals').then(({ getCLS, getFID, getFCP, getLCP, getTTFB }) => {
        getCLS(onPerfEntry);
        getFID(onPerfEntry);
        getFCP(onPerfEntry);
        getLCP(onPerfEntry);
        getTTFB(onPerfEntry);
      });
    }
  };
  ```

- src/index.tsx 의 경로를 수정해줍시다.

  ```typescript
  // # API & Library ==================================================

  import React from 'react';
  import ReactDOM from 'react-dom/client';
  // import reportWebVitals from "./reportWebVitals"; <--
  import { reportWebVitals } from './api/webVitals';

  // # Style ==========================================================

  import './theme.css';

  // # Component ======================================================

  import App from './App';

  const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);
  root.render(
    <React.StrictMode>
      <App />
    </React.StrictMode>,
  );

  reportWebVitals();
  ```

- src/reportWebVitals.ts 파일을 삭제합니다.

##### 4단계. Jest와 Testing Library 는 사용빈도가 낮기에 제거합니다.

https://github.com/testing-library/jest-dom

&nbsp; 각 함수의 리턴값과 컴포넌트 렌더링을 시범용으로 구동해주는 패키지입니다. 다만, 사용자에 따라서 사용빈도가 극단적으로 적습니다. 저는 잘 안쓰기 때문에 제거하겠습니다.

- src/ 폴더 내에서 <b>setupTests.ts</b> 와 <b>App.test.tsx</b> 파일을 삭제합니다.
- npm search jest 명령어를 통해서 검색
- npm uninstall jest
- 모든 흔적을 지우고 싶으시면 package.json 에서 ctrl + f 로 검색하여 jest 와 testing-library 를 제거한 뒤에 package-lock.json 을 삭제하고 `npm i --package-lock-only`->`npm install` 명령을 실행합니다.
- npm cache verify
  - 꼬인 부분을 체크 및 해결하는 명령어입니다. cache 폴더의 내용을 확인하고, 가비지 데이터들을 수집하여 삭제하고 무결성을 확인합니다.
- npm cache clean --force
  - npm의 cache를 모조리 삭제하는 명령어입니다.

##### 정리

위 단계를 거친 뒤엔 src 폴더의 구조가 다음과 같이 정리됩니다.

```txt
src/
├─ api/ (외부 라이브러리 및 외부 참조함수들)
├─ asset/ (이미지, 음악등 에셋들)
├─ component/ (하위 자식 컴포넌트들. 아직 설명안했습니다.)
├─ App.tsx (react SPA 구현의 최상단)
├─ index.tsx (react 컴포넌트 토대의 최상단)
├─ react-app-env.d.ts (환경변수 타입 파일. 아직 설명안했습니다.)
└─ theme.css (전체 테마로 적용되는 스타일)
```

#### react & typescript > 환경설정

- tsconfig.json 가 없다면 tsconfig.json 를 만들어주세요. compilerOptions 안에 baseUrl 을 src로 설정해주세요

  ```json
  // # front-end\tsconfig.json
  {
    "compilerOptions": {
      "baseUrl": "src", // <-- 추가 및 확인
      "target": "es5",
      "lib": ["dom", "dom.iterable", "esnext"],
      "allowJs": true,
      "skipLibCheck": true,
      "esModuleInterop": true,
      "allowSyntheticDefaultImports": true,
      "strict": true,
      "forceConsistentCasingInFileNames": true,
      "noFallthroughCasesInSwitch": true,
      "module": "esnext",
      "moduleResolution": "node",
      "resolveJsonModule": true,
      "isolatedModules": true,
      "noEmit": true,
      "jsx": "react-jsx"
    },
    "include": ["src"] // <-- 확인
  }
  ```

  - 베이스 주소가 src로 설정되었기 때문에 앞으로 import 할 때, 뒤에 /../../../ 없이 주소를 적을 경우 src 부터 시작합니다.

### eslint & prettier

#### eslint & prettier > 패키지 설치

- 앞서서 eslint & prettier 란?

  - eslint 는 현재 개발자들에게 매우 인기있는 JavaScript linter이다, lint 란 소스 코드를 사전 검사하여 버그, 스타일 오류, 의심스러운 구조체들을 파악하여 로직 에러를 사전에 막아주는 도구이다.
  - prettier는 대다수가 쓰는 code formatter로 띄어쓰기, 개행 줄, 따옴표 등의 코드 생김새를 체크하고 강제로 지키도록 만들어 팀 간에 약속한 코드 컨벤션을 유지시켜준다 . eslint 의 스타일 체크보다 훨씬 기능이 다양하며, 자동으로 code format 를 맞춰 변화시켜주기 때문에 매우 편리하다. 한 명이 개발한 것 처럼 이쁜 코드를 만들어주는 도구이다.

- 빌드 시가 아니라 IDE 에서 개발 시 실시간 체크하기 위해서 vscode 의 extension `eslint` 와 `prettier` 를 설치해야 합니다.
- 프로젝트에 필요한 패키지들을 내려받는다. 필요한 것은 다음과 같다.

  - eslint
  - prettier
  - eslint-config-prettier
    - eslint에서 prettier와 충돌할 수 있는 rule을 꺼버린다.
    - 코드 오류만로 eslint, 코드 포맷팅만 prettier로 잡을 수 있다.
  - eslint-plugin-prettier
    - prettier를 eslint의 rules로써 동작하게 한다.
    - 코드 포맷팅 문제가 사전에 오류 메세지로 출력되서 파악하기 쉬워진다.
    - 단, 오류 메시지가 지나치게 많아져서 느려진다.

- 위에서 언급한 패키지들을 내려 받는 명령어

  ```bash
  npm install eslint prettier eslint-config-prettier eslint-plugin-prettier --save-dev
  ```

#### eslint & prettier > 환경 설정

- prettier 세팅

  - vscode 설정에서 default editor 를 prettier 로 바꿔줄 것
  - 편하게 쓰기 위해서 editor: format on save 를 true 값으로 해주면 저장 시에 자동으로 코드를 알맞게 바꿔준다.
  - 특수 법칙을 적용할 디렉토리 front-end/ 폴더 안에 `.prettierrc.json` 파일을 생성하고 내부에 법칙을 작성한다.

    ```json
    {
      "singleQuote": true,
      "semi": true,
      "useTabs": false,
      "tabWidth": 2,
      "trailingComma": "all",
      "printWidth": 100,
      "arrowParens": "always",
      "endOfLine": "auto"
    }
    ```

  <br />

- eslint 세팅

  - npx eslint --init 명령어를 통해 빠른 초기 설정이 가능하다.
  - 예시 프로젝트에서는 react 와 typescript 를 사용한다.
  - javascript module 과 commonjs 중 무엇을 쓰는 지 질문하는데 module 이 더 최신 방식이다. 뭐가 뭔지 모르겠다면 본인이 타 파일의 코드를 불러오는 방법을 보면 안다.

    - commonjs : 가져올 때는 `require` 로, 내보낼때는 `module.exports` 를 쓰는 구 방법

    - javascript module : `import` 와 `export` 을 사용하여 EMCA Script modules(또는 ES modules)를 가져오고 내보내는 방법. JS 코드 패키징의 공식 표준 형식이며 대부분의 최신 웹 브라우저는 기본적으로 모듈을 지원한다.

  - 설정하고 나면, 추가적으로 내려받아야할 설정들까지 자동으로 받아준다. 그 후, .eslintrc 파일이 생성되었을 것이다. 참고로 이 설정파일의 형식을 먼저 묻는데 js 로 선택할 경우, 최상위 디렉토리가 아니면 인식이 안될 수 있다. json 이 무난하다.

  - .eslintrc.json 에 프리티어 설정을 적용한다.

    ```json
    {
      // 상위 폴더에 적용 유뮤.
      "root": false,

      // env 환경변수 적용
      "env": {
        "browser": true,
        "es2021": true
      },

      // 추가한 plugin에서 사용할 규칙을 설정.
      "extends": [
        "eslint:recommended",
        "plugin:react/recommended",
        "plugin:@typescript-eslint/recommended",
        "plugin:prettier/recommended"
      ],

      "overrides": [],

      // 구문 분석을 위해 사용하는 parser 설정
      "parser": "@typescript-eslint/parser",

      // 구문 분석할 언어 옵션 설정
      "parserOptions": {
        // 프로젝트 tsconfig 주소를 못잡을때 명시
        "project": ["tsconfig.json"],
        "ecmaVersion": "latest",
        "sourceType": "module"
      },

      "plugins": ["react", "@typescript-eslint"],

      // 프로젝트에 사용할 규칙을 설정.
      // 규칙에 추가 옵션이 있는 경우 배열로 설정 가능.
      // 참고 : https://eslint.org/docs/latest/rules/
      // off 또는 0 사용시 규칙을 사용하지 않음.
      // warn 또는 1 사용시 규칙을 경고로 사용.
      // error 또는 2 사용시 규칙을 오류로 사용.
      "rules": {
        "prettier/prettier": ["error"], // * prettier 경고도 에러로 취급
        "@typescript-eslint/no-empty-function": ["error", { "allow": [] }] // * 의존성 오류 제어
      },

      // .로 시작하는 설정파일이나 node_modules, 외의 무시할 파일 영역
      "ignorePatterns": ["build", "dist", "public"],

      // 리액트 버전 자동탐지
      "settings": {
        "react": {
          "version": "detect"
        }
      }
    }
    ```

##### eslint & prettier > 환경 설정 > $\color{#FF9922} \footnotesize \textnormal{Error while loading rule '@typescript-eslint/no-unused-expressions': Cannot read properties of undefined (reading 'allowShortCircuit') 🚨}$

&nbsp; 해당 에러는 `no-unused-expressions` 사용되지 않은 변수가 생기지 않도록 막습니다.

&nbsp; 문제는 코드의 무결성을 지키는 ESLint와 타입스크립트 플러그인 @typescript-eslint 의 버전의 불일치가 해당 에러를 유발한다는 점 입니다.

&nbsp; 후에 해결될 문제로 보이지만 현재까지의 해결방안은 `npm install --save-dev eslint@9.14.0` 명령어를 통하여 ESLint 를 9.14 이하의 버전으로 사용하는 것 입니다.

&nbsp; 또는 `no-unused-expressions` 규칙의 경고 단계를 원천적으로 차단하는 수준에서, 단순 경고 급으로 낮출 수도 있습니다. 다음과 같이 `.eslintrc.json` 파일의 rules 에 해당 조건을 수정해주세요.

```json
{
  // ...

  // 프로젝트에 사용할 규칙을 설정.
  // 규칙에 추가 옵션이 있는 경우 배열로 설정 가능.
  // 참고 : https://eslint.org/docs/latest/rules/
  // off 또는 0 사용시 규칙을 사용하지 않음.
  // warn 또는 1 사용시 규칙을 경고로 사용.
  // error 또는 2 사용시 규칙을 오류로 사용.
  "rules": {
    "no-unused-vars": "warn"
  }

  // ...
}
```

##### eslint & prettier > 환경 설정 > $\color{#FF9922} \footnotesize \textnormal{ERROR in [eslint] Failed to load plugin '@typescript-eslint' declared in '.eslintrc.json' 🚨}$

- 이 오류는 ESLint와 @typescript-eslint 플러그인 또는 패키지 의존성 사이에서 생긴 버전들의 불일치로 인해 발생합니다. 원인과 해결 방안은 다음과 같습니다:

다음 절차로 해결할 수 있습니다.

1. 패키지 업데이트

```bash
npm update eslint @typescript-eslint/eslint-plugin @typescript-eslint/parser
```

2. ESLint를 특정 버전으로 고정시켜 봅니다.

```bash
npm install eslint@7.32.0
```

3. 의존성 재설치

   - node_modules 폴더를 삭제하고 패키지를 다시 설치합니다.

```bash
rm -rf node_modules
npm install
```

4. TypeScript 설치 확인

   - 프로젝트에 TypeScript가 제대로 설치되어 있는지 확인합니다.

```bash
npm install typescript
```

5. Node.js 버전 확인

- 프로젝트에 적합한 Node.js 버전을 사용하고 있는지 확인해주세요.

6. ESLint 설정 파일 검토

- .eslintrc 파일의 설정을 검토하고, 필요한 플러그인과 파서가 올바르게 선언되어 있는지 확인합니다

7. package.json의 ESLint config 확장 법칙 삭제

```json
// ...

  "eslintConfig": {
    "extends": [
      "react-app" // <-- 삭제하기
    ]
  },

// ...
```

8. Node.js 버전 확인 및 업데이트

```bash
node -v
npm -v
```

9. npm 캐시 정리

```bash
npm cache clean --force
```

10. 프로젝트 재구축

- 심각하게 꼬였다면 배를 버리는 것 또한 방법입니다. 다른 폴더에 npm project 를 다시 구축한 뒤에 폴더만 옮겨주세요.

### env 환경 변수 설정

- typescript 에서 환경변수의 타입을 미리 명시하여 귀찮은 타입 처리를 피할 수 있다

  - 프로젝트 최상단(src 폴더 바로 외부)에 `.env` 생성 후, 환경변수를 등록합니다. <br />
    변수 이름이 `REACT_APP_` 으로 시작해야 인식되는 것을 주의하세요. <br />

  - 현 개발 빌드의 버젼을 string 타입 환경변수로 등록하여 사용하는 예시는 다음과 같습니다.

    - `.env` 파일에 환경변수 값 기입

      ```txt
      REACT_APP_VERSION = v0.0.1
      REACT_APP_NUMBER = 1
      ```

    <br />

    - `react-app-env.d.ts` 에 환경변수의 타입 명시

      ```typescript
      /// <reference types="react-scripts" />

      declare namespace NodeJS {
        interface ProcessEnv {
          NODE_ENV: 'development' | 'production';
          REACT_APP_VERSION: string;
          REACT_APP_NUMBER: number;
        }
      }
      ```

    <br />

    - process.env.REACT_APP_VERSION 라는 이름으로 환경변수 사용이 가능합니다.

      - npm start 또는 배포된 웹페이지에 접속하면 reportWebVitals 함수가 실행되면서 환경변수 .env 의 값 v0.0.1 를 콘솔창에 띄우도록 해봅시다.

        ```typescript
        // # front-end/src/api/webVitals/index.ts

        // ...

        export const reportWebVitals = (onPerfEntry?: ReportHandler) => {
          (async () => console.log(`front-end ${Number(process.env.REACT_APP_NUMBER) * 100}`))(); // <-- 추가된 코드

          if (onPerfEntry && onPerfEntry instanceof Function) {
            import('web-vitals').then(({ getCLS, getFID, getFCP, getLCP, getTTFB }) => {
              getCLS(onPerfEntry);
              getFID(onPerfEntry);
              getFCP(onPerfEntry);
              getLCP(onPerfEntry);
              getTTFB(onPerfEntry);
            });
          }
        };
        ```

      - F12 를 눌러 <b>콘솔</b> 창을 띄우시면 v0.0.1 버전이 출력되어 있을 것 입니다.

- $\color{#FF9922} \footnotesize \textnormal{주의사항 .env 의 값은 빌드 시점에 고정됩니다. 🚨}$

  - .env 환경변수 값은 npm start 이나 npm run build 를 한 시점에서 결정됩니다.
  - 이미 빌드를 한 이후에는 .env 값을 수정하고 새로고침을 하더라도 변하지 않습니다.
  - ctrl + c 로 테스트를 끄고 다시 키거나 새로 빌드해서 배포하기 전까지는 수정된 환경변수 값이 들어가지 못합니다.

<hr />

### React index.tsx 구조와 React.StrictMode 확인

- [공식문서](https://bit.ly/CRA-vitals)
- React StrictMode 는 리액트에서 제공하는 검사도구입니다. <br/>
  개발모드 시 디버그를 시행하면서 이상한 생명주기를 가진 컴포넌트나 권장하지 않는 부분을 점검해줍니다.

- `index.tsx` 파일 최상단 인덱스 파일은 다음과 같이 `<React.StrictMode>` 태그로 감싸져있습니다.

  ```typescript
  // # src/index.tsx

  import React from 'react';
  import ReactDOM from 'react-dom/client';
  import { reportWebVitals } from './api/webVitals';

  import './theme.css';

  import App from './App';

  const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);
  root.render(
    <React.StrictMode>
      <App />
    </React.StrictMode>,
  );

  reportWebVitals(console.log);
  ```

- react의 도구들은 구조상 도구가 감지할 <b>컴포넌트 영역</b>을 태그로 묶어주어야 합니다. 다음은 감시도구, 라우터, 리코일이라는 도구가 `<React.StrictMode>` `</BrowserRouter>` `<RecoilRoot>` 라는 태그를 통해 감지 영역을 지정해준 모습입니다.

  ```typescript
  // # src/index.tsx
  // ## API & Library
  import React from 'react';
  import ReactDOM from 'react-dom/client';
  import { BrowserRouter } from 'react-router-dom';
  import { RecoilRoot } from 'recoil';
  import { reportWebVitals } from 'api/webVitals';

  // ## Components
  import App from './App';

  const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);

  root.render(
    <React.StrictMode>
      <BrowserRouter>
        <RecoilRoot>
          <App />
        </RecoilRoot>
      </BrowserRouter>
    </React.StrictMode>,
  );

  reportWebVitals(console.log);
  ```

  이런 구조에서 리액트의 검사도구가 `<App/>` 내의 컴포넌트들을 검사할 수 있습니다.

- $\color{#FF9922} \footnotesize \textnormal{Double Invoke! useEffect() 함수가 두 번 실행됩니다 🚨}$

  &nbsp; 아직 useEffect 함수 설명을 하진 않았지만 미리 짚고 가겠습니다.

  &nbsp; React StrictMode 검사도구가 전체 점검을 하면서 invoke 된 함수가 실행됩니다. 따라서 점검 때 한 번, 실행 시 한 번, 이렇게 useEffect 함수가 두 번 실행되며 로그도 두 번 씩 뜹니다.

  &nbsp; 불필요하다 생각되거나 double invoke 상황을 피하고 싶다면 `<React.StrictMode>` 태그를 제거해도 됩니다.

<hr />

### 백지화 및 홈페이지 디자인 시작

&nbsp; 지금까지는 react 가 제공하는 기본 페이지 디자인(파란색 리액트 로고가 가운데에 회전하는 페이지) 을 유지하면서 전체적인 구조를 조정하였습니다.

&nbsp; 이제 본격적인 응용과 실행예제를 위하여 필요없는 부분을 전부 삭제하고 빈 페이지로 만들겠습니다.

#### 1단계. App.tsx 정리

- 필요없는 로고와 내용물들은 삭제합니다.
- src/asset/logo.svg 삭제
- App.tsx 를 백지화 합니다. 이제 div 사이에 작성한 내용이 페이지가 됩니다. // 주석처리 된 부분은 코드가 길어졌을 때, 눈에 잘보이도록 정리하는 용도 입니다. 아무런 의미가 없습니다.

  ```typescript
  // # src/App.tsx

  import React from 'react';

  const App = () => {
    return <div className="App"></div>;
  };

  export default App;
  ```

#### 2단계. theme.css 정리

- 모든 내용을 삭제합니다.
- 자주 쓰이는 설정을 추가해줍니다.

  ```css
  * {
    <!-- 포지션은 부모 상속을 원칙으로 합니다. -->
    position: relative;

    <!-- 테두리 선 두께가 객체 밖으로 나가지 않습니다. -->
    box-sizing: border-box;

    <!-- 객체 속에 여유 간격을 두지 마세요. ▣ -->
    padding: 0;

    <!-- 객체들 사이에 여유 간격을 두지 마세요. ■ ■ -->
    margin: 0;

    <!-- z축 기준값을 1000으로 하겠습니다. -->
    z-index: 1000;

    <!-- 글씨를 자동으로 꾸미지 말아주세요. -->
    text-decoration: none;
  }
  ```

#### 3단계. Hello, world!

- 여기까지 잘 따라오셨다면 처음에 HTML 로 만들었던 Hello, world! 를 다시 만들어봅시다.
- App.tsx 에 페이지를 작성합니다.

  ```typescript
  // # src/App.tsx
  // ## API & Library ==================================================

  import React from 'react';

  // ## Asset ==========================================================
  // ## Style ==========================================================
  // ## Component ======================================================

  const App = () => {
    // ## Hook ===========================================================
    // ## Method =========================================================
    // ## Return =========================================================

    return (
      <div className="app">
        <h1>Hello, world!</h1> // <--
        <h3>front-end : {process.env.REACT_APP_VERSION}</h3> // <--
      </div>
    );
  };

  export default App;
  ```

- theme.css 에서 글씨를 정가운데로 맞춰줍시다.

  ```css
  * {
    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    z-index: 1000;
    text-decoration: none;
  }

  .app {
    width: 100vw;
    height: 100vh;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
  }
  ```

- `npm start` 로 확인해보세요.

#### 4단계. Hello, world! + 자식 컴포넌트

- 자식 컴포넌트를 만들어서 react 구조에 익숙해져봅시다
- component/ 폴더 안에 HelloPage/ 폴더를 만듭니다.
- src/component/HelloPage/index.tsx
- HelloPage/ 폴더 내부에 index.tsx 파일을 만들고 다음과 같이 작성합니다.

  ```typescript
  // # src/component/HelloPage

  import React from 'react';

  export const HelloPage = () => {
    return (
      <center>
        <h1>Hello, world!</h1>
        <h3>front-end : {process.env.REACT_APP_VERSION}</h3>
      </center>
    );
  };
  ```

- App.tsx 를 다음과 같이 수정해주세요

  ```typescript
  // # src/App.tsx
  // ## API & Library ==================================================

  import React from 'react';

  // ## Asset ==========================================================
  // ## Style ==========================================================
  // ## Component ======================================================

  import { HelloPage } from 'component/HelloPage'; // <--

  const App = () => {
    // ## Hook ===========================================================
    // ## Method =========================================================
    // ## Return =========================================================

    return (
      <div className="app">
        <HelloPage></HelloPage> // <--

        // * <HelloPage /> 처럼 닫는 부분 없이 단일 태그로 써도 됩니다.
      </div>
    );
  };

  export default App;
  ```

- index 파일은 디폴트 값으로 취급됩니다. 덕분에 폴더 경로만 적어줘도 연결됩니다.
- 이제 페이지 전체에 해당하는 App.tsx 를 수정하지 않아도 작은 범위에서 내부의 자식 컴포넌트만 수정해주면 디자인과 글씨를 바꿀 수 있습니다.
- `<HelloPage></HelloPage>` 를 닫는 부분 없이 단일 태그로 `<HelloPage />` 처럼 쓸 수도 있습니다.
- `npm start` 를 통해서 결과물을 확인해보세요.

#### 5단계. Hello, world! + 테마와 폰트

- 페이지 전체에 사용될 글꼴이나 바탕색을 수정해봅시다.
- 예시용으로 저는 [윤디자인](https://www.yoondesign-m.com/719) 사이트에서 폰트 파일 `koverwatch.ttf` 을 다운로드 받겠습니다.
- src/asset/ 폴더 안에 font/ 폴더를 만든 뒤에 그 안에 폰트 파일을 넣어주세요.
- src/theme.css 파일에서 font 를 적용해주세요.

  ```css
  /* # src/theme.css */

  /* ## font =================================================== */

  @font-face {
    font-family: Koverwatch; /* <-- */
    src: url(asset/font/koverwatch.ttf); /* <-- */
  }

  /* ## style ================================================== */

  * {
    font-family: Koverwatch; /* <-- */
    font-size: 64px; /* <-- */

    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    z-index: 1000;
    text-decoration: none;
  }

  .app {
    width: 100vw;
    height: 100vh;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
  }
  ```

- `npm start` 를 통해서 결과물을 확인해보세요.

<hr />

#### 6단계. Hello, world! + 테마 환경변수

- 페이지 전체에 사용되는 색상등의 변수들을 지정해봅시다.
- css 에서 `var(<VARIABLE_NAME>)` 방식으로 `<VARIABLE_NAME>` 변수를 사용할 수 있습니다. `<VARIABLE_NAME>` 변수명은 `--` 로 시작하는 것이 원칙입니다.
- 예시로 라이트 모드 색상과, 다크 모드 색상을 분리하려면 다음과 같이 전체에 통용되는 색상을 바꿔주어야 합니다.

  ```css
  /* # src/theme.css */

  /* ## font =================================================== */

  @font-face {
    font-family: Koverwatch;
    src: url(asset/font/koverwatch.ttf);
  }

  /* ## Variable =============================================== */

  .light {
    --color-main: #ffffff; /* <-- */
    --color-reverse: #000000; /* <-- */
  }

  .dark {
    --color-main: #353839; /* <-- */
    --color-reverse: #ffffff; /* <-- */
  }

  /* ## style ================================================== */

  * {
    font-family: Koverwatch;
    font-size: 64px;

    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    z-index: 1000;
    text-decoration: none;
  }

  .app {
    width: 100vw;
    height: 100vh;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;

    color: var(--color-reverse); /* <-- */
    background-color: var(--color-main); /* <-- */
  }
  ```

- dark 또는 light 라는 클래스 이름에 따라 --color-reverse, --color-main 변수의 값이 달라지면서 색이 달라집니다.
- 이제 App.tsx 가 isDark 라는 값에 의하여 dark 모드인지 light 모드인지 결정하도록 다음과 같이 작성해주세요.

  ```typescript
  // # src/App.tsx
  // ## API & Library ==================================================

  import React from 'react';

  // ## Asset ==========================================================
  // ## Style ==========================================================
  // ## Component ======================================================

  import { HelloPage } from 'component/HelloPage';

  const App = () => {
    // ## Default ========================================================
    const isDark = true; // <--

    // ## Hook ===========================================================
    // ## Method =========================================================
    // ## Return =========================================================

    return (
      <div className={`app ${isDark ? 'dark' : 'light'}`}> // <--
        <HelloPage></HelloPage>
      </div>
    );
  };

  export default App;
  ```

- `npm start` 를 통해서 결과물을 확인해보세요.
- isDark 값을 false 와 true 로 바꿔보세요.

### SASS

&nbsp; sass 는 기존의 css 보다 향상된 스타일 문법 입니다.

&nbsp; 다음 두 명령어 중 하나를 골라 사용하시면 됩니다.

- node-sass 적용 `npm install node-sass` (비추천, 현재 지원 중단)
- dart sass 적용 `npm install sass`

#### SASS > $\color{#FF9922} \footnotesize \textbf{node-sass 에러 🚨}$

&nbsp; `node-sass` 는 더 이상 사용되지 않습니다. node 의 버전에 영향을 받기 때문에 개발을 하다보면 `node_modules\node-sass` 가 말썽을 일으킬 때가 있습니다.

&nbsp; 이는 sass 문법을 css 에 적용시켜주는 node-sass가 노드 버전에 의존적이어서 노드 버전이 바뀌면 오류를 일으키곤 합니다. 버전에 맞춰서 package.json 를 수정하는 방법도 있지만 dart sass 를 사용하는 쪽을 추천합니다.

#### SASS > 적용 예시

&nbsp; src/theme.css 파일의 확장자를 src/theme<b>.scss</b> 로 바꿔주세요

- 이제 SASS 문법으로 테마를 꾸밀 수 있습니다. // 주석처리 된 부분은 코드가 길어졌을 때, 눈에 잘보이도록 정리하는 용도 입니다. 아무런 의미가 없습니다.

  ```scss
  // # src/theme.scss
  // ## API & Library ==================================================
  // ## Asset ==========================================================
  // ### Font

  @font-face {
    font-family: Koverwatch;
    src: url(asset/font/koverwatch.ttf);
  }

  // ### Image
  // ## Default ========================================================
  // ### Variable

  .light {
    --color-main: #ffffff; /* <-- */
    --color-reverse: #000000; /* <-- */
  }

  .dark {
    --color-main: #353839; /* <-- */
    --color-reverse: #ffffff; /* <-- */
  }

  // ### Animation

  // ## Style ==========================================================

  * {
    font-family: Koverwatch;
    font-size: 64px;

    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    z-index: 1000;
    text-decoration: none;
  }

  .app {
    width: 100vw;
    height: 100vh;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
  }
  ```

- 가장 큰 차이 중 하나는 주석 처리가 // 로 편해졌다는 점 입니다.
- 또한 지금 당장은 큰 의미가 없지만 & 를 통해 자기 자신을 지정하여 캐스케이드하게 스타일 코드를 작성할 수 있습니다. 다음은 예시입니다.

  ```scss
  * {
    font-family: Koverwatch;
    font-size: 64px;

    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    z-index: 1000;
    text-decoration: none;

    // 나 (*) 바로 밑에 있는 .app 를 선택
    & > .app {
      background-color: red; // 확인용 빨간 배경

      width: 100vw;
      height: 100vh;
      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
    }
  }
  ```

- `npm start` 를 통해서 결과물을 확인해보세요.
- 예시용이었으므로 `* { ... & > .app { ... }}` 구조는 원래 모습인 `* {...}` 과 `.app {...}` 으로 분리하여 원상복구 하셔도 됩니다.

<hr />

### react-icons

&nbsp; [react-icons 사이트](https://react-icons.github.io/react-icons/)

&nbsp; 페이지 디자인에는 여러 아이콘과 기호들이 사용됩니다.

&nbsp; 기호가 필요한 상황마다 쓸만한 아이콘을 찾고 또 페이지에 넣는 과정은 상당히 불편합니다. react-icons 은 자주 쓰이는 아이콘 디자인들을 전부 제공해줍니다.

#### react-icons > 설치

- `npm install react-icons` 명령어로 설치해주세요

  ```bash
  npm install react-icons
  ```

#### react-icons > 적용예시

- react-icons... 를 import 해준 이후면 태그로 사용할 수 있습니다.
- 사용 예시는 다음과 같습니다.

  ```javascript
  // # src/component/Hello/index.tsx
  // ## API & Library ==================================================

  import React from 'react';
  import { AiFillSetting } from 'react-icons/ai'; // <--

  // ## Asset ==========================================================
  // ## Style ==========================================================
  // ## Component ======================================================

  export const Hello = () => {
    // ## Hook ===========================================================
    // ## Method =========================================================
    // ## Return =========================================================

    return (
      <center>
        <AiFillSetting /> // <--
        <h1>Hello, world!</h1>
        <h3>front-end : {process.env.REACT_APP_VERSION}</h3>
      </center>
    );
  };
  ```

<hr />

### Styled Component

- Styled Component 를 이용하면 React 가 HTML 코드를 스크립트를 이용하여 조작하듯 CSS 또한 스크립트로 조작할 수 있습니다.
- Styled Component 를 이용하면 스타일의 적용을 좀 더 국소적으로 통제할 수 있습니다. 필요 없어진 디자인 css 코드들의 정돈과 기존 코드들의 관리도 편해집니다.
- css 관리와 개발 편의성을 위하여 각 컴포넌트의 디렉토리 구조를 데이터 정보를 담은 `index.tsx` 와 스타일을 적용한 `style.tsx` 로 분리합니다.

#### Styled Component > 설치

- `npm install styled-components` 명령어로 스타일 컴포넌트 패키지를 설치할 수 있습니다.
- `npm install @types/styled-components` 명령어로 스타일 컴포넌트 타입에 대한 타입스크립트 명세서를 설치할 수 있습니다.

#### Styled Component > 적용예시

- Hello/style.tsx 를 만들어봅시다.

  - styled-components 를 임포트하고 div 태그를 선언하고 스타일을 적용합니다.
  - 변화가 눈에 띄도록 한 번 빨간색으로 칠해보겠습니다.

    ```typescript
    // # src/component/Hello/style.tsx

    import Styled from 'styled-components'; // <--

    export const Styled_Hello = Styled.div`
      width: 50vw;
      height: 50vh;
      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
    
      background-color: red;
    `;
    ```

- Hello/index.tsx 에 적용하겠습니다.

  - ./style 로 부터 Styled_Hello 컴포넌트 div 태그를 가져옵니다.
  - 이는 `<Styled_Hello>` 라는 태그명으로 사용할 수 있습니다.

    ```typescript
    // # src/component/HelloPage/index.tsx

    import React from 'react';
    import { AiFillSetting } from 'react-icons/ai';
    import { Styled_Hello } from './style'; // <--

    export const HelloPage = () => {
      return (
        <Styled_Hello> // <--
          <AiFillSetting />
          <h1>Hello, world!</h1>
          <h3>front-end : {process.env.REACT_APP_VERSION}</h3>
        </Styled_Hello>
      );
    };
    ```

- 다음과 같은 구조를 적용하여 Styled Component 에 props 값 즉 인자값을 넘기는 것도 가능합니다.

```typescript
export const Styled_Example = Styled.div<{ isActive: boolean }>`
  background: ${({ isActive }) => (isActive ? 'red' : 'blue')};
`;
```

- `npm start` 를 통해서 결과물을 확인해보세요.

<hr />

### react router

#### react router > 설치

- 패키지 설치 명령어
- `react-router-dom` 패키지와 `@types/react-router-dom` 타입스크립트 명세서를 설치해주세요.

  ```bash
  npm install react-router-dom
  npm install @types/react-router-dom
  ```

#### react router > 환경설정

- 테스트용 페이지 파일들을 생성

  1. 홈페이지 src/component/Home/

     - index.tsx

       ```typescript
       // # src/component/Home/index.tsx
       import React from 'react';

       export const Home = () => {
         return (
           <>
             <div>홈 페이지</div>
           </>
         );
       };
       ```

  2. 블로그 페이지 src/component/Blog/

     - index.tsx

       ```typescript
       // # src/component/Blog/index.tsx
       import React from 'react';

       export const Blog = () => {
         return (
           <>
             <div>블로그 페이지</div>
           </>
         );
       };
       ```

  3. 에러 핸들링 페이지 src/component/Error/

     ```typescript
     // # src/component/Error/index.tsx
     import React from 'react';

     export const Error = () => {
       return (
         <>
           <div>에러 페이지</div>
         </>
       );
     };
     ```

  <br />

- src/index.tsx

  - react의 최상단 index.tsx 에 Router가 감지할 수 있도록<br />
    react-router-dom 에서 BrowserRouter 를 임포트하고 `<BrowserRouter>` 태그를 넣어줍니다.

    ```typescript
    import React from 'react';
    import ReactDOM from 'react-dom/client';
    import { BrowserRouter } from 'react-router-dom'; // <--
    import { reportWebVitals } from 'api/webVitals';
    import App from './App';

    const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);

    root.render(
      <React.StrictMode>
        <BrowserRouter> // <--
          <App />
        </BrowserRouter>
      </React.StrictMode>,
    );

    reportWebVitals(console.log);
    ```

- src/App.tsx

  - react-router-dom 모듈의 Route, Routes, Navigate 를 임포트 해주세요.
  - Routes 태그 안에 주소에 맞게 Route 태그로 페이지를 연결해주세요.
  - Navigate 태그로 특정 주소로 보낼 수 있습니다. 처음 도착할 주소에는 HomePage, 아예 해당하지 않는 주소에는 ErrorPage를 매칭해주세요.
  - 다음과 같은 코드로 작성됩니다.

    ```typescript
    // # src/App.tsx
    // ## API & Library ==================================================

    import React from 'react';
    import { Route, Routes, Navigate } from 'react-router-dom';

    // ## Asset ==========================================================
    // ## Style ==========================================================
    // ## Component ======================================================

    import { Blog } from 'component/Blog';
    import { Error } from 'component/Error';
    import { Home } from 'component/Home';

    const App = () => {
      // ## Default ========================================================
      const isDark = false;

      // ## Hook ===========================================================
      // ## Method =========================================================
      // ## Return =========================================================

      return (
        <div className={`app ${isDark ? 'dark' : 'light'}`}>
          <Routes> // <--
            <Route path="/" element={<Navigate replace to="/home" />} />
            <Route path="/home/*" element={<Home />} />
            <Route path="/blog/*" element={<Blog />} />
            <Route path="/error/*" element={<Error />} />
            <Route path="/*" element={<Navigate replace to="/error" />} />
          </Routes>
        </div>
      );
    };

    export default App;
    ```

  - 각각의 임포트된 라이브러리는 다음의 역할을 합니다.
    - BrowserRouter
      > history API를 사용해 URL과 UI를 동기화하는 라우터입니다.
    - Route
      > 컴포넌트의 속성에 설정된 URL과 현재 경로가 일치하면 해당하는 컴포넌트, 함수를 렌더링한다.
    - Link
      > 'a'태그와 비슷합니다. to속성에 설정된 링크로 이동합니다. 기록이 history스택에 저장됩니다.
    - Switch
      > 자식 컴포넌트 Route또는 Redirect중 매치되는 첫 번째 요소를 렌더링합니다. Switch를 사용하면 BrowserRouter만 사용할 때와 다르게 하나의 매칭되는 요소만 렌더링한다는 점을 보장해줍니다. 사용하지 않을 경우 매칭되는 모두를 렌더링합니다.

- 사이트를 로컬 주소에 올려 테스트하는 `npm start` 명령어를 통해서 작동을 확인해봅시다.

  - 처음 주소가 /home 으로 가는지, /qwer 같은 이상한 주소는 /error 로 보내는지 /blog 주소를 주소창에 입력하면 제대로 가는지 확인해주세요.

- `npm run build` 명령어를 통해서 빌드한 후 /build 폴더 안의 내용물을 전부 배포용 프로젝트 `<GITHUB_ID>`.github.io에 올려준 뒤에 https://`<GITHUB_ID>`.github.io/ 에 접속해서 확인해봅시다.

  ```bash
  npm run build
  ```

#### react router > $\color{#FF9922} \footnotesize \textbf{404 에러 제어 🚨}$

&nbsp; 이번엔 잘 안될 것입니다. 404 에러 페이지가 뜹니다. 만약 잘 됬다면 주소창에 직접 https://`<GITHUB_ID>`.github.io<b>/blog</b> 를 입력해 보세요.

&nbsp; 404 에러가 뜨는 이유는 바로 웹 배포를 해주는 사실상의 백엔드 서버인 Gitpage.io 때문입니다. Gitpage.io 입장에서 보기엔 https://`<GITHUB_ID>`.github.io<b>/blog</b> 라는 주소는 없는 곳을 가리키는 이상한 주소입니다. React의 SPA 구조를 Gitpage.io 가 받아들이지 못해서 발생하는 문제입니다.

&nbsp; 다행히 편법을 사용하여 이 문제를 쉽게 해결할 수 있습니다. Gitpage.io는 이상한 주소로 인하여 404 에러를 응답할 때 <b>index.html</b> 옆에 <b>404.html</b> 파일이 존재한다면 그것을 대신 띄워줍니다. 이것을 응용하여 <b>404.html</b> 파일을 직접 생성해준 뒤, 입력받은 주소를 데이터로 바꾸어 https://`<GITHUB_ID>`.github.io<b>/</b> 기본주소로 넘겨주는 코드를 추가합니다. 또한 <b>index.html</b> 쪽에는 넘어온 주소 데이터가 있을 경우에 이를 해석해서 react router 에게 넘겨주는 코드를 추가합니다.

- 빌드된 front-end/build 폴더의 최상단 구조는 front-end/public 폴더에 들어있습니다.
- /public/404.html 파일 생성

  ```html
  <!-- front-end/public/404.html -->
  <!DOCTYPE html>
  <html>
    <head>
      <title>Integral Blog</title>
      <script type="text/javascript">
        window.location.replace(`/?url=${window.location.href}`);
      </script>
    </head>
    <body></body>
  </html>
  ```

- /public/index.html 파일 수정

  ```html
  <!-- front-end/public/index.html -->
  <!DOCTYPE html>
  <html lang="en">
    <head>
      <meta charset="utf-8" />
      <link rel="icon" href="%PUBLIC_URL%/favicon.ico" />
      <meta name="viewport" content="width=device-width, initial-scale=1" />
      <meta name="theme-color" content="#000000" />
      <meta name="description" content="Web site created using create-react-app" />
      <link rel="apple-touch-icon" href="%PUBLIC_URL%/logo192.png" />
      <link rel="manifest" href="%PUBLIC_URL%/manifest.json" />

      <title>Integral Blog</title>
    </head>
    <body style="margin: 0">
      <div id="root"></div>
      <script type="text/javascript">
        if (window.location.search.slice(1, 4) == 'url')
          window.history.replaceState(null, null, `${window.location.search.slice(5)}`);
      </script>
    </body>
  </html>
  ```

- Gitpage.io는 이상한 주소로 인하여 404 에러를 응답할 때 <b>index.html</b> 옆에 <b>404.html</b> 파일이 존재한다면 그것을 대신 띄워줍니다.
- <b>404.html</b> 파일을 직접 생성해준 뒤, 입력받은 주소를 데이터로 바꾸어 github.io/ 주소로 다시 넘겨주는 코드를 추가합니다. 데이터를 넘겨주는 방법은 여러 종류가 있지만 여기선 가장 쉽고 빠르게 전체주소를 쿼리스트링으로 넘겨주는 방법을 씁니다.

- 이를 다시 `npm run build` 명령어로 빌드 후에 gitpage.io 프로젝트에 올려 깃 페이지 링크에서 잘 작동하는 지 확인해보자. 그 외에도 직접 분해해서 필요한 데이터만 가져오는 방법, localstorage 를 쓰는 방법 등 본인에게 적합한 방법을 사용하세요.

#### react router > NavLink

&nbsp; 각 주소에 페이지를 할당했다면 이제 각 페이지를 넘나들수 있도록 링크 버튼을 만들어 보세요.

&nbsp; React와 비슷한 웹 프론트엔드 프레임워크 Vue 의 Vue Router 에서 `<router-link>` 를 지원하는 것과 같이 React Router 에서는 `<NavLink>` 를 지원합니다.

- Home 에 Error 와 Blog 로 이동하는 링크를 만들어보겠습니다.
- Home index.tsx에 다음과 같이 링크를 추가해주세요

  ```typescript
  // # src/component/Home/index.tsx

  import React from 'react';
  import { NavLink } from 'react-router-dom'; // <--
  import { Styled_Home } from './style';

  export const Home = () => {
    return (
      <Styled_Home>
        <h1>홈 페이지입니다.</h1>
        <br />
        <NavLink to="/blog">블로그 페이지로 가기</NavLink> // <--
        <NavLink to="/error">에러 페이지로 가기</NavLink> // <--
      </Styled_Home>
    );
  };
  ```

#### react router > $\color{#FF9922} \footnotesize \textbf{인터넷의 예제에서는 activeClassName 이 사용됬는데 오류가 발생하는 경우 🚨}$

&nbsp; 현재 페이지 위치를 가리키는 링크버튼은 클릭을 막거나, 색을 다르게 표현하는 경우가 있습니다.

&nbsp; 이때, 과거 다른 예시들 중에선 activeClassName 이라는 방법을 사용할텐데 이를 따라서 쓰게되면 에러가 납니다.

&nbsp; React Router v6 이전에는 activeClassName 으로 클릭된 태그에 클래스 적용이 가능했지만 더 이상 지원하지 않습니다. React Router v6 이후로는 직접적으로 `{ <BOOL_FUNCTION> }` 를 이용해서 class 태그 값을 바꾸는 함수를 넣어서 조작할 수 있습니다.

- isActive 변수로 클릭 된 태그의 정보를 조작하는 예시입니다.

  ```typescript
  <NavLink
    to="/blog"
    className={({ isActive }) => (isActive ? 'example-classname-1' : 'example-classname-2')}
  ></NavLink>
  ```

### react useState

&nbsp; react 라이브러리에서는 스크립트 코드를 통하여 가상 DOM 위에서 웹페이지를 생성합니다. 이 과정에서 let 의 변동적인 변수 사용이 제한됩니다. 아예 선언이 불가한 경우가 생기거나 또는 변경해도 이미 렌더링된 웹페이지에 변화가 적용되지 않습니다.

&nbsp; react 에서 변수를 사용하기 위해서는 변수의 그릇은 const 로 선언하고 변수가 변했기 때문에 다시 렌더링 해야한다는 사실을 react 가상 DOM 에 전달해줄 방법이 필요합니다. 이것이 useState 입니다.

&nbsp; useState 는 다음의 형태로 사용됩니다.

<center>

`const [『GETTER』, 『SETTER』] = useState<『VALUE_TYPE』>(『INITIAL_VALUE』);`

</center>

#### react useState > 예시

- 버튼을 클릭하면 카운트가 올라가는 사이트를 만들어 보겠습니다.

&nbsp; 다음과 같이 사용할 수 있습니다.

```typescript
// # src/component/Home/index.tsx

import React, { useState, useEffect } from 'react';

export const Home = () => {
  const [count, setCount] = useState(0); // <--

  const onClickEvent = () => {
    setCount(count + 1);
    console.log('클릭 이벤트 발생'); // <--
  };

  return (
    <>
      <h1>홈 페이지입니다.</h1>
      <br />
      <button onClick={onClickEvent}>버튼</button>
      <div>카운트 : {count}</div>
    </>
  );
};
```

### react useRef

&nbsp; useRef 는 다음과 같은 방식으로 값을 저장하고 사용할 수 있습니다.

<center>

`const 『VAULE_NAME』= useRef<『VAULE_TYPE』>(『INITIAL_VALUE』)`
`『VAULE_NAME』.current++;`

</center>

&nbsp; useRef 는 useState 와 비슷하게 const 로 변화하는 변수를 선언하는 방법입니다. useState 와는 크게 다음의 차이점을 지닙니다.

1. useState 는 getter 와 setter 를 사용하지만, useRef 는 객체 내부에 current 클래스 변수를 직접 사용합니다.

2. useRef 의 변화는 리렌더링의 트리거가 되지 않습니다. 다른 변화로 인하여 리렌더링이 발생했을 시에 비로소 useREf 의 변화가 적용됩니다. 덕분에 useRef 는 가벼우며 사이트에 무리를 주지 않습니다.

&nbsp; 위의 두 가지 특성으로 인하여 useRef 로 선언된 변수는 컴포넌트와 무관한 변수, DOM 요소 접근, 지속적인 값 저장, 커스텀 훅 생성 등에 사용됩니다.

#### react useRef > 예시

&nbsp; 다음의 예시는 useState 와 useRef 를 동시에 쓰는 코드 입니다. useState 의 값 count1 이 변하기 전에는 count2 의 변화가 페이지 렌더링에 적용되지 않습니다.

```typescript
// # src/component/Home/index.tsx

import React, { useState, useRef } from 'react';

export const Home = () => {
  const [count1, setCount1] = useState<number>(0);
  const count2 = useRef<number>(0);

  const count1Up = () => {
    setCount1(count1 + 1);
    console.log('카운트1 : ', count1);
  };

  const count2Up = () => {
    count2.current++;
    console.log('카운트2 : ', count2.current);
  };

  return (
    <>
      <h1>홈 페이지입니다.</h1>
      <br />
      <button onClick={count1Up}>카운트1 UP</button>
      <button onClick={count2Up}>카운트2 UP</button>
      <br />
      <div>카운트1 : {count1}</div>
      <br />
      <div>카운트2 : {count2.current}</div>
    </>
  );
};
```

### react useEffect

&nbsp; react 라이브러리에서는 가상 DOM으로 렌더링된 페이지를 다시 렌더링하기 전에는 페이지의 정보가 변하지 않습니다.

&nbsp; 유동적인 변화를 구현하거나, 함수가 구동하는 타이밍을 맞추기 위해서는 useEffect 를 사용해야 합니다. useEffect 에 선언된 객체가 변화할 때, useEffect는 이를 감지하고 작동합니다.

&nbsp; useEffect 함수 안에는 작동 시 호출할 콜백 함수와 변화를 감지할 의존성 객체들의 배열을 인자로 받습니다. 결과적으로 밑의 양식으로 사용할 수 있습니다..

<center>

`useEffect(『CALLBACK_FUNCTION』, 『DEPENDENCY_ARRAY』)`

</center>

- 의존성 객체를 인자로 주지 않았을 경우에는 모든 변화 상황 마다 콜백함수가 발동합니다.

```typescript
// # src/component/Home/index.tsx

import React, { useState, useEffect } from 'react';

export const Home = () => {
  const [count1, setCount1] = useState(0);
  const [count2, setCount2] = useState(0);

  useEffect(() => {
    console.log('뭐가 변하든 나도 작동할꺼야!');
  }); // <--

  return (
    <>
      <h1>홈 페이지입니다.</h1>
      <br />
      <button onClick={() => setCount1(count1 + 1)}>카운트 1 UP</button>
      <button onClick={() => setCount2(count2 + 1)}>카운트 2 UP</button>
      <br />
      <div>카운트1 : {count1}</div>
      <div>카운트2 : {count2}</div>
    </>
  );
};
```

- 의존성 객체를 인자로 줄 경우에는 해당 인자의 변화에만 반응합니다.

```typescript
// # src/component/Home/index.tsx

import React, { useState, useEffect } from 'react';

export const Home = () => {
  const [count1, setCount1] = useState(0);
  const [count2, setCount2] = useState(0);

  useEffect(() => {
    console.log('count2가 변하면 나도 작동할꺼야!');
  }, [count2]); // <--

  return (
    <>
      <h1>홈 페이지입니다.</h1>
      <br />
      <button onClick={() => setCount1(count1 + 1)}>카운트 1 UP</button>
      <button onClick={() => setCount2(count2 + 1)}>카운트 2 UP</button>
      <br />
      <div>카운트1 : {count1}</div>
      <div>카운트2 : {count2}</div>
    </>
  );
};
```

- 의존성 객체를 빈 객체로 줄 경우에는 맨 처음 페이지가 로드 될 때, 초기 렌더링 시에만 함수를 호출하고 다시는 호출되지 않습니다.

```typescript
// # src/component/Home/index.tsx

import React, { useState, useEffect } from 'react';

export const Home = () => {
  const [count1, setCount1] = useState(0);
  const [count2, setCount2] = useState(0);

  useEffect(() => {
    console.log('처음에만 작동할꺼야!');
  }, []); // <--

  return (
    <>
      <h1>홈 페이지입니다.</h1>
      <br />
      <button onClick={() => setCount1(count1 + 1)}>카운트 1 UP</button>
      <button onClick={() => setCount2(count2 + 1)}>카운트 2 UP</button>
      <br />
      <div>카운트1 : {count1}</div>
      <div>카운트2 : {count2}</div>
    </>
  );
};
```

<hr />

### recoil 상태 관리 라이브러리

#### recoil 상태 관리 라이브러리 > 필요한 이유

&nbsp; Vue 나 React 에서는 DOM 기반으로 페이지를 형성하는 컴포넌트들을 분리 개발하게 된 덕분에 재사용성이 매우 증가되었지만, 컴포넌트 간에 상호작용을 필요로 하는 계산에는 애로사항이 꽃핍니다.

&nbsp; 가끔 부모 컴포넌트와 자식 컴포넌트가 상호작용을 해야 할 때가 있습니다. 예를 들어서 컬러팔레트를 클릭하면 배경이 바뀌는 사이트를 상상해 보세요. 버튼은 자식 컴포넌트에 있습니다. 부모 컴포넌트의 바탕색은 어떻게 바꿀까요? 그 반대로 부모에 버튼이 있고 자식의 색을 바꿔야 한다면요?

&nbsp; 부모가 자식에게 데이터를 전달할 때는 인자를 통해서 넘겨줄 수 있습니다. 부모 컴포넌트에서 자식에게 넘겨주는 인자를 `props` 라고 부릅니다.

&nbsp; 자식이 부모에게 데이터를 넘겨주기 위해선 부모의 `event`를 자식에게 넘겨주면 됩니다. Vue나 Svelte 에서는 emit 을 통해, React 에선 스크립트를 직접 적용할 수 있기 때문에 콜백함수 hook 을 넘겨줄 수 있습니다.

&nbsp; 하지만 상호작용해야 할 컴포넌트가 고조할머니 뻘이라면 어떡하시겠습니까? 고조부모-증조부모-조부모-부모-자식 관계들을 건너 건너 props 와 event 를 전달하시겠습니까? 이런 인자 전달 캐스케이드 쇼는 너무 복잡하고 힘듭니다.

&nbsp; 프로그래밍처럼 전역변수만 있다면 해결될 문제입니다. 이 문제를 해결하기 위해 상태 관리 라이브러리`(State Management Library)`가 필요합니다. 여러 컴포넌트에서 데이터를 공유할 수 있도록 데이터를 중앙 관리하는 방식이라고 생각하면 이해가 편합니다.

&nbsp; 많은 개발자들이 사용하며 어느 정도 신뢰가 쌓인 Vue의 Vuex, Pinia 그리고 React의 Recoil, Redux 가 주로 사용됩니다. React 에서 자체적으로 지원하는 전역 상태 관리 인터페이스 Context API 나, Mobx 등 여러 방법들이 있으니 입맛에 맞게 선택하시면 됩니다.

&nbsp; 전 데이터 비동기화 처리가 간편한 recoil 을 채택하겠습니다.

#### recoil 상태 관리 라이브러리 > 설치

- `npm install recoil`<br/>
  다음의 명령어로 위에서 언급한 패키지들을 내려 받습니다.

<br />

## 서버 환경 조성

### REST API

&nbsp; REST API 는 세련되고 안정된 서버와의 통신 방식입니다.

&nbsp; 여기서는 별개의 서버 호출을 하지 않고 프론트엔드 측에서 형태만 구축하겠습니다. 백엔드 서버를 별개로 올리지 않더라도 웹페이지를 live server 나 npm start 등의 명령어로 로컬 호스트로 올리게 되면 페이지를 렌더링 하면서 페이지의 파일들도 해당 포트에 올리게 됩니다.

#### REST API > localhost 에 대한 이해

&nbsp; vscode 확장 live server 의 경우나 react의 npm start 같은 로컬호스트 테스트를 실행하면 클라우드 시스템과 같이 여러분의 파일 폴더를 웹 브라우저에서 접근할 수 있게 됩니다. 설정한 포트 넘버에 따라 `localhost:『PORT_NUMBER』/` 주소에서 접근할 수 있습니다.

&nbsp; 이 과정에서 파일 디렉토리 목록을 담은 index 라는 이름의 파일이 있다면 index 파일명의 파일을 브라우저에 띄웁니다. 이것이 index.tsx 라는 이름을 가진 파일이 해당 주소에서 브라우저에 띄워지는 이유입니다.

&nbsp; 예를 들어, 로컬호스트로 올린 폴더에 data.json 이라는 제목의 파일을 넣어뒀다면 크롬이나 엣지등의 웹브라우저에서 `localhost:『PORT_NUMBER』/data.json` 이라고 검색하면 해당 데이터가 출력됩니다. React 로컬호스트 테스트의 경우 react 프로젝트 최상단 public 폴더가 로컬호스트로 올려집니다.

- Example 예시를 확인하는 두 사용자 User 가 있다고 가정해보겠습니다.
- react 프로젝트 최상단 public 폴더에 가서버 역할을 할 server/ 폴더를 만들어주세요.
- public/server/ 폴더에 id 에 해당하는 example/ 폴더를 만들어주세요.
- public/server/example/user.json 파일을 생성하고 두 사용자의 정보를 다음과 같이 만들어주세요.

```json
[
  {
    "id": 0,
    "name": "홍길동"
  },
  {
    "id": 1,
    "name": "전우치"
  }
]
```

- 터미널에 `npm start` 명령어로 react 의 빌드 테스트를 로컬 서버에 올려주세요.
- 웹브라우저에서 `localhost:『PORT_NUMBER』/server/example/user.json` 주소를 검색해주세요.(react의 디폴트 포트넘버는 3000 입니다.)
- 브라우저에서 해당 데이터에 접근할 수 있는 지 확인해봅시다.

&nbsp; 우선 이렇게 같은 소스에서 데이터에 접근하는 방법을 이용하여 서버가 별도로 있는 척을 하겠습니다. 실제로 서버를 준비하고 포트포워딩하여 연결할 때는 주소만 바꿔주면 됩니다.

#### $\color{#FF9922} \footnotesize \textnormal{REST API > 추가적인 설명 🚨}$

&nbsp; 지금 이 구현은 프론트엔드 측에서 절반만 구현한 것 입니다. RESTful 한 통신을 위해서는 백엔드 서버 또한 이에 적합하게 만들어야 합니다.

&nbsp; REST API 서버는 URL 에 다루는 자원에 접근할 수 있는 ID 고유키만을 적어 소통하도록 구성합니다. 데이터의 CRUD 조작은 GET, POST, PUT, DELETE 라는 http 프로토콜 통신 타입에 담아서 요청합니다.

&nbsp; 그렇다면 `http:『SERVER_URL』/『RESOURCE_ID』/『DATA_PRIMARY_KEY』` 만으로 서로 소통할 수 있게 됩니다. 지금 예시에서는 REST API 서버를 구축하는 백엔드 개발 단계를 생략했기 때문에 오해없으시길 바랍니다.

#### REST API > Axios

&nbsp; axios 라이브러리는 promise 객체를 좀더 간결하고 세련되게 쓰는 방법입니다.

##### REST API > Axios > 설치

- axios 객체를 사용할 수 있도록 패키지를 설치해주세요.

```bash
npm install axios
```

##### REST API > Axios > 코드 예시

&nbsp; 이제 axios 를 우리 입맛에 맞게 쓸 수 있도록 API 화 시킬 것 입니다.

- src/api/ 폴더에 axios/ 폴더를 만들고 index.ts 를 생성해주세요.

````typescript
// # src/api/axios/index.tsx

import axios, { AxiosInstance } from 'axios';

/**
 * @description
 * 모든 Axios 객체를 중앙통제하는 싱글턴 API 인스턴스 입니다.
 *
 * 다른 api 주소에서 받아올 경우에는 Axios 객체를 새로 만들어 지정해줄 수 있습니다.
 *
 * @example
 * ```
 * // * Axios API 임포트하여 사용합니다.
 * import { AxiosApi } from 'api/axios';
 *
 * // * 다음과 같이 객체를 받아옵니다. base url 과 객체명을 통일하는 것을 권장합니다.
 * const『AXIOS_INSTANCE_NAME』 = AxiosApi.getAPI().getInstance('『BASE_URL』');
 *
 * // * 엑시오스 인스턴스 객체에서는 다음과 같이 url 요청을 보낼 수 있습니다.
 * 『AXIOS_INSTANCE_NAME』.get(`『REQUEST_URL』`)
 * ```
 *
 * @author inte99ral
 * @version 2024-11-18
 */

export class AxiosApi {
  // ## Private:

  private static apiInstance: AxiosApi;
  private axiosMap: Map<string, AxiosInstance>;

  private constructor() {
    this.axiosMap = new Map<string, AxiosInstance>();
    this.axiosMap.set(
      'default',
      axios.create({
        baseURL: process.env.REACT_APP_SERVER,
        headers: { 'Content-Type': 'application/json; charset=UTF-8' },
      }),
    );
  }

  // ## Public:

  public static getAPI = () => {
    if (!AxiosApi.apiInstance) AxiosApi.apiInstance = new AxiosApi();
    return AxiosApi.apiInstance;
  };

  public getInstance = (url: string = 'default', isBaseUrl: boolean = true) => {
    if (!this.axiosMap.has(url)) {
      this.axiosMap.set(
        url,
        axios.create({
          baseURL: (isBaseUrl ? process.env.REACT_APP_SERVER : '') + url,
          headers: { 'Content-Type': 'application/json; charset=UTF-8' },
        }),
      );
    }
    return this.axiosMap.get(url);
  };

  /**
   *
   * @param accessToken axios에 입력할 엑세스토큰
   * @param axiosUrlArr 대상 axios의 url, 값이 없다면 모든 axios를 대상으로 합니다.
   */
  public setAccessToken = (accessToken: string, ...axiosUrlArr: string[]) => {
    this.axiosMap.forEach((axiosInstance: AxiosInstance, axiosUrl: string) => {
      if (axiosUrlArr.length != 0 || !axiosUrlArr.includes(axiosUrl)) return;
      axiosInstance.defaults.headers.common['Authorization'] = `Bearer ${accessToken}`;
    });
  };

  /**
   *
   * @param interceptFunction axios에 입력할 인터셉터 함수
   * @param axiosUrlArr 대상 axios의 url, 값이 없다면 모든 axios를 대상으로 합니다.
   */
  public setRequestInterceptor = (interceptFunction: boolean, ...axiosUrlArr: string[]) => {
    this.axiosMap.forEach((axiosInstance: AxiosInstance, axiosUrl: string) => {
      if (axiosUrlArr.length != 0 || !axiosUrlArr.includes(axiosUrl)) return;
      axiosInstance.interceptors.request.use(
        (config) => {
          if (interceptFunction) throw new Error('Error');
          return config;
        },
        (error) => {
          Promise.reject(error);
        },
      );
    });
  };
}
````

##### REST API > Axios > 코드 상세 설명

- Axios 객체는 싱글턴 디자인패턴을 채택하여 중복되지 않도록 하는 것이 좋습니다. Axios 객체가 여러 번 생성되어 서버 컴퓨터에게 순서섞인 비동기적 CRUD 처리를 요구하게 될 경우, 서버 데이터의 CRUD 데이터 처리 순서가 뒤죽박죽이 될 수 있습니다.

- 서버의 오버헤드를 줄이기 위하여 여러 다른 서버 주소에서 데이터를 가져오는 경우가 있기 때문에 baseUrl 지정을 유동적으로 할 수 있도록 했습니다.

- fetch 의 예시를 보면 알수있듯, Axios를 사용할 때는 response 객체에 json() 또는 text() 메서드가 없습니다. 그 이유는 Axios가 이미 응답 데이터를 자동으로 파싱하기 때문입니다. Axios에서는 response 객체의 data 속성을 통해 직접 파싱된 데이터에 접근할 수 있습니다.

#### REST API > API 화

&nbsp; axios 싱글턴 인스턴스를 만들고 리턴받는 API 를 구현하였습니다. 이제 RESTful 한 요청/응답 데이터를 얻어오는 함수들을 만들고 API 화 하겠습니다.

&nbsp; 다음의 예시는 example 이라는 resource id 에 맞춰 RESTful 하게 통신하는 상황을 가정합니다.

&nbsp; public/server/example/user.json 파일에 있는 데이터를 가져오고 다루는 API 를 만들어봅시다.

- src/api/ 폴더에 rest/ 폴더를 만듭니다.
- src/api/rest/ 폴더에 example/ 폴더를 만들고 index.ts 를 생성해주세요.

````typescript
// # src/api/rest/『RESTFUL_ID』/index.tsx

// ## Documentation ==================================================
/**
 * @description
 * REST API 에 맞게 통신 요청/응답 처리를 함수화 한 파일 입니다.
 *
 * base url, 즉 REST 통신의 자원 ID 와 객체명을 통일하는 것을 권장합니다.
 *
 * @example
 * ```
 * // * rest 라이브러리 임포트하여 사용합니다.
 * import {『RESTFUL_FUNCTION』} from 'api/rest/『RESTFUL_ID』'
 *
 * // * 요청/응답은 프라미스 객체로 처리되므로 동기적으로 처리하는 것은 불가능하며 비동기 처리를 해야합니다.
 * // 1. IFFE 방식
 * (async () => { const responceData = await 『RESTFUL_FUNCTION』(); })();
 *
 * // 2. Promise 체이닝
 * 『RESTFUL_FUNCTION』().then((data) => { const responceData = data; });
 * ```
 *
 * @author inte99ral
 * @version 2024-11-18
 */

// ## API & Library ==================================================

import { AxiosApi } from 'api/axios';

// ## Interface & Type ===============================================

/**
 * @description
 *
 * 응답 데이터의 Interface & Type 입니다.
 *
 * typescript 에서는 응답 데이터의 Type 을 반드시 알아야하는 경우가 있습니다.
 *
 * @example
 * ```
 * // * rest 라이브러리 임포트하여 사용합니다.
 * import {『RESTFUL_FUNCTION』,『RESPONCE_TYPE』} from 'api/rest/『AXIOS_OBJECT_NAME』'
 *
 * // * useState 에 대한 예시는 다음과 같습니다.
 * const [『SETTER』,『GETTER』] = useState<『RESPONCE_TYPE』[]>();
 *
 * (async () => {
 *  『GETTER』(await 『RESTFUL_FUNCTION』());
 * })();
 * ```
 *
 * @author inte99ral
 * @version 2024-11-18
 */
export interface User {
  [key: string]: string | number | boolean; // 인덱스 시그니처 - 동적 키 접근 허용
  id: number;
  name: string;
}

// ## Variable & Constant ============================================

const exampleAxios = AxiosApi.getAPI().getInstance('example');

// ## Function =======================================================

export const getExampleUserlist = () => {
  return new Promise<User[]>((resolve, reject) => {
    exampleAxios
      ?.get(`/user.json`)
      .then((response) => {
        resolve(response.data);
      })
      .catch((error) => {
        reject(error);
      });
  });
};

/**
 * @description Axios 객체가 아닌 fetch를 사용한 예시 입니다.
 * @author inte99ral
 * @version 2024-11-18
 */
export const getTestDataByFetch = () => {
  return new Promise((resolve, reject) => {
    // fetch 옵션의 상세 설명 https://developer.mozilla.org/ko/docs/Web/API/Window/fetch
    fetch('server/example/user.json', {
      method: 'GET', // { GET | POST | PUT | DELETE }
      mode: 'cors', // { no-cors | cors "교차 출처(cross-origin) 허용" | same-origin "동일출처만 허용" }
      headers: {
        'Content-Type': 'application/json',
      },
    })
      .then((response) => {
        if (!response.ok) throw new Error(`HTTP error! status: ${response.status}`);
        return response.json();
      })
      .then((data) => {
        // console.log('JSON 데이터 로드 완료:', data);
        resolve(data);
      })
      .catch((error) => {
        // console.error('JSON 파일 로드 중 오류 발생:', error);
        reject(error);
      });
  });
};
````

#### REST API > 사용 예시

- **실전과 비슷하게 같은 url 안에서 받아오는 방법**

  &nbsp; `localhost:『PORT_NUMBER』/home/` 주소의 페이지에서 `localhost:『PORT_NUMBER』/server/example/user.json` 에서 받아온 유저들의 정보를 테이블로 출력해보겠습니다.

  ```typescript
  // # src/component/Home/index.tsx

  import React, { useState, useEffect } from 'react';

  import { getExampleUserlist, ExampleUser } from 'api/rest/example';

  export const Home = () => {
    const [exampleUserList, setExampleUserList] = useState<ExampleUser[]>();

    // 또는 ExampleUser 를 가져오지 않고 타입추론 합니다.
    // const [exampleUserList, setExampleUserList] = useState<Awaited<ReturnType<typeof getExampleUserlist>>>();

    useEffect(() => {
      (async () => setExampleUserList(await getExampleUserlist()))();
    }, []);

    return (
      <>
        <h4>예시 유저들의 목록은 다음과 같습니다.</h4>
        <br />
        {exampleUserList ? (
          <table style={{ borderCollapse: 'collapse' }}>
            <tr>
              {Object.keys(exampleUserList[0]).map((header, index) => (
                <th key={index} style={{ border: '1px solid black', padding: '14px' }}>
                  {header}
                </th>
              ))}
            </tr>
            {exampleUserList.map((row, rowIndex) => (
              <tr key={rowIndex}>
                {Object.keys(row).map((header, cellIndex) => (
                  <td key={cellIndex} style={{ border: '1px solid black', padding: '14px' }}>
                    {row[header]}
                  </td>
                ))}
              </tr>
            ))}
          </table>
        ) : (
          <></>
        )}
      </>
    );
  };
  ```

- **Github API 를 이용하는 방법**

  &nbsp; Github 의 raw 데이터 API 를 사용하는 방법 또한 존재합니다. 이 경우에 통상적으로 다음의 구조의 url 로 raw 데이터를 받아올 수 있습니다.

  ```text
  https://raw.githubusercontent.com/『USER_NAME』/『REPOSITORY_NAME』/『BRANCH_NAME』/『DIRECTORY_PATH』/『FILE_NAME』
  ```

  &nbsp; 원하는 데이터를 깃허브에서 찾은 뒤에 우상단 raw 를 클릭하면 주소를 얻을 수 있습니다.

&nbsp; 앞으로 AWS 나 서버를 올리게 된다면 곧바로 그 주소에 맞춰 수정하면 됩니다.

## 리액트 마크다운

&nbsp; 매번 HTML 코드를 작성하는 일은 괴롭습니다. 사이트 운영에 의미가 없겠죠.

&nbsp; 유동적이고 지속가능한 사이트 확장을 위해서 마크다운을 사이트에 적용가능한 HTML 로 바꾸어주는 라이브러리를 사용하겠습니다.

### 리액트 마크다운 > 설치

- 다음의 npm 명령어로 설치할 수 있습니다.

  ```bash
  npm install react-markdown
  ```

### 리액트 마크다운 > 적용

- 다음과 같은 방법으로 적용됩니다.

  ```tsx
  import React from 'react';
  import ReactMarkdown from 'react-markdown';

  export const Example = () => {
    const post = `
    # 마크다운 양식의 글
    `;

    return (
      <>
        <ReactMarkdown>{post}</ReactMarkdown>
      </>
    );
  };
  ```

### 리액트 마크다운 > 심화

&nbsp; 심화 예시로 Github 에서 md 파일을 렌더링하는 방법을 그대로 만들어 보겠습니다.

#### 리액트 마크다운 > 심화 > 0. 사전정리작업

&nbsp; 우선 글씨가 보기 좋도록 src/theme.scss 에서 폰트를 [Pretendard](https://namu.wiki/w/Pretendard) 로 바꾸겠습니다. 또한 전체 테마에서 바탕색과 문서색을 정해주겠습니다.

- **src/theme.scss 의 수정**

  - src/theme.scss 의 테마 폰트를 글씨가 보기 좋도록 [Pretendard](https://namu.wiki/w/Pretendard) 로 정하겠습니다.
  - src/theme.scss 의 사이트 전체 테마에서 바탕색과 문서색을 정해주겠습니다.

  ```scss
  // # src/theme.scss

  // ...

  @font-face {
    font-family: Pretendard;
    src: url(asset/font/PretendardVariable.ttf);
  }

  // ...

  .light {
    --color-main: #ffffff;
    --color-sub: #f4f5f7;
    --color-reverse: #000000;
    --color-blur: #00000040;
  }

  .dark {
    --color-main: #353839;
    --color-sub: #2f2f31;
    --color-reverse: #ffffff;
    --color-blur: #ffffff40;
  }

  // ...

  * {
    font-family: Pretendard; // <--
    font-size: 14px;

    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    z-index: 1000;
    text-decoration: none;
  }
  ```

&nbsp; src/component/Home/index.tsx 도 포스팅 글들을 보기좋게 정리하겠습니다. style 파일에서 스타일 컴포넌트를 생성해주세요.

- **src/component/Home/style.tsx 를 다음과 같이 수정합니다.**

  ```tsx
  // # src/component/Home/style.tsx

  import Styled from 'styled-components';

  export const Styled_Home = Styled.div`
    width: 100vw;
    height: 100vh;
    padding: 14px;
  
    display: flex;
    align-items: top;
    overflow: auto;
  
    background-color: var(--color-sub);
  `;

  export const Styled_HomeCard = Styled.div`
    width: 30vw;
    max-width: 30vw;
    flex-shrink: 0;
    margin: 14px;
  
    border-radius: 14px;
    background-color: var(--color-main);
    overflow: hidden;
  
    box-shadow:
      4px 4px 10px -1px rgba(0, 0, 0, 0.25),
      -4px -4px 10px -1px rgba(255, 255, 255, 0.25);
  
    & > div:nth-of-type(1) {
      height: 80px;
      min-height: 80px;
  
      color: white;
      font-size: 24px;
      font-weight: bold;
  
      padding: 28px;
      background-color: #353839;
  
    }
  
    & > div:nth-of-type(2) {
      height: calc(100% - 80px);
      padding: 28px;
      overflow: auto;
    }
  `;
  ```

- **src/component/Home/component/Markdown_0/index.tsx**

  - src/component/Home/component/Markdown_0/ 폴더를 만들고 그 안에 index.tsx 를 만들어 주세요.
  - 이 컴포넌트는 마크다운 텍스트를 해석없이 그냥 텍스트로 보여줍니다.
  - 마크다운을 해석해서 렌더링 한 경우와의 차이를 비교해 볼 것 입니다.

  ```tsx
  // # src/component/Home/component/Markdown_0/index.tsx

  import React, { FC } from 'react';

  export const Markdown_0: FC<{ children: string }> = ({ children }) => {
    return (
      <>
        <div>Markdown #0</div>
        <div>{children}</div>
      </>
    );
  };
  ```

- **src/component/Home/index.tsx 를 다음과 같이 수정합니다.**

  ```tsx
  // # src/component/Home/index.tsx

  import React from 'react';

  import { Styled_Home, Styled_HomeCard } from './style';

  export const Home = () => {
    const post = `
      # 마크다운 제목
  
      ## 마크다운 소제목
  
      - 목록1
      - 목록2
    `;

    return (
      <Styled_Home>
        <Styled_HomeCard>
          <Markdown_0>{post}</Markdown_0>
        </Styled_HomeCard>
      </Styled_Home>
    );
  };
  ```

&nbsp; `npm start` 로 확인해보면 마크다운을 적용하지 않았기 때문에 post 내용이 글씨 그대로 카드 안에 나타났을 것 입니다.

&nbsp; 이제 카드 별로 적용되는 플러그인이 마크다운 텍스트를 어떻게 렌더링하는 지 구별해서 볼 수 있습니다.

&nbsp; src/component/Home/index.tsx 의 post 에 여러 마크다운 문법들을 적어넣겠습니다.

- **src/component/Home/index.tsx**

  - post 값을 다음과 같이 수정해주세요.

  ```tsx
  // # src/component/Home/index.tsx

  // ...

  export const Home = () => {
    const post = `
    # 마크다운：Markdown

    ## 기본 문법

    ### Latex 수식

    - n<sup>r</sup>
    - A<sub>k</sub>

    - When $a \\ne 0$, there are two solutions to $(ax^2 + bx + c = 0)$ and they are
      $$ x = {-b \\pm \\sqrt{b^2-4ac} \\over 2a} $$

    - \${\\color{lightgreen}Light \\space Green}\$

    - \$\\color{#FF9922} \\footnotesize \\textnormal{일반 텍스트}\$

    <div align=center>

    \$_{n}\\mathrm{H}_{r} = C'(n, r) = \\binom{n+r-1}{r} = \\binom{n+r-1}{n-1}\$

    </div>

    ### 인용

    - 블록 인용：\`>\` 사용

      > 첫번째 블록
      >
      > > 두번째 블록
      > >
      > > > 세번째 블록

    ### 코드 블럭

    - 인라인 코드

      - \`[](int x, int y) -> int { return x + y; };\`

    - 펜스드 코드 블럭

      \`\`\`cpp
      [](int x, int y) -> int { return x + y; };
      \`\`\`

    ### 코드 하이라이트

    - C++

    \`\`\`cpp
    #include <bits/stdc++.h>

    #ifndef ONLINE_JUDGE
    #define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::cin.rdbuf(fs.is_open()?((std::istream*)&fs)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
    #else
    #define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
    #endif

    using namespace std;

    int main() {
      SET_IO("_INPUT_.txt");

      for (string buf; cin >> buf;) cout << buf << endl;

      return 0;
    }
    \`\`\`

    - Java

    \`\`\`java
    package Baekjoon;

    import java.io.BufferedReader;
    import java.io.FileInputStream;
    import java.io.IOException;
    import java.io.InputStreamReader;

    public class Main {
      public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("__INPUT__.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (String line = br.readLine(); line != null; line = br.readLine()) System.out.println(line);

        br.close();
        return;
      }
    }

    \`\`\`

    - JavaScript

    \`\`\`js
    const reader = {
      fullLine: () => this.fullLine,
      hasMoreLines: () => !!this.fullLine[this.lineIndex],
      readLine: (() => {
        this.lineIndex = 0;
        this.fullLine = require('fs')
          // .readFileSync('dev/stdin') // * 터미널 입력
          .readFileSync('__INPUT__.txt') // * 로컬 __INPUT__.txt 입력
          .toString()
          .split(/\r\n|\r|\n/gm);

        return () => this.fullLine[this.lineIndex++];
      })(),
    };

    while (reader.hasMoreLines()) console.log(reader.readLine());
    \`\`\`

    ### 가운데 정렬：Align Center

      <div align=left>
      『LEFT_TEXT』
      </div>

      <center>
      『CENTER_TEXT_0』
      </center>

      <div align=center>
      『CENTER_TEXT_1』
      </div>

      <div align=right>
      『RIGHT_TEXT』
      </div>

    ### 확장/축소：Accordion

    <details>
    <summary>

    \`\`\`cpp
    int main() {
    ... 클릭하여 확장/축소 ...
    \`\`\`

    </summary>

    \`\`\`cpp
    cout << "Hello, World!" << endl;
    \`\`\`

    </details>

    \`\`\`cpp
    return 0;
    }
    \`\`\`

    ### 수평선

    ---

      <hr />

    ### 공백：No Breaking Space

    &nbsp;공백&nbsp;공백

    ### 줄바꿈：Breaking Line

    개행1
    개행1

    개행2

    개행2

    개행3<br />개행3

    ### 표：Table

    #### Table > Markdown Native

    | 첫번째(왼쪽정렬) | 두번째(가운데정렬) | 세번째(오른쪽정렬) |
    | ---------------- | :----------------: | -----------------: |
    | 왼쪽정렬         |     가운데정렬     |         오른쪽정렬 |

    #### Table > HTML Tag

      <table>
      <tr>
      <th align=left>첫번째(왼쪽정렬, 코드블럭)</th>
      <th align=center>두번째(가운데정렬)</th>
      <th align=right>세번째(오른쪽정렬)</th>
      </tr>
      <tr>
      <td align=left>

    \`\`\`cpp
    #include <bits/stdc++.h>

    int main() {
    return 0;
    }
    \`\`\`

      </td>
      <td align=center>가운데정렬</td>
      <td align=right>오른쪽정렬</td>
      </tr>
      </table>

    ### 텍스트 서식

    - _이탤릭체_
    - **볼드체**
    - <b>볼드체</b>
    - ~~취소선~~
    - <del>취소선</del>
    - <u>밑줄</u>
    - **_볼드+이탤릭_**
    - **~~볼드+취소선~~**
    - **_~~볼드+이탤릭+취소선~~_**

    ### 목록

    - 순서 없는 목록
      - 목록1
      - 목록2
    - 순서 있는 목록
      1. 목록1
      2. 목록2
    - 체크리스트
      - [ ] 목록1
      - [ ] 목록2

    ### 참조

    #### 참조 > Markdown Native

    - [하이퍼 링크](./server/post/9/0.png)
    - ![대체 텍스트](./server/post/9/0.png)

    #### 참조 > HTML Tag

    - <a href="./server/post/9/0.png">이미지 링크</a>
    - <img src="./server/post/9/0.png" alt="0" width="200" height="200" />
    `;


  // ...
  ```

- **public/server/post/1/0.png**

  - 위의 `const post = ...` 값의 가장 밑의 이미지 참조 문법을 보시면 "./server/post/9/0.png" 라는 주소로 이미지를 부르고 있습니다.
  - 항목 중에서 `REST API > localhost 에 대한 이해` 항목에 나오듯, "public/server/post/9/" 경로에 0.png 파일을 필요로 합니다.
  - 이 복잡해보이는 경로는 후에 Axios를 적용하면서 사용됩니다. 일단 위의 경로를 따라 폴더를 만들어 주세요.
  - 마크다운 문서에 띄울 png 파일을 이름을 0.png 로 하고 폴더에 넣어주세요.

#### 리액트 마크다운 > 심화 > 1. 마크다운 표준 문법 적용

&nbsp; 이제 React-markdown 을 적용하겠습니다. `리액트 마크다운 > 설치` 항목에서 언급된 데로 `npm install react-markdown` 명령어로 react-markdown 이 설치되어 있어야 합니다.

- **src/component/Home/component/Markdown_1/index.tsx**

  - src/component/Home/component/Markdown_1/ 폴더를 만들고 그 안에 index.tsx 를 만들어 주세요.
  - `import Markdown from 'react-markdown'`

  ```tsx
  // # src/component/Home/component/Markdown_1/index.tsx

  import React, { FC } from 'react';
  import Markdown from 'react-markdown'; // <--

  export const Markdown_1: FC<{ children: string }> = ({ children }) => {
    return (
      <>
        <div>Markdown #1</div>
        <div>
          <Markdown>{children}</Markdown>
        </div>
      </>
    );
  };
  ```

- **src/component/Home/index.tsx**

  - Home 에 Markdown_1 컴포넌트를 적용해주세요.

  ```tsx
  // # src/component/Home/index.tsx

  import React from 'react';

  import { Markdown_0 } from './component/Markdown_0';
  import { Markdown_1 } from './component/Markdown_1';

  export const Home = () => {
    // ...

    return (
      <Styled_Home>
        <Styled_HomeCard>
          <Markdown_0>{post}</Markdown_0>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_1>{post}</Markdown_1>
        </Styled_HomeCard>
      </Styled_Home>
    );
  };
  ```

&nbsp; 0번과 비교해보면 좀 부실해보이지만 1번은 확실히 마크다운의 기초적인 문법이 적용되어 있습니다.

&nbsp; 스타일이 적용되지 않았기 때문에 아직 비주얼적인 부분이 어색합니다.

#### 리액트 마크다운 > 심화 > 2. 마크다운 깃허브 CSS 적용

&nbsp; 가장 기본적인 형식만 갖춘 부분들에 CSS 을 적용하여 그럴싸하게 만들어봅시다.

- **NPM 설치**

  ```bash
  npm install github-markdown-css
  ```

- **src/component/Home/component/Markdown_2/index.tsx**

  - src/component/Home/component/Markdown_2/ 폴더를 만들고 그 안에 index.tsx 를 만들어 주세요.
  - `import 'github-markdown-css/github-markdown.css';` 으로 css 를 임포트하고 대상 엘리먼트의 클래스 이름에 `markdown-body` 를 추가해주세요.

  ```tsx
  // # src/component/Home/component/Markdown_2/index.tsx

  import React, { FC } from 'react';
  import Markdown from 'react-markdown';
  import 'github-markdown-css/github-markdown.css'; // <--

  export const Markdown_2: FC<{ children: string }> = ({ children }) => {
    return (
      <>
        <div>Markdown #2</div>
        <div>
          <Markdown className={'markdown-body'}>{children}</Markdown> {/* <--  */}
        </div>
      </>
    );
  };
  ```

- **src/component/Home/index.tsx**

  - Home 에 Markdown_1 컴포넌트를 적용해주세요.

  ```tsx
  // # src/component/Home/index.tsx

  // ...

  import { Markdown_2 } from './component/Markdown_2';

  // ...

  export const Home = () => {
    // ...

    return (
      <Styled_Home>
        <Styled_HomeCard>
          <Markdown_0>{post}</Markdown_0>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_1>{post}</Markdown_1>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_2>{post}</Markdown_2>
        </Styled_HomeCard>
      </Styled_Home>
    );
  };
  ```

&nbsp; 이전보다 훨씬 그럴싸한 모습을 갖추기 시작했습니다.

&nbsp; 다만 아직 HTML 태그의 경우나 코드블럭, 취소선 등이 적용

#### 리액트 마크다운 > 심화 > 3. 마크다운 확장 문법 적용

&nbsp; GitHub 나 최신 markdown 에디터들은 기존 마크다운 문법에 몇 가지 기능을 추가하여 커스터마이징을 하였습니다. 대표적인 기능들은 다음과 같습니다.

- 취소선 (Strikethrough): ~~취소선~~ 형식으로 텍스트에 취소선을 적용할 수 있습니다.
- 테이블 (Tables): 마크다운에서 테이블을 생성하고 표시할 수 있습니다.
- 작업 목록 (Task lists): - [ ] 또는 - [x] 형식으로 체크박스가 있는 할 일 목록을 만들 수 있습니다.
- URL 자동 링크: URL을 직접 입력하면 자동으로 클릭 가능한 링크로 변환됩니다.

&nbsp; remark 을 이용하면 마크다운 문법을 확장하거나 커스터마이징 할 수 있습니다.

&nbsp; remark 는 마크다운 처리에 특화되어 있는 unified 생태계의 일부로, 문서 처리를 위한 도구입니다.

&nbsp; remark 는 마크다운을 파싱하여 mdast(Markdown Abstract Syntax Tree)로 변환해주며, 구문을 검사하고 변경하는 기능을 가지고 있습니다.

&nbsp; react-markdown 에서는 remark 플러그인을 지원합니다. GitHub 의 커스터마이징과 일치하는 플러그인으로는 GFM (Github Flavored Markdown) 이 있습니다.

- **remark 플러그인 GFM 설치**

  ```bash
  npm install remark-gfm
  ```

- **src/component/Home/component/Markdown_3/index.tsx**

  - src/component/Home/component/Markdown_3/ 폴더를 만들고 그 안에 index.tsx 를 만들어 주세요.
  - `import gfm from 'remark-gfm';` 로 리액트를 임포트해줍니다.
  - react-markdown 의 remarkPlugins 옵션 배열에 remark-gfm 를 넣어줍니다.

  ```tsx
  // # src/component/Home/component/Markdown_3/index.tsx

  import React, { FC } from 'react';
  import Markdown from 'react-markdown';
  import GFM from 'remark-gfm'; // <--

  import 'github-markdown-css/github-markdown.css';

  export const Markdown_3: FC<{ children: string }> = ({ children }) => {
    return (
      <>
        <div>Markdown #3</div>
        <div>
          <Markdown
            className={'markdown-body'}
            remarkPlugins={[GFM]} // <--
          >
            {children}
          </Markdown>
        </div>
      </>
    );
  };
  ```

#### 리액트 마크다운 > 심화 > 4. HTML 태그 적용

&nbsp; Markdown 문법은 HTML 문법을 포괄적으로 받아들이기도 합니다.

&nbsp; 단순 문서라면 마크다운 문법만으로도 충분하나 블로그나 설명문에 HTML 의 문법이 더해지면 iframe, 복잡한 표, 또는 사용자 정의 HTML 구조 등 훨씬 풍부한 표현이 가능해지기 때문입니다.

&nbsp; Github 의 마크다운 정책 또한 HTML 문법을 제한적으로 수용합니다. 하지만 일반적인 마크다운 파서는 마크다운의 문법이 아닌 HTML 태그를 단순 텍스트로 처리하거나 아예 무시하기 때문에 별도의 처리가 필요합니다.

&nbsp; rehype 를 이용하면 HTML 요소를 마크다운 문서에 적용할 수 있습니다.

&nbsp; rehype 는 HTML 처리에 특화되어 있는 unified 생태계의 일부로, 문서 처리를 위한 도구입니다.

&nbsp; rehype 는 HTML을 파싱하여 hast(HTML Abstract Syntax Tree)로 변환해주며, HTML 구조를 검사하고 생성하는 기능을 가지고 있습니다.

&nbsp; react-markdown 에서는 rehype 플러그인을 지원합니다. 원시 HTML 태그를 파싱하여 적절한 HTML 구조로 해석해주는 플러그인으로 rehype-raw 가 있습니다.

- **rehype 플러그인 rehype-raw 설치**

  ```bash
  npm install rehype-raw
  ```

- **src/component/Home/component/Markdown_4/index.tsx**

  - src/component/Home/component/Markdown_4/ 폴더를 만들고 그 안에 index.tsx 를 만들어 주세요.
  - `import raw from 'rehype-raw';` 로 리액트를 임포트해줍니다.
  - react-markdown 의 rehypePlugins 옵션 배열에 rehype-raw 를 넣어줍니다.

  ```tsx
  // # src/component/Home/component/Markdown_4/index.tsx

  import React, { FC } from 'react';
  import Markdown from 'react-markdown';
  import GFM from 'remark-gfm';
  import RAW from 'rehype-raw'; // <--

  import 'github-markdown-css/github-markdown.css';

  export const Markdown_4: FC<{ children: string }> = ({ children }) => {
    return (
      <>
        <div>Markdown #4</div>
        <div>
          <Markdown
            className={'markdown-body'}
            remarkPlugins={[GFM]}
            rehypePlugins={[RAW]} // <--
          >
            {children}
          </Markdown>
        </div>
      </>
    );
  };
  ```

#### 리액트 마크다운 > 심화 > 5. XSS(Cross-Site Scripting) 취약점 보완

&nbsp; GitHub README와 동일한 `보안 정책` 을 따르기 위해서는 XSS(Cross-Site Scripting) 보안 취약점을 막아야합니다.

&nbsp; XSS 공격은 웹 애플리케이션의 취약점을 이용하여 공격자가 악성 스크립트를 삽입하고 공격 대상의 브라우저에서 실행되도록 하는 공격 기법입니다.

&nbsp; 기본적으로 rehype 는 HTML 파싱을 하는 과정에서 HTML 입력에 대한 필터링을 하지 않기 때문에, 이 과정에서 악성 스크립트가 포함된 HTML을 그대로 처리할 위험성이 있습니다.

&nbsp; rehype-sanitize 를 이용하면 HTML 을 정화하여 악성코드의 기능을 살균 소독하듯이 무력화 시킬 수 있습니다. 또한, 허용된 HTML 태그만 렌더링되도록 제어하여 차단할 수도 있습니다.

- **rehype 플러그인 rehype-sanitize 설치**

  ```bash
  npm install rehype-sanitize
  ```

- **src/component/Home/component/Markdown_5/index.tsx**

  - src/component/Home/component/Markdown_5/ 폴더를 만들고 그 안에 index.tsx 를 만들어 주세요.
  - `import STZ, { defaultSchema } from 'rehype-sanitize';` 로 임포트해줍니다.
  - react-markdown 의 rehypePlugins 옵션 배열에 rehype-sanitize 객체를 넣어줍니다.
  - rehype-sanitize 객체의 두번째 값은 보안 정책을 제어하는 옵션입니다. 가장 기본적인 보안 정보를 담은 객체 defaultSchema 를 ... 스프레드 연산자로 풀어서 넣어주세요.

  ```tsx
  // # src/component/Home/component/Markdown_5/index.tsx

  import React, { FC } from 'react';
  import Markdown from 'react-markdown';
  import GFM from 'remark-gfm';
  import RAW from 'rehype-raw';
  import STZ, { defaultSchema } from 'rehype-sanitize'; // <--

  import 'github-markdown-css/github-markdown.css';

  export const Markdown_5: FC<{ children: string }> = ({ children }) => {
    return (
      <>
        <div>Markdown #4</div>
        <div>
          <Markdown
            className={'markdown-body'}
            remarkPlugins={[GFM]}
            rehypePlugins={[RAW, [STZ, { ...defaultSchema }]]} // <--
          >
            {children}
          </Markdown>
        </div>
      </>
    );
  };
  ```

  - Github 와 완벽하게 같은 보안 정책은 다음의 설정으로 맞출 수 있습니다.

- **rehype-sanitize의 기본 스키마를 확장하여 GitHub의 보안 정책과 유사한 설정을 만듭니다.**

  - GitHub에서 허용하는 코드 블록 언어들을 추가합니다.
  - GitHub에서 사용하는 특정 클래스명(예: align, width, height 등)을 허용합니다.
  - GitHub 마크다운에서 지원하는 추가 HTML 요소(예: img, input, code, details, summary)를 허용합니다.

  ```tsx
  // # src/component/Home/component/Markdown_5/index.tsx

  import React, { FC } from 'react';
  import Markdown from 'react-markdown';
  import GFM from 'remark-gfm';
  import RAW from 'rehype-raw';
  import STZ from 'rehype-sanitize';

  import 'github-markdown-css/github-markdown.css';

  export const Markdown_5: FC<{ children: string }> = ({ children }) => {
    // * GitHub 스타일의 보안 스키마 정의
    const githubSchema = {
      // ** 태그의 허용할 속성들을 명시적으로 정의
      attributes: {
        // *** 모든 태그에게 허용하는 속성
        '*': ['className', 'id', 'align'],

        // *** 허용하는 코드 블록 언어 속성
        code: ['language-js', 'language-python', 'language-ruby', 'language-java'],

        // *** 허용하는 링크 속성
        a: ['href', 'title', 'target', 'user-mention', 'team-mention', 'issue-link', 'commit-link'],

        // *** 허용하는 이미지 태그 속성
        img: ['src', 'alt', 'title', 'width', 'height'],

        // *** 허용하는 체크박스 속성
        input: ['type', 'checked', 'disabled'],
      },

      // ** 허용하는 HTML 태그 명
      tagNames: [
        'h1',
        'h2',
        'h3',
        'h4',
        'h5',
        'h6',
        'p',
        'div',
        'strong',
        'em',
        'del',
        'a',
        'img',
        'ol',
        'ul',
        'li',
        'input',
        'pre',
        'code',
        'blockquote',
        'table',
        'thead',
        'tbody',
        'tr',
        'th',
        'td',
        'br',
        'hr',
        'details',
        'summary',
      ],

      // ** 추가 보안 설정
      protocols: {
        href: ['http', 'https', 'mailto', 'tel', '#'],
        src: ['http', 'https'],
      },
      clobberPrefix: 'user-content-',
      clobber: ['name', 'id'],
      strip: ['script', 'style', 'xml'],
      allowComments: false,
      allowDoctypes: false,
    };

    return (
      <>
        <div>Markdown #5</div>
        <div>
          <Markdown
            className={'markdown-body'}
            remarkPlugins={[GFM]}
            rehypePlugins={[RAW, [STZ, githubSchema]]} // <--
          >
            {children}
          </Markdown>
        </div>
      </>
    );
  };
  ```

#### 리액트 마크다운 > 심화 > 6. 다듬기

&nbsp; 심화 5단계에서도 몇몇 태그에 CSS 는 적용이 되어있지 않습니다.

&nbsp; 대표적으로 `~~취소선~~` 의 경우 취소선이 적용되지 않을 때가 있습니다.

&nbsp; style.tsx 로 추가적인 CSS 적용을 해주도록 하겠습니다.

- **src/component/Home/component/Markdown_6/style.tsx**

  - src/component/Home/component/Markdown_6/ 폴더를 만들고 그 안에 style.tsx 를 만들어 주세요.
  - style.tsx 에서 스타일을 몰아서 처리하기 위하여 `github-markdown-css` 를 참조하도록 하겠습니다.
  - 취소선은 scss 문법 기준 `& .markdown-body del` 에 해당합니다. `text-decoration: line-through;` 로 가운데를 긋는 선이 그어지도록 설정하겠습니다.

  ```tsx
  // # src/component/Home/component/Markdown_6/style.tsx

  import Styled from 'styled-components';
  import githubMarkdownCss from 'github-markdown-css/github-markdown.css';

  export const Styled_MarkdownBody = Styled.div`
    ${githubMarkdownCss}
  
    & .markdown-body del {
      text-decoration: line-through;
    }
  `;
  ```

- **src/component/Home/component/Markdown_6/index.tsx**

  - src/component/Home/component/Markdown_6/ 폴더를 만들고 그 안에 index.tsx 를 만들어 주세요.
  - Markdown_5/index.tsx 와 나머지 설정은 전부 동일합니다.
  - style.tsx 의 Styled_MarkdownBody 를 가져와서 Markdown 태그를 감싸주세요.

  ```tsx
  // # src/component/Home/component/Markdown_6/index.tsx

  // ...

  import { Styled_MarkdownBody } from './style'; // <--

  export const Markdown_6: FC<{ children: string }> = ({ children }) => {
    // ...

    return (
      <>
        <div>Markdown #6</div>
        <Styled_MarkdownBody>
          <Markdown
            className={'markdown-body'}
            remarkPlugins={[GFM]}
            rehypePlugins={[RAW, [STZ, githubSchema]]} // <--
          >
            {children}
          </Markdown>
        </Styled_MarkdownBody>
      </>
    );
  };
  ```

- **src/component/Home/index.tsx**

  - Home 에 Markdown_6 컴포넌트를 적용해주세요.

  ```tsx
  // # src/component/Home/index.tsx

  import React from 'react';

  import { Markdown_0 } from './component/Markdown_0';
  import { Markdown_1 } from './component/Markdown_1';
  import { Markdown_2 } from './component/Markdown_2';
  import { Markdown_3 } from './component/Markdown_3';
  import { Markdown_4 } from './component/Markdown_4';
  import { Markdown_5 } from './component/Markdown_5';
  import { Markdown_6 } from './component/Markdown_6';

  export const Home = () => {
    // ...

    return (
      <Styled_Home>
        <Styled_HomeCard>
          <Markdown_0>{post}</Markdown_0>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_1>{post}</Markdown_1>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_2>{post}</Markdown_2>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_3>{post}</Markdown_3>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_4>{post}</Markdown_4>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_5>{post}</Markdown_5>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_6>{post}</Markdown_6>
        </Styled_HomeCard>
      </Styled_Home>
    );
  };
  ```

&nbsp; 완성되었습니다. 이제 여러분은 여러분의 페이지에서 github 스타일을 완벽하게 구현할 수 있게 되었습니다.

### 리액트 마크다운 > 심화 > 7. LaTeX 적용

&nbsp; 가끔 수식의 적용이 필요할 경우가 있습니다. github의 마크다운 문서는 LaTeX 문법 기반의 수식 표현을 지원합니다.

- **필요 플러그인 설치**

  ```bash
  # remark-math, rehype-katex, katex 설치
  npm install remark-math rehype-katex katex
  ```

- **src/component/Home/component/Markdown_7/style.tsx**

  - src/component/Home/component/Markdown_7/ 폴더를 만들고 그 안에 style.tsx 를 만들어 주세요.
  - Markdown_6/style.tsx 와 마찬가지로 기존 `github-markdown-css` 가 참조됩니다.
  - LaTeX 수식 구현을 웹화면에 최적화한 KaTeX 플러그인 CSS `katex/dist/katex.min.css` 를 적용합니다.
  - `& .katex msup mn` 의 예시 처럼 index.tsx 에서 `output: 'mathml'` 옵션이 적용되어 있다면 svg 로 만들지 않고 HTML 엘리먼트로 변형하기 때문에 CSS 적용이 가능합니다.

  ```tsx
  // # src/component/Home/component/Markdown_7/style.tsx

  import Styled from 'styled-components';

  import githubMarkdownCss from 'github-markdown-css/github-markdown.css';
  import katexCss from 'katex/dist/katex.min.css'; // <--

  export const Styled_MarkdownBody = Styled.div`
    ${githubMarkdownCss}
    ${katexCss} // <--
  
    & .katex msup mn { font-size: 0.7em; } // <--
    & .katex mrow { margin-top: 0.1rem; } // <--
    & .markdown-body del { text-decoration: line-through; }
  `;
  ```

- **src/component/Home/component/Markdown_7/index.tsx**

  - src/component/Home/component/Markdown_7/ 폴더를 만들고 그 안에 index.tsx 를 만들어 주세요.
  - style.tsx 의 Styled_MarkdownBody 를 가져와서 Markdown 태그를 감싸주세요.
  - githubSchema에 LaTeX 렌더링에 필요한 태그와 속성을 추가했습니다.
  - rehypeKatex 플러그인에 { strict: false } 옵션을 추가하여 더 유연한 LaTeX 파싱을 허용합니다.

  ```tsx
  // # src/component/Home/component/Markdown_7/index.tsx

  import React, { FC } from 'react';
  import Markdown from 'react-markdown';
  import GFM from 'remark-gfm';
  import MAT from 'remark-math'; // <--
  import RAW from 'rehype-raw';
  import STZ from 'rehype-sanitize';
  import KTX from 'rehype-katex'; // <--

  import { Styled_MarkdownBody } from './style';

  // ### Markdown_7
  export const Markdown_7: FC<{ children: string }> = ({ children }) => {
    // #### Variable:
    // ##### githubSchema
    /**
     * @description
     *
     * GitHub 스타일의 커스텀 보안 스키마 입니다.
     *
     * - githubSchema
     *   - attributes : 태그의 허용할 옵션
     *     - '*' : 모든 태그에서 허용할 옵션
     *     - 『HTML_TAG』: 해당 태그에서 허용할 옵션
     *     - code : 코드 블럭에서 허용할 옵션 및 언어
     *       - /^language-./ : 정규표현식, 모든 언어 옵션 허용
     *       - 'language-cpp' : C++
     *       - 'language-csharp' : C#
     *       - 'language-go' : Go
     *       - 'language-java' : Java
     *       - {'language-javascript' | 'language-typescript'} : {JavaScript | TypeScript}
     *       - 'language-php' : PHP
     *       - 'language-python' : Python
     *       - 'language-ruby' : Ruby
     *       - 'language-rust' : Rust
     *       - {'language-shell' | 'language-bash'} : Shell
     *       - 'language-swift': Swift
     *       - 'language-sql' : SQL
     *       - 'language-kotlin' : Kotlin
     *   - tagNames : 허용할 태그
     *   - protocols : 허용하는 프로토콜 보안 설정
     *   - clobberPrefix
     *   - clobber
     *   - strip
     *   - allowComments
     *   - allowDoctypes
     */
    const githubSchema = {
      attributes: {
        '*': ['className', 'id', 'align'],
        input: ['type', 'checked', 'disabled'],
        img: ['src', 'alt', 'title', 'width', 'height'],
        code: [/^language-./, ['math-inline', 'math-display']], // <--
        a: ['href', 'title', 'target', 'user-mention', 'team-mention', 'issue-link', 'commit-link'],
        span: ['className', 'style'],
        div: ['className', 'style'],
      },
      tagNames: [
        'h1',
        'h2',
        'h3',
        'h4',
        'h5',
        'h6',
        'p',
        'strong',
        'b',
        'em',
        'del',
        'a',
        'img',
        'ol',
        'ul',
        'li',
        'input',
        'pre',
        'code',
        'blockquote',
        'table',
        'thead',
        'tbody',
        'tr',
        'th',
        'td',
        'br',
        'hr',
        'details',
        'summary',
        'sup',
        'sub',
        // * LaTeX 렌더링에 필요한 태그 추가
        'span',
        'div',
        'svg',
        'path',
        'annotation',
      ],
      protocols: {
        href: ['http', 'https', 'mailto', 'tel', '#'],
        src: ['http', 'https'],
      },
      clobberPrefix: 'user-content-',
      clobber: ['name', 'id'],
      strip: ['script', 'style', 'xml'],
      allowComments: false,
      allowDoctypes: false,
    };

    return (
      <>
        <div>Markdown #7</div>
        <Styled_MarkdownBody>
          <Markdown
            className={'markdown-body'}
            remarkPlugins={[GFM, MAT]} // <--
            rehypePlugins={[RAW, [STZ, githubSchema], [KTX, { strict: false, output: 'mathml' }]]} // <--
          >
            {children}
          </Markdown>
        </Styled_MarkdownBody>
      </>
    );
  };
  ```

- **src/component/Home/index.tsx**

  - Home 에 Markdown_7 컴포넌트를 적용해주세요.

  ```tsx
  // # src/component/Home/index.tsx

  import React from 'react';

  // ...

  import { Markdown_7 } from './component/Markdown_7';

  // ...

  export const Home = () => {
    // ...

    return (
      <Styled_Home>
        <Styled_HomeCard>
          <Markdown_0>{post}</Markdown_0>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_1>{post}</Markdown_1>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_2>{post}</Markdown_2>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_3>{post}</Markdown_3>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_4>{post}</Markdown_4>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_5>{post}</Markdown_5>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_6>{post}</Markdown_6>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_7>{post}</Markdown_7>
        </Styled_HomeCard>
      </Styled_Home>
    );
  };
  ```

### 리액트 마크다운 > 심화 > 8. 코드 하이라이트 적용

&nbsp; 코드 블럭에 IDE 처럼 하이라이트 색상을 부여하여 구문 강조를 적용하면 코드의 가독성이 좋아집니다.

&nbsp; github 도 몇 가지 언어에 대해서 코드 하이라이트를 지원합니다.

&nbsp; github 와 완전히 일치하는 하이라이트 스타일을 구현하는 쪽은 훨씬 복잡하기 때문에 이 부분은 react-syntax-highlighter 에서 지원하는 다른 스타일로 대체 하겠습니다.

- **필요 플러그인 설치**

  ```bash
  # react-syntax-highlighter 과 타입정보 패키지를 설치합니다.
  # 설치된 버전이 다를 경우, 같은 버전으로 맞춰주세요.
  npm install react-syntax-highlighter @types/react-syntax-highlighter;
  ```

- **src/component/Home/component/Markdown_8/style.tsx**

  - src/component/Home/component/Markdown_8/ 폴더를 만들고 그 안에 style.tsx 를 만들어 주세요.
  - Markdown_7/style.tsx 와 마찬가지로 기존 `github-markdown-css` 가 참조됩니다.
  - Markdown_7/style.tsx 와 마찬가지로 기존 `katex/dist/katex.min.css` 가 참조됩니다.
  - `& .syntax-highlighter { background-color: transparent !important; }` 코드를 추가하여 배경색은 스타일의 영향을 받지 않도록 막겠습니다.

  ```tsx
  // # src/component/Home/component/Markdown_8/style.tsx

  import Styled from 'styled-components';

  import githubMarkdownCss from 'github-markdown-css/github-markdown.css';
  import katexCss from 'katex/dist/katex.min.css';

  // ## Style ==================================================================

  export const Styled_MarkdownBody = Styled.div`
    ${githubMarkdownCss}
    ${katexCss}
  
    & .syntax-highlighter { background-color: transparent !important; } // <--
    & .katex msup mn { font-size: 0.7em; }
    & .katex mrow { margin-top: 0.1rem; }
    & .markdown-body del { text-decoration: line-through; }
  `;
  ```

- **src/component/Home/component/Markdown_8/index.tsx**

  - src/component/Home/component/Markdown_8/ 폴더를 만들고 그 안에 index.tsx 를 만들어 주세요.
  - style.tsx 의 Styled_MarkdownBody 를 가져와서 Markdown 태그를 감싸주세요.
  - 필요한 라이브러리들을 임포트해주세요.
    - Light 또는 Prism 을 SyntaxHighlighter 이름으로 임포트 합니다. 나중에 종류를 바꿀 때에 유용합니다.
    - 필요한 코드블록 스타일을 찾아 임포트합니다.
      - Light 의 경우 `'react-syntax-highlighter/dist/esm/styles/hljs'` 경로에 있습니다.
      - Prism 의 경우 `'react-syntax-highlighter/dist/esm/styles/prism'` 경로에 있습니다.
    - 필요한 언어 정보를 찾아 임포트합니다.
      - Light 의 경우 `'react-syntax-highlighter/dist/esm/languages/hljs/...'` 경로에 있습니다.
      - Prism 의 경우 `'react-syntax-highlighter/dist/esm/languages/prism/...'` 경로에 있습니다.
  - `const supportedLanguages: string[]` 스트링 배열을 선언하여 적용할 코드블럭 종류를 정해주세요.
  - 적용할 코드 스타일을 신택스 하이라이터의 registerLanguage 함수로 등록해주세요.
  - `const components = {...}` 객체로 code 태그를 신택스 하이라이터 컴포넌트로 변환하는 코드를 작성합니다.
  - react-markdown의 components 속성에 앞에서 만든 components 객체를 적용합니다.

  ```tsx
  // # src/component/Home/component/Markdown_8/index.tsx

  // ...

  import { Components } from 'react-markdown/lib/index';
  import { Light as SyntaxHighlighter } from 'react-syntax-highlighter';
  import { vs as SyntaxStyle } from 'react-syntax-highlighter/dist/esm/styles/hljs';
  import cpp from 'react-syntax-highlighter/dist/esm/languages/hljs/cpp';
  import java from 'react-syntax-highlighter/dist/esm/languages/hljs/java';
  import js from 'react-syntax-highlighter/dist/esm/languages/hljs/javascript';

  // ...

  export const Markdown_8: FC<{ children: string }> = ({ children }) => {
    // ...

    /**
     * @description 적용할 코드블럭 언어의 종류를 지정합니다.
     */
    const supportedLanguages: string[] = ['cpp', 'java', 'javascript'];
    SyntaxHighlighter.registerLanguage('cpp', cpp);
    SyntaxHighlighter.registerLanguage('java', java);
    SyntaxHighlighter.registerLanguage('javascript', js);

    // ...

    /**
     * @description 코드블럭 태그 <code></code> 를 스타일에 맞게 <SyntaxHighlighter></SyntaxHighlighter> 로 변환하는 조건을 정합니다.
     */
    const components = {
      code: ({
        inline,
        className,
        children,
        ...props
      }: {
        inline?: boolean;
        className?: string;
        children: React.ReactNode;
      }) => {
        const match = /language-(\w+)/.exec(className || '');
        return !inline && match && supportedLanguages.includes(match[1]) ? (
          <SyntaxHighlighter
            class="syntax-highlighter"
            style={SyntaxStyle}
            language={match[1]}
            PreTag="div"
            {...props}
          >
            {String(children).replace(/\n$/, '')}
          </SyntaxHighlighter>
        ) : (
          <code className={className} {...props}>
            {children}
          </code>
        );
      },
    } as Components;

    // ...

    return (
      <>
        <div>Markdown #8</div>
        <Styled_MarkdownBody>
          <Markdown
            className={'markdown-body'}
            remarkPlugins={[GFM, MAT]}
            rehypePlugins={[RAW, [STZ, githubSchema], [KTX, { strict: false, output: 'mathml' }]]}
            components={components} // <--
          >
            {children}
          </Markdown>
        </Styled_MarkdownBody>
      </>
    );
  };
  ```

- **src/component/Home/index.tsx**

  - Home 에 Markdown_8 컴포넌트를 적용해주세요.

  ```tsx
  // # src/component/Home/index.tsx

  import React from 'react';

  // ...

  import { Markdown_8 } from './component/Markdown_8';

  // ...

  export const Home = () => {
    // ...

    return (
      <Styled_Home>
        <Styled_HomeCard>
          <Markdown_0>{post}</Markdown_0>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_1>{post}</Markdown_1>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_2>{post}</Markdown_2>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_3>{post}</Markdown_3>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_4>{post}</Markdown_4>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_5>{post}</Markdown_5>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_6>{post}</Markdown_6>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_7>{post}</Markdown_7>
        </Styled_HomeCard>
        <Styled_HomeCard>
          <Markdown_8>{post}</Markdown_8>
        </Styled_HomeCard>
      </Styled_Home>
    );
  };
  ```

### 리액트 마크다운 > 심화 > 9. API 화

&nbsp; 이제 어디서든 응용할 수 있도록 API 화를 시키도록 하겠습니다.

&nbsp; 사실상 심화 8 까지 과정을 묶어서 api 폴더로 옮기면 됩니다.

- **src/api/markdown/style.tsx**

  - src/api/markdown/ 폴더를 만들고 그 안에 다음과 같이 style.tsx 를 만들어주세요.

  ```tsx
  // # src/api/markdown/style.tsx

  // ## Documentation ==========================================================
  /**
   *
   * 마크다운 양식의 세부적인 스타일을 조정합니다.
   *
   * @dependencies
   * - [x] github-markdown-css
   * - [x] katex
   */

  // ## Import Declaration =====================================================

  // ### API & Library:

  import Styled from 'styled-components';

  // ### Style:

  import githubMarkdownCss from 'github-markdown-css/github-markdown.css';
  import katexCss from 'katex/dist/katex.min.css';

  // ## Style ==================================================================

  export const Styled_Markdown = Styled.div`
    ${githubMarkdownCss}
    ${katexCss}
  
    & .syntax-highlighter { background-color: transparent !important; }
    & .katex msup mn { font-size: 0.7em; }
    & .katex mrow { margin-top: 0.1rem; }
    & .markdown-body del { text-decoration: line-through; }
  `;
  ```

  - **src/api/markdown/index.tsx**

  - src/api/markdown/ 폴더를 만들고 그 안에 다음과 같이 index.tsx 를 만들어주세요.

  ```tsx
  // # src/api/markdown/index.tsx

  // ## Documentation ==========================================================
  /**
   * @description
   *
   * 마크다운 양식을 읽는 리액트 컴포넌트 API 입니다.
   *
   * @dependencies
   * - [x] react-markdown
   * - [x] remark-gfm
   * - [x] remark-math
   * - [x] rehype-raw
   * - [x] rehype-sanitize
   * - [x] rehype-katex
   * - [x] react-syntax-highlighter
   * - [x] @types/react-syntax-highlighter
   *
   * @author inte99ral
   * @version 2024-12-15
   */

  // ## Import Declaration =====================================================

  // ### API & Library:

  import React, { FC } from 'react';
  import ReactMarkdown from 'react-markdown';
  import { Components } from 'react-markdown/lib/index';

  import GFM from 'remark-gfm';
  import MAT from 'remark-math';

  import RAW from 'rehype-raw';
  import STZ from 'rehype-sanitize';
  import KTX from 'rehype-katex';

  import { Light as SyntaxHighlighter } from 'react-syntax-highlighter';
  import { vs as SyntaxStyle } from 'react-syntax-highlighter/dist/esm/styles/hljs';
  import cpp from 'react-syntax-highlighter/dist/esm/languages/hljs/cpp';
  import java from 'react-syntax-highlighter/dist/esm/languages/hljs/java';
  import js from 'react-syntax-highlighter/dist/esm/languages/hljs/javascript';

  // ### Style:
  import { Styled_Markdown } from './style';

  // ## Variable & Constant ====================================================

  const supportedLanguages: string[] = ['cpp', 'java', 'javascript'];
  SyntaxHighlighter.registerLanguage('cpp', cpp);
  SyntaxHighlighter.registerLanguage('java', java);
  SyntaxHighlighter.registerLanguage('javascript', js);

  // ## Component ==============================================================

  // ### Markdown
  export const Markdown: FC<{ children: string }> = ({ children }) => {
    // #### Variable:
    // ##### schema
    /**
     * @description
     *
     * 커스텀 보안 정보가 담긴 스키마 입니다.
     *
     * - schema
     *   - attributes : 태그의 허용할 옵션
     *     - '*' : 모든 태그에서 허용할 옵션
     *     - 『HTML_TAG』: 해당 태그에서 허용할 옵션
     *     - code : 코드 블럭에서 허용할 옵션 및 언어
     *       - /^language-./ : 정규표현식, 모든 언어 옵션 허용
     *       - 'language-cpp' : C++
     *       - 'language-csharp' : C#
     *       - 'language-go' : Go
     *       - 'language-java' : Java
     *       - {'language-javascript' | 'language-typescript'} : {JavaScript | TypeScript}
     *       - 'language-php' : PHP
     *       - 'language-python' : Python
     *       - 'language-ruby' : Ruby
     *       - 'language-rust' : Rust
     *       - {'language-shell' | 'language-bash'} : Shell
     *       - 'language-swift': Swift
     *       - 'language-sql' : SQL
     *       - 'language-kotlin' : Kotlin
     *   - tagNames : 허용할 태그
     *   - protocols : 허용하는 프로토콜 보안 설정
     *   - clobberPrefix
     *   - clobber
     *   - strip
     *   - allowComments
     *   - allowDoctypes
     */
    const schema = {
      attributes: {
        '*': ['className', 'id', 'align'],
        input: ['type', 'checked', 'disabled'],
        img: ['src', 'alt', 'title', 'width', 'height'],
        code: [/^language-./, ['math-inline', 'math-display']], // <--
        a: ['href', 'title', 'target', 'user-mention', 'team-mention', 'issue-link', 'commit-link'],
        span: ['className', 'style'],
        div: ['className', 'style'],
      },
      tagNames: [
        'h1',
        'h2',
        'h3',
        'h4',
        'h5',
        'h6',
        'p',
        'strong',
        'b',
        'em',
        'del',
        'a',
        'img',
        'ol',
        'ul',
        'li',
        'input',
        'pre',
        'code',
        'blockquote',
        'table',
        'thead',
        'tbody',
        'tr',
        'th',
        'td',
        'br',
        'hr',
        'details',
        'summary',
        'sup',
        'sub',
        'span',
        'div',
        'svg',
        'path',
        'annotation',
      ],
      protocols: {
        href: ['http', 'https', 'mailto', 'tel', '#'],
        src: ['http', 'https'],
      },
      clobberPrefix: 'user-content-',
      clobber: ['name', 'id'],
      strip: ['script', 'style', 'xml'],
      allowComments: false,
      allowDoctypes: false,
    };

    // ##### components
    /**
     * @description 코드블럭 태그 <code></code> 를 스타일에 맞게 <SyntaxHighlighter></SyntaxHighlighter> 로 변환하는 조건을 정합니다.
     */
    const components = {
      code: ({
        inline,
        className,
        children,
        ...props
      }: {
        inline?: boolean;
        className?: string;
        children: React.ReactNode;
      }) => {
        const match = /language-(\w+)/.exec(className || '');
        return !inline && match && supportedLanguages.includes(match[1]) ? (
          <SyntaxHighlighter
            class="syntax-highlighter"
            style={SyntaxStyle}
            language={match[1]}
            PreTag="div"
            {...props}
          >
            {String(children).replace(/\n$/, '')}
          </SyntaxHighlighter>
        ) : (
          <code className={className} {...props}>
            {children}
          </code>
        );
      },
    } as Components;

    // #### Return:
    return (
      <Styled_Markdown>
        <ReactMarkdown
          className={'markdown-body'}
          remarkPlugins={[GFM, MAT]}
          rehypePlugins={[RAW, [STZ, schema], [KTX, { strict: false, output: 'mathml' }]]}
          components={components}
        >
          {children}
        </ReactMarkdown>
      </Styled_Markdown>
    );
  };
  ```

&nbsp; 이제부터 언제나 `import { Markdown } from 'api/markdown';` 으로 마크다운을 읽을 수 있습니다.
&nbsp; Home/index.tsx 에서도 다음과 같이 바로 사용할 수 있습니다.

- **src/component/Home/index.tsx**

  - Home 에 Markdown api 를 사용합니다.

  ```tsx
  // # src/component/Home/index.tsx

  import React from 'react';
  import { Markdown } from 'api/markdown'; // <--

  // ...

  export const Home = () => {
    // ...

    return (
      <Styled_Home>
        // ...
        <Styled_HomeCard>
          <div>Markdown #9</div> // <--
          <Markdown>{post}</Markdown> // <--
        </Styled_HomeCard>
      </Styled_Home>
    );
  };
  ```

### 리액트 마크다운 > 심화 > 10. REST API 적용

&nbsp; 마크다운 데이터를 REST API 를 통해서 가져오도록 하겠습니다.

&nbsp; `리액트 마크다운 > 심화 > 0. 사전정리작업` 문단에서 `REST API > localhost 에 대한 이해` 문단의 정보를 기반으로 하여 "public/server/post/9/" 경로에 0.png 파일을 넣었던 것 기억나시나요?

&nbsp; 이제 "public/server/post/9" 경로에 "index.md" 라는 마크다운 파일을 만들고 REST API 로 불러올 것 입니다.

&nbsp; 굳이 예제로 9 을 글 번호로 정한 이유는 0 번 에셋 번호와 헷갈리지 않도록 일부러 다른 번호가 되도록 하기 위함이었습니다. "public/server/post/9/0.png" 는 9번 글의 0번 에셋 임을 명시합니다.

&nbsp; 이 디렉터리 구조는 "public/server/post/『POST_NUMBER』/index.md" 파일이 참조하는 에셋은 "public/server/post/『POST_NUMBER』/『ASSET_NUMBER』" 로 찾을 수 있도록 한 구조입니다.

&nbsp; 최대한 서버없이 RESTful 한 척을 유지하기 위한 구조이기 때문에 응용하실 때는 이 구조를 따르지 않으셔도 됩니다.

- **public/server/post/9/index.md**

  - public/server/post/9/ 폴더에 index.md 파일을 만들어 주세요.
  - 테스트 용으로 가볍게 적겠습니다.

  ```md
  # Example 유저 내역

  ## 목록

  - 홍길동
  - 전우치
  ```

  &nbsp; 이제 `http://localhost:『PORT_NUMBER』/server/post/9/index.md` 주소에서 해당 파일에 접근할 수 있습니다.

- **src/api/rest/post/index.ts**

  &nbsp; REST API 환경 조성이 사전에 필요합니다.

  &nbsp; src/api/rest/ 폴더에 post/ 폴더를 추가한 뒤, index.ts 를 만들어주세요.

```ts
// # src/api/rest/post/index.tsx

// ## Documentation ==========================================================
/**
 * @description
 *
 * 포스팅 될 글들을 마크다운 양식으로 다루는 함수들 입니다.
 *
 * @author inte99ral
 * @version 2024-12-13
 */

// ## Import Declaration =====================================================

// ### API & Library:

import { AxiosApi } from 'api/axios';

// ## Variable & Constant ====================================================

const postAxios = AxiosApi.getAPI().getInstance('post');

// ## Function ===============================================================

export const getPost = (id: number) => {
  return new Promise<string>((resolve, reject) => {
    postAxios
      ?.get(`/${id}/index.md`, { responseType: 'text' })
      .then((responce) => {
        resolve(responce.data);
      })
      .catch((error) => {
        reject(error);
      });
  });
};
```

- **src/component/Home/index.tsx**

  - Home 에 REST API 를 적용해주세요.

  ```tsx
  // # src/component/Home/index.tsx

  import React from 'react';

  // ...

  import React, { useState, useEffect } from 'react';
  import { getPost } from 'api/rest/post';

  // ...

  export const Home = () => {
    // ...

    const [post, setPost] = useState('');

    useEffect(() => {
      (async () => {
        setPost(await getPost(1));
      })();
    }, []);

    // ...

    return <Styled_Home>...</Styled_Home>;
  };
  ```

&nbsp; 이제 마크다운의 적용이 끝났습니다.

## 사이트 디자인
