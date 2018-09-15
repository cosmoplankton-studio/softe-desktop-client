





<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
  <link rel="dns-prefetch" href="https://assets-cdn.github.com">
  <link rel="dns-prefetch" href="https://avatars0.githubusercontent.com">
  <link rel="dns-prefetch" href="https://avatars1.githubusercontent.com">
  <link rel="dns-prefetch" href="https://avatars2.githubusercontent.com">
  <link rel="dns-prefetch" href="https://avatars3.githubusercontent.com">
  <link rel="dns-prefetch" href="https://github-cloud.s3.amazonaws.com">
  <link rel="dns-prefetch" href="https://user-images.githubusercontent.com/">



  <link crossorigin="anonymous" media="all" integrity="sha512-ffMzRgUi/mtdt6xiC1jtSP1kZPeTBajWgak1AnijhQVTr6eCui3vcdxCvFCJjbjAXg730wT/i/rceI+PIwS6kQ==" rel="stylesheet" href="https://assets-cdn.github.com/assets/frameworks-c4bbb32afb602dcf8c75be0bc4c83014.css" />
  <link crossorigin="anonymous" media="all" integrity="sha512-s8gtUCQADtfctIBspyFVUayzGX7kbK+w0nIeV7gp8DZLI7IBWjEJMyyN9nxeFKogu9/ZYmdhtrqKp+xeMuVXEw==" rel="stylesheet" href="https://assets-cdn.github.com/assets/github-393fa18b1758491727794aa1b8bdff7a.css" />
  
  
  
  

  <meta name="viewport" content="width=device-width">
  
  <title>stb/stb_image_write.h at master · nothings/stb</title>
    <meta name="description" content="GitHub is where people build software. More than 27 million people use GitHub to discover, fork, and contribute to over 80 million projects.">
  <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub">
  <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub">
  <meta property="fb:app_id" content="1401488693436528">

    
    <meta property="og:image" content="https://avatars0.githubusercontent.com/u/7525026?s=400&amp;v=4" /><meta property="og:site_name" content="GitHub" /><meta property="og:type" content="object" /><meta property="og:title" content="nothings/stb" /><meta property="og:url" content="https://github.com/nothings/stb" /><meta property="og:description" content="stb single-file public domain libraries for C/C++" />

  <link rel="assets" href="https://assets-cdn.github.com/">
  <link rel="web-socket" href="wss://live.github.com/_sockets/VjI6MjMwODMxNTk4OjRmMmMwNTAwZTM0NWRiMGVhYzEwNDdiZmM5ZjQ4ZDk1ZmJlYjNhZDQ4ODg4NjZjNTU3NTYzNDJhNTdkMTI0ZDY=--8bca93ef38b292220d58ec3fbbacc886c8de2bb4">
  <meta name="pjax-timeout" content="1000">
  <link rel="sudo-modal" href="/sessions/sudo_modal">
  <meta name="request-id" content="77D4:55D2:3A4A5B6:6FA050D:5AE3D736" data-pjax-transient>


  

  <meta name="selected-link" value="repo_source" data-pjax-transient>

    <meta name="google-site-verification" content="KT5gs8h0wvaagLKAVWq8bbeNwnZZK1r1XQysX3xurLU">
  <meta name="google-site-verification" content="ZzhVyEFwb7w3e0-uOTltm8Jsck2F5StVihD0exw2fsA">
  <meta name="google-site-verification" content="GXs5KoUUkNCoaAZn7wPN-t01Pywp9M3sEjnt_3_ZWPc">
    <meta name="google-analytics" content="UA-3769691-2">

<meta name="octolytics-host" content="collector.githubapp.com" /><meta name="octolytics-app-id" content="github" /><meta name="octolytics-event-url" content="https://collector.githubapp.com/github-external/browser_event" /><meta name="octolytics-dimension-request_id" content="77D4:55D2:3A4A5B6:6FA050D:5AE3D736" /><meta name="octolytics-dimension-region_edge" content="iad" /><meta name="octolytics-dimension-region_render" content="iad" /><meta name="octolytics-actor-id" content="11255740" /><meta name="octolytics-actor-login" content="cosmoplankton" /><meta name="octolytics-actor-hash" content="396a13f86e5d11014fa136c03c548bdeec026110f7c7839a6f3d06cb8ecb28cd" />
<meta name="analytics-location" content="/&lt;user-name&gt;/&lt;repo-name&gt;/blob/show" data-pjax-transient="true" />




  <meta class="js-ga-set" name="dimension1" content="Logged In">


  

      <meta name="hostname" content="github.com">
    <meta name="user-login" content="cosmoplankton">

      <meta name="expected-hostname" content="github.com">
    <meta name="js-proxy-site-detection-payload" content="MGRlYzAyOWI1MjdhYmRkM2Q2MDFhZmFhZTJkNzAwYWUzMzg3MjkzMjAzODg3ZGJlNGRkY2I2ODE0NWQ4ZjM2Ynx7InJlbW90ZV9hZGRyZXNzIjoiMTgzLjgyLjE5LjQyIiwicmVxdWVzdF9pZCI6Ijc3RDQ6NTVEMjozQTRBNUI2OjZGQTA1MEQ6NUFFM0Q3MzYiLCJ0aW1lc3RhbXAiOjE1MjQ4ODEyMjIsImhvc3QiOiJnaXRodWIuY29tIn0=">

    <meta name="enabled-features" content="UNIVERSE_BANNER,FREE_TRIALS,MARKETPLACE_INSIGHTS,MARKETPLACE_SELF_SERVE,MARKETPLACE_FREE_APPS,MARKETPLACE_INSIGHTS_CONVERSION_PERCENTAGES">

  <meta name="html-safe-nonce" content="2f1bb3b72cc707ba3ad559e105ff2852b47f50c1">

  <meta http-equiv="x-pjax-version" content="f06547c83214549a4e68c8ff4eed68fc">
  

      <link href="https://github.com/nothings/stb/commits/master.atom" rel="alternate" title="Recent Commits to stb:master" type="application/atom+xml">

  <meta name="description" content="stb single-file public domain libraries for C/C++">
  <meta name="go-import" content="github.com/nothings/stb git https://github.com/nothings/stb.git">

  <meta name="octolytics-dimension-user_id" content="7525026" /><meta name="octolytics-dimension-user_login" content="nothings" /><meta name="octolytics-dimension-repository_id" content="20159867" /><meta name="octolytics-dimension-repository_nwo" content="nothings/stb" /><meta name="octolytics-dimension-repository_public" content="true" /><meta name="octolytics-dimension-repository_is_fork" content="false" /><meta name="octolytics-dimension-repository_network_root_id" content="20159867" /><meta name="octolytics-dimension-repository_network_root_nwo" content="nothings/stb" /><meta name="octolytics-dimension-repository_explore_github_marketplace_ci_cta_shown" content="false" />


    <link rel="canonical" href="https://github.com/nothings/stb/blob/master/stb_image_write.h" data-pjax-transient>


  <meta name="browser-stats-url" content="https://api.github.com/_private/browser/stats">

  <meta name="browser-errors-url" content="https://api.github.com/_private/browser/errors">

  <link rel="mask-icon" href="https://assets-cdn.github.com/pinned-octocat.svg" color="#000000">
  <link rel="icon" type="image/x-icon" class="js-site-favicon" href="https://assets-cdn.github.com/favicon.ico">

<meta name="theme-color" content="#1e2327">


  <meta name="u2f-support" content="true">

<link rel="manifest" href="/manifest.json" crossOrigin="use-credentials">

  </head>

  <body class="logged-in env-production page-blob">
    

  <div class="position-relative js-header-wrapper ">
    <a href="#start-of-content" tabindex="1" class="p-3 bg-blue text-white show-on-focus js-skip-to-content">Skip to content</a>
    <div id="js-pjax-loader-bar" class="pjax-loader-bar"><div class="progress"></div></div>

    
    
    



        
<header class="Header  f5" role="banner">
  <div class="d-flex flex-justify-between px-3 container-lg">
    <div class="d-flex flex-justify-between ">
      <div class="">
        <a class="header-logo-invertocat" href="https://github.com/" data-hotkey="g d" aria-label="Homepage" data-ga-click="Header, go to dashboard, icon:logo">
  <svg height="32" class="octicon octicon-mark-github" viewBox="0 0 16 16" version="1.1" width="32" aria-hidden="true"><path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0 0 16 8c0-4.42-3.58-8-8-8z"/></svg>
</a>

      </div>

    </div>

    <div class="HeaderMenu d-flex flex-justify-between flex-auto">
      <div class="d-flex">
            <div class="">
              <div class="header-search scoped-search site-scoped-search js-site-search" role="search">
  <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="js-site-search-form" data-scope-type="Repository" data-scope-id="20159867" data-scoped-search-url="/nothings/stb/search" data-unscoped-search-url="/search" action="/nothings/stb/search" accept-charset="UTF-8" method="get"><input name="utf8" type="hidden" value="&#x2713;" />
    <label class="form-control header-search-wrapper  js-chromeless-input-container">
          <a class="header-search-scope no-underline" href="/nothings/stb/blob/master/stb_image_write.h">This repository</a>
      <input type="text"
        class="form-control header-search-input  js-site-search-focus js-site-search-field is-clearable"
        data-hotkey="s,/"
        name="q"
        value=""
        placeholder="Search"
        aria-label="Search this repository"
        data-unscoped-placeholder="Search GitHub"
        data-scoped-placeholder="Search"
        autocapitalize="off"
        >
        <input type="hidden" class="js-site-search-type-field" name="type" >
    </label>
</form></div>

            </div>

          <ul class="d-flex pl-2 flex-items-center text-bold list-style-none" role="navigation">
            <li>
              <a class="js-selected-navigation-item HeaderNavlink px-2" data-hotkey="g p" data-ga-click="Header, click, Nav menu - item:pulls context:user" aria-label="Pull requests you created" data-selected-links="/pulls /pulls/assigned /pulls/mentioned /pulls" href="/pulls">
                Pull requests
</a>            </li>
            <li>
              <a class="js-selected-navigation-item HeaderNavlink px-2" data-hotkey="g i" data-ga-click="Header, click, Nav menu - item:issues context:user" aria-label="Issues you created" data-selected-links="/issues /issues/assigned /issues/mentioned /issues" href="/issues">
                Issues
</a>            </li>
                <li>
                  <a class="js-selected-navigation-item HeaderNavlink px-2" data-ga-click="Header, click, Nav menu - item:marketplace context:user" data-octo-click="marketplace_click" data-octo-dimensions="location:nav_bar, group:" data-selected-links=" /marketplace" href="/marketplace">
                    Marketplace
</a>                </li>
            <li>
              <a class="js-selected-navigation-item HeaderNavlink px-2" data-ga-click="Header, click, Nav menu - item:explore" data-selected-links="/explore /trending /trending/developers /integrations /integrations/feature/code /integrations/feature/collaborate /integrations/feature/ship showcases showcases_search showcases_landing /explore" href="/explore">
                Explore
</a>            </li>
          </ul>
      </div>

      <div class="d-flex">
        
<ul class="user-nav d-flex flex-items-center list-style-none" id="user-links">
  <li class="dropdown js-menu-container">
    <span class="d-inline-block  px-2">
      
    <a aria-label="You have no unread notifications" class="notification-indicator tooltipped tooltipped-s  js-socket-channel js-notification-indicator" data-hotkey="g n" data-ga-click="Header, go to notifications, icon:read" data-channel="notification-changed:11255740" href="/notifications">
        <span class="mail-status "></span>
        <svg class="octicon octicon-bell" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M14 12v1H0v-1l.73-.58c.77-.77.81-2.55 1.19-4.42C2.69 3.23 6 2 6 2c0-.55.45-1 1-1s1 .45 1 1c0 0 3.39 1.23 4.16 5 .38 1.88.42 3.66 1.19 4.42l.66.58H14zm-7 4c1.11 0 2-.89 2-2H5c0 1.11.89 2 2 2z"/></svg>
</a>
    </span>
  </li>

  <li class="dropdown js-menu-container">
    <details class="dropdown-details details-reset js-dropdown-details d-flex px-2 flex-items-center">
      <summary class="HeaderNavlink"
         aria-label="Create new…"
         data-ga-click="Header, create new, icon:add">
        <svg class="octicon octicon-plus float-left mr-1 mt-1" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 9H7v5H5V9H0V7h5V2h2v5h5z"/></svg>
        <span class="dropdown-caret mt-1"></span>
      </summary>

      <ul class="dropdown-menu dropdown-menu-sw">
        
<a class="dropdown-item" href="/new" data-ga-click="Header, create new repository">
  New repository
</a>

  <a class="dropdown-item" href="/new/import" data-ga-click="Header, import a repository">
    Import repository
  </a>

<a class="dropdown-item" href="https://gist.github.com/" data-ga-click="Header, create new gist">
  New gist
</a>

  <a class="dropdown-item" href="/organizations/new" data-ga-click="Header, create new organization">
    New organization
  </a>



  <div class="dropdown-divider"></div>
  <div class="dropdown-header">
    <span title="nothings/stb">This repository</span>
  </div>
    <a class="dropdown-item" href="/nothings/stb/issues/new" data-ga-click="Header, create new issue">
      New issue
    </a>

      </ul>
    </details>
  </li>

  <li class="dropdown js-menu-container">

    <details class="dropdown-details details-reset js-dropdown-details d-flex pl-2 flex-items-center">
      <summary class="HeaderNavlink name mt-1"
        aria-label="View profile and more"
        data-ga-click="Header, show menu, icon:avatar">
        <img alt="@cosmoplankton" class="avatar float-left mr-1" src="https://avatars1.githubusercontent.com/u/11255740?s=40&amp;v=4" height="20" width="20">
        <span class="dropdown-caret"></span>
      </summary>

      <ul class="dropdown-menu dropdown-menu-sw">
        <li class="dropdown-header header-nav-current-user css-truncate">
          Signed in as <strong class="css-truncate-target">cosmoplankton</strong>
        </li>

        <li class="dropdown-divider"></li>

        <li><a class="dropdown-item" href="/cosmoplankton" data-ga-click="Header, go to profile, text:your profile">
          Your profile
        </a></li>
        <li><a class="dropdown-item" href="/cosmoplankton?tab=stars" data-ga-click="Header, go to starred repos, text:your stars">
          Your stars
        </a></li>
          <li><a class="dropdown-item" href="https://gist.github.com/" data-ga-click="Header, your gists, text:your gists">Your gists</a></li>

        <li class="dropdown-divider"></li>

        <li><a class="dropdown-item" href="https://help.github.com" data-ga-click="Header, go to help, text:help">
          Help
        </a></li>

        <li><a class="dropdown-item" href="/settings/profile" data-ga-click="Header, go to settings, icon:settings">
          Settings
        </a></li>

        <li><!-- '"` --><!-- </textarea></xmp> --></option></form><form class="logout-form" action="/logout" accept-charset="UTF-8" method="post"><input name="utf8" type="hidden" value="&#x2713;" /><input type="hidden" name="authenticity_token" value="2xVw+TdC6FNojXs7bFMuNm4KOphZv4XcK2bdv4Gg6RR97yZcVs7OvFrVLIwTvWKg/c/h+MPUwMb5drn+G3lY3A==" />
          <button type="submit" class="dropdown-item dropdown-signout" data-ga-click="Header, sign out, icon:logout">
            Sign out
          </button>
        </form></li>
      </ul>
    </details>
  </li>
</ul>



        <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="sr-only right-0" action="/logout" accept-charset="UTF-8" method="post"><input name="utf8" type="hidden" value="&#x2713;" /><input type="hidden" name="authenticity_token" value="vKLN42VuE3IHcT1PjiV+hwQaCJp4JwYsU/GUfg1XNHIaWJtGBOI1nTUpavjxyzIRl9/T+uJMQzaB4fA/l46Fug==" />
          <button type="submit" class="dropdown-item dropdown-signout" data-ga-click="Header, sign out, icon:logout">
            Sign out
          </button>
</form>      </div>
    </div>
  </div>
</header>

      

  </div>

  <div id="start-of-content" class="show-on-focus"></div>

    <div id="js-flash-container">
</div>



  <div role="main" class="application-main ">
        <div itemscope itemtype="http://schema.org/SoftwareSourceCode" class="">
    <div id="js-repo-pjax-container" data-pjax-container >
      







  <div class="pagehead repohead instapaper_ignore readability-menu experiment-repo-nav  ">
    <div class="repohead-details-container clearfix container">

      <ul class="pagehead-actions">
  <li>
        <!-- '"` --><!-- </textarea></xmp> --></option></form><form data-autosubmit="true" data-remote="true" class="js-social-container" action="/notifications/subscribe" accept-charset="UTF-8" method="post"><input name="utf8" type="hidden" value="&#x2713;" /><input type="hidden" name="authenticity_token" value="HdXvxrWeWcJ1dhqoEjWdsOJ6ZyTZA/0g3qjvP/UTgCFqhYL6q88Lesc31nXTmZu7PFsETPmdlQaMJHJh9rBIVg==" />      <input type="hidden" name="repository_id" id="repository_id" value="20159867" class="form-control" />

        <div class="select-menu js-menu-container js-select-menu">
          <a href="/nothings/stb/subscription"
            class="btn btn-sm btn-with-count select-menu-button js-menu-target"
            role="button"
            aria-haspopup="true"
            aria-expanded="false"
            aria-label="Toggle repository notifications menu"
            data-ga-click="Repository, click Watch settings, action:blob#show">
            <span class="js-select-button">
                <svg class="octicon octicon-eye" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"/></svg>
                Watch
            </span>
          </a>
          <a class="social-count js-social-count"
            href="/nothings/stb/watchers"
            aria-label="498 users are watching this repository">
            498
          </a>

        <div class="select-menu-modal-holder">
          <div class="select-menu-modal subscription-menu-modal js-menu-content">
            <div class="select-menu-header js-navigation-enable" tabindex="-1">
              <svg class="octicon octicon-x js-menu-close" role="img" aria-label="Close" viewBox="0 0 12 16" version="1.1" width="12" height="16"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
              <span class="select-menu-title">Notifications</span>
            </div>

              <div class="select-menu-list js-navigation-container" role="menu">

                <div class="select-menu-item js-navigation-item selected" role="menuitem" tabindex="0">
                  <svg class="octicon octicon-check select-menu-item-icon" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
                  <div class="select-menu-item-text">
                    <input type="radio" name="do" id="do_included" value="included" checked="checked" />
                    <span class="select-menu-item-heading">Not watching</span>
                    <span class="description">Be notified when participating or @mentioned.</span>
                    <span class="js-select-button-text hidden-select-button-text">
                      <svg class="octicon octicon-eye" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"/></svg>
                      Watch
                    </span>
                  </div>
                </div>

                <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
                  <svg class="octicon octicon-check select-menu-item-icon" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
                  <div class="select-menu-item-text">
                    <input type="radio" name="do" id="do_subscribed" value="subscribed" />
                    <span class="select-menu-item-heading">Watching</span>
                    <span class="description">Be notified of all conversations.</span>
                    <span class="js-select-button-text hidden-select-button-text">
                      <svg class="octicon octicon-eye" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"/></svg>
                        Unwatch
                    </span>
                  </div>
                </div>

                <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
                  <svg class="octicon octicon-check select-menu-item-icon" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
                  <div class="select-menu-item-text">
                    <input type="radio" name="do" id="do_ignore" value="ignore" />
                    <span class="select-menu-item-heading">Ignoring</span>
                    <span class="description">Never be notified.</span>
                    <span class="js-select-button-text hidden-select-button-text">
                      <svg class="octicon octicon-mute" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8 2.81v10.38c0 .67-.81 1-1.28.53L3 10H1c-.55 0-1-.45-1-1V7c0-.55.45-1 1-1h2l3.72-3.72C7.19 1.81 8 2.14 8 2.81zm7.53 3.22l-1.06-1.06-1.97 1.97-1.97-1.97-1.06 1.06L11.44 8 9.47 9.97l1.06 1.06 1.97-1.97 1.97 1.97 1.06-1.06L13.56 8l1.97-1.97z"/></svg>
                        Stop ignoring
                    </span>
                  </div>
                </div>

              </div>

            </div>
          </div>
        </div>
</form>
  </li>

  <li>
    
  <div class="js-toggler-container js-social-container starring-container on">
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="starred js-social-form" action="/nothings/stb/unstar" accept-charset="UTF-8" method="post"><input name="utf8" type="hidden" value="&#x2713;" /><input type="hidden" name="authenticity_token" value="6WMZA+biKW56Ne0iFIgZKvjl38lT/L97NkM2j+8XHitf1MpivYyEFly2lC2V17O9C4MlITKXTMr5eXis6hrxIA==" />
      <input type="hidden" name="context" value="repository"></input>
      <button
        type="submit"
        class="btn btn-sm btn-with-count js-toggler-target"
        aria-label="Unstar this repository" title="Unstar nothings/stb"
        data-ga-click="Repository, click unstar button, action:blob#show; text:Unstar">
        <svg class="octicon octicon-star" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M14 6l-4.9-.64L7 1 4.9 5.36 0 6l3.6 3.26L2.67 14 7 11.67 11.33 14l-.93-4.74z"/></svg>
        Unstar
      </button>
        <a class="social-count js-social-count" href="/nothings/stb/stargazers"
           aria-label="7232 users starred this repository">
          7,232
        </a>
</form>
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="unstarred js-social-form" action="/nothings/stb/star" accept-charset="UTF-8" method="post"><input name="utf8" type="hidden" value="&#x2713;" /><input type="hidden" name="authenticity_token" value="w+dPoouitg4gNEmgUpFUPYi6I46ey8VhN37j5+vu5o6MMJnuKYdDgG1NHZNxsmNQlW22FifuvkuBujsDmzoKag==" />
      <input type="hidden" name="context" value="repository"></input>
      <button
        type="submit"
        class="btn btn-sm btn-with-count js-toggler-target"
        aria-label="Star this repository" title="Star nothings/stb"
        data-ga-click="Repository, click star button, action:blob#show; text:Star">
        <svg class="octicon octicon-star" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M14 6l-4.9-.64L7 1 4.9 5.36 0 6l3.6 3.26L2.67 14 7 11.67 11.33 14l-.93-4.74z"/></svg>
        Star
      </button>
        <a class="social-count js-social-count" href="/nothings/stb/stargazers"
           aria-label="7232 users starred this repository">
          7,232
        </a>
</form>  </div>

  </li>

  <li>
          <a href="#fork-destination-box" class="btn btn-sm btn-with-count"
              title="Fork your own copy of nothings/stb to your account"
              aria-label="Fork your own copy of nothings/stb to your account"
              rel="facebox"
              data-ga-click="Repository, show fork modal, action:blob#show; text:Fork">
              <svg class="octicon octicon-repo-forked" viewBox="0 0 10 16" version="1.1" width="10" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8 1a1.993 1.993 0 0 0-1 3.72V6L5 8 3 6V4.72A1.993 1.993 0 0 0 2 1a1.993 1.993 0 0 0-1 3.72V6.5l3 3v1.78A1.993 1.993 0 0 0 5 15a1.993 1.993 0 0 0 1-3.72V9.5l3-3V4.72A1.993 1.993 0 0 0 8 1zM2 4.2C1.34 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3 10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3-10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"/></svg>
            Fork
          </a>

          <div id="fork-destination-box" style="display: none;">
            <h2 class="facebox-header" data-facebox-id="facebox-header">Where should we fork this repository?</h2>
            <include-fragment src=""
                class="js-fork-select-fragment fork-select-fragment"
                data-url="/nothings/stb/fork?fragment=1">
              <img alt="Loading" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-128.gif" width="64" height="64" />
            </include-fragment>
          </div>

    <a href="/nothings/stb/network" class="social-count"
       aria-label="1350 users forked this repository">
      1,350
    </a>
  </li>
</ul>

      <h1 class="public ">
  <svg class="octicon octicon-repo" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M4 9H3V8h1v1zm0-3H3v1h1V6zm0-2H3v1h1V4zm0-2H3v1h1V2zm8-1v12c0 .55-.45 1-1 1H6v2l-1.5-1.5L3 16v-2H1c-.55 0-1-.45-1-1V1c0-.55.45-1 1-1h10c.55 0 1 .45 1 1zm-1 10H1v2h2v-1h3v1h5v-2zm0-10H2v9h9V1z"/></svg>
  <span class="author" itemprop="author"><a class="url fn" rel="author" href="/nothings">nothings</a></span><!--
--><span class="path-divider">/</span><!--
--><strong itemprop="name"><a data-pjax="#js-repo-pjax-container" href="/nothings/stb">stb</a></strong>

</h1>

    </div>
    
<nav class="reponav js-repo-nav js-sidenav-container-pjax container"
     itemscope
     itemtype="http://schema.org/BreadcrumbList"
     role="navigation"
     data-pjax="#js-repo-pjax-container">

  <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
    <a class="js-selected-navigation-item selected reponav-item" itemprop="url" data-hotkey="g c" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches repo_packages /nothings/stb" href="/nothings/stb">
      <svg class="octicon octicon-code" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M9.5 3L8 4.5 11.5 8 8 11.5 9.5 13 14 8 9.5 3zm-5 0L0 8l4.5 5L6 11.5 2.5 8 6 4.5 4.5 3z"/></svg>
      <span itemprop="name">Code</span>
      <meta itemprop="position" content="1">
</a>  </span>

    <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
      <a itemprop="url" data-hotkey="g i" class="js-selected-navigation-item reponav-item" data-selected-links="repo_issues repo_labels repo_milestones /nothings/stb/issues" href="/nothings/stb/issues">
        <svg class="octicon octicon-issue-opened" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7 2.3c3.14 0 5.7 2.56 5.7 5.7s-2.56 5.7-5.7 5.7A5.71 5.71 0 0 1 1.3 8c0-3.14 2.56-5.7 5.7-5.7zM7 1C3.14 1 0 4.14 0 8s3.14 7 7 7 7-3.14 7-7-3.14-7-7-7zm1 3H6v5h2V4zm0 6H6v2h2v-2z"/></svg>
        <span itemprop="name">Issues</span>
        <span class="Counter">47</span>
        <meta itemprop="position" content="2">
</a>    </span>

  <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
    <a data-hotkey="g p" itemprop="url" class="js-selected-navigation-item reponav-item" data-selected-links="repo_pulls checks /nothings/stb/pulls" href="/nothings/stb/pulls">
      <svg class="octicon octicon-git-pull-request" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M11 11.28V5c-.03-.78-.34-1.47-.94-2.06C9.46 2.35 8.78 2.03 8 2H7V0L4 3l3 3V4h1c.27.02.48.11.69.31.21.2.3.42.31.69v6.28A1.993 1.993 0 0 0 10 15a1.993 1.993 0 0 0 1-3.72zm-1 2.92c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zM4 3c0-1.11-.89-2-2-2a1.993 1.993 0 0 0-1 3.72v6.56A1.993 1.993 0 0 0 2 15a1.993 1.993 0 0 0 1-3.72V4.72c.59-.34 1-.98 1-1.72zm-.8 10c0 .66-.55 1.2-1.2 1.2-.65 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2zM2 4.2C1.34 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"/></svg>
      <span itemprop="name">Pull requests</span>
      <span class="Counter">21</span>
      <meta itemprop="position" content="3">
</a>  </span>

    <a data-hotkey="g b" class="js-selected-navigation-item reponav-item" data-selected-links="repo_projects new_repo_project repo_project /nothings/stb/projects" href="/nothings/stb/projects">
      <svg class="octicon octicon-project" viewBox="0 0 15 16" version="1.1" width="15" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M10 12h3V2h-3v10zm-4-2h3V2H6v8zm-4 4h3V2H2v12zm-1 1h13V1H1v14zM14 0H1a1 1 0 0 0-1 1v14a1 1 0 0 0 1 1h13a1 1 0 0 0 1-1V1a1 1 0 0 0-1-1z"/></svg>
      Projects
      <span class="Counter" >0</span>
</a>


  <a class="js-selected-navigation-item reponav-item" data-selected-links="repo_graphs repo_contributors dependency_graph pulse /nothings/stb/pulse" href="/nothings/stb/pulse">
    <svg class="octicon octicon-graph" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M16 14v1H0V0h1v14h15zM5 13H3V8h2v5zm4 0H7V3h2v10zm4 0h-2V6h2v7z"/></svg>
    Insights
</a>

</nav>


  </div>

<div class="container new-discussion-timeline experiment-repo-nav  ">
  <div class="repository-content ">

    
  <a class="d-none js-permalink-shortcut" data-hotkey="y" href="/nothings/stb/blob/e6afb9cbae4064da8c3e69af3ff5c4629579c1d2/stb_image_write.h">Permalink</a>

  <!-- blob contrib key: blob_contributors:v21:aee38dace3993adfe87bb28f9caf4223 -->

  <div class="file-navigation">
    
<div class="select-menu branch-select-menu js-menu-container js-select-menu float-left">
  <button class=" btn btn-sm select-menu-button js-menu-target css-truncate" data-hotkey="w"
    
    type="button" aria-label="Switch branches or tags" aria-expanded="false" aria-haspopup="true">
      <i>Branch:</i>
      <span class="js-select-button css-truncate-target">master</span>
  </button>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax>

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <svg class="octicon octicon-x js-menu-close" role="img" aria-label="Close" viewBox="0 0 12 16" version="1.1" width="12" height="16"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
        <span class="select-menu-title">Switch branches/tags</span>
      </div>

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Filter branches/tags" id="context-commitish-filter-field" class="form-control js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" data-filter-placeholder="Filter branches/tags" class="js-select-menu-tab" role="tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" data-filter-placeholder="Find a tag…" class="js-select-menu-tab" role="tab">Tags</a>
            </li>
          </ul>
        </div>
      </div>

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches" role="menu">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/nothings/stb/blob/dev/stb_image_write.h"
               data-name="dev"
               data-skip-pjax="true"
               rel="nofollow">
              <svg class="octicon octicon-check select-menu-item-icon" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
              <span class="select-menu-item-text css-truncate-target js-select-menu-filter-text">
                dev
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open selected"
               href="/nothings/stb/blob/master/stb_image_write.h"
               data-name="master"
               data-skip-pjax="true"
               rel="nofollow">
              <svg class="octicon octicon-check select-menu-item-icon" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
              <span class="select-menu-item-text css-truncate-target js-select-menu-filter-text">
                master
              </span>
            </a>
        </div>

          <div class="select-menu-no-results">Nothing to show</div>
      </div>

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div>

    </div>
  </div>
</div>

    <div class="BtnGroup float-right">
      <a href="/nothings/stb/find/master"
            class="js-pjax-capture-input btn btn-sm BtnGroup-item"
            data-pjax
            data-hotkey="t">
        Find file
      </a>
      <clipboard-copy for="blob-path" class="btn btn-sm BtnGroup-item">
        Copy path
      </clipboard-copy>
    </div>
    <div id="blob-path" class="breadcrumb">
      <span class="repo-root js-repo-root"><span class="js-path-segment"><a data-pjax="true" href="/nothings/stb"><span>stb</span></a></span></span><span class="separator">/</span><strong class="final-path">stb_image_write.h</strong>
    </div>
  </div>


  
  <div class="commit-tease">
      <span class="float-right">
        <a class="commit-tease-sha" href="/nothings/stb/commit/543ad0c11294051a51775d346bf660e2d87ba36e" data-pjax>
          543ad0c
        </a>
        <relative-time datetime="2018-02-11T19:29:32Z">Feb 11, 2018</relative-time>
      </span>
      <div>
        <img alt="" class="avatar" data-canonical-src="https://1.gravatar.com/avatar/9de7684bebc108c2dee4eafda927407b?d=https%3A%2F%2Fassets-cdn.github.com%2Fimages%2Fgravatars%2Fgravatar-user-420.png&amp;r=g&amp;s=140" height="20" src="https://camo.githubusercontent.com/6b769b73b6e8dc11a3fbc5560b2f204cfdb971dc/68747470733a2f2f312e67726176617461722e636f6d2f6176617461722f39646537363834626562633130386332646565346561666461393237343037623f643d68747470732533412532462532466173736574732d63646e2e6769746875622e636f6d253246696d6167657325324667726176617461727325324667726176617461722d757365722d3432302e706e6726723d6726733d313430" width="20" />
        <span class="user-mention">Sean Barrett</span>
          <a href="/nothings/stb/commit/543ad0c11294051a51775d346bf660e2d87ba36e" class="message" data-pjax="true" title="stb_image_write: tweak handling of STB_IMAGE_WRITE_STATIC">stb_image_write: tweak handling of STB_IMAGE_WRITE_STATIC</a>
      </div>

    <div class="commit-tease-contributors">
      <button type="button" class="btn-link muted-link contributors-toggle" data-facebox="#blob_contributors_box">
        <strong>22</strong>
         contributors
      </button>
          <a class="avatar-link tooltipped tooltipped-s" aria-label="nothings" href="/nothings/stb/commits/master/stb_image_write.h?author=nothings"><img alt="@nothings" class="avatar" height="20" src="https://avatars2.githubusercontent.com/u/7525026?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="DanielGibson" href="/nothings/stb/commits/master/stb_image_write.h?author=DanielGibson"><img alt="@DanielGibson" class="avatar" height="20" src="https://avatars2.githubusercontent.com/u/1216493?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="xeekworx" href="/nothings/stb/commits/master/stb_image_write.h?author=xeekworx"><img alt="@xeekworx" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/6032840?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="karjonas" href="/nothings/stb/commits/master/stb_image_write.h?author=karjonas"><img alt="@karjonas" class="avatar" height="20" src="https://avatars2.githubusercontent.com/u/754587?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="Skylark13" href="/nothings/stb/commits/master/stb_image_write.h?author=Skylark13"><img alt="@Skylark13" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/907768?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="fahickman" href="/nothings/stb/commits/master/stb_image_write.h?author=fahickman"><img alt="@fahickman" class="avatar" height="20" src="https://avatars1.githubusercontent.com/u/10904832?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="guillaumechereau" href="/nothings/stb/commits/master/stb_image_write.h?author=guillaumechereau"><img alt="@guillaumechereau" class="avatar" height="20" src="https://avatars2.githubusercontent.com/u/107679?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="cap" href="/nothings/stb/commits/master/stb_image_write.h?author=cap"><img alt="@cap" class="avatar" height="20" src="https://avatars1.githubusercontent.com/u/22780?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="zerhacken" href="/nothings/stb/commits/master/stb_image_write.h?author=zerhacken"><img alt="@zerhacken" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/1444972?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="Benjins" href="/nothings/stb/commits/master/stb_image_write.h?author=Benjins"><img alt="@Benjins" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/6193112?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="rygorous" href="/nothings/stb/commits/master/stb_image_write.h?author=rygorous"><img alt="@rygorous" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/1077496?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="romigrou" href="/nothings/stb/commits/master/stb_image_write.h?author=romigrou"><img alt="@romigrou" class="avatar" height="20" src="https://avatars1.githubusercontent.com/u/15167357?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="pboettch" href="/nothings/stb/commits/master/stb_image_write.h?author=pboettch"><img alt="@pboettch" class="avatar" height="20" src="https://avatars3.githubusercontent.com/u/442684?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="rwhitworth" href="/nothings/stb/commits/master/stb_image_write.h?author=rwhitworth"><img alt="@rwhitworth" class="avatar" height="20" src="https://avatars3.githubusercontent.com/u/7214365?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="kosua20" href="/nothings/stb/commits/master/stb_image_write.h?author=kosua20"><img alt="@kosua20" class="avatar" height="20" src="https://avatars1.githubusercontent.com/u/3199516?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="jorgenpt" href="/nothings/stb/commits/master/stb_image_write.h?author=jorgenpt"><img alt="@jorgenpt" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/21258?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="filipwasil" href="/nothings/stb/commits/master/stb_image_write.h?author=filipwasil"><img alt="@filipwasil" class="avatar" height="20" src="https://avatars3.githubusercontent.com/u/1853117?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="ejulien" href="/nothings/stb/commits/master/stb_image_write.h?author=ejulien"><img alt="@ejulien" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/4431372?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="oon3m0oo" href="/nothings/stb/commits/master/stb_image_write.h?author=oon3m0oo"><img alt="@oon3m0oo" class="avatar" height="20" src="https://avatars2.githubusercontent.com/u/11841654?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="serge-rgb" href="/nothings/stb/commits/master/stb_image_write.h?author=serge-rgb"><img alt="@serge-rgb" class="avatar" height="20" src="https://avatars1.githubusercontent.com/u/282970?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="baldurk" href="/nothings/stb/commits/master/stb_image_write.h?author=baldurk"><img alt="@baldurk" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/661798?s=40&amp;v=4" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="akx" href="/nothings/stb/commits/master/stb_image_write.h?author=akx"><img alt="@akx" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/58669?s=40&amp;v=4" width="20" /> </a>


    </div>

    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header" data-facebox-id="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list" data-facebox-id="facebox-description">
          <li class="facebox-user-list-item">
            <img alt="@nothings" height="24" src="https://avatars3.githubusercontent.com/u/7525026?s=48&amp;v=4" width="24" />
            <a href="/nothings">nothings</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@DanielGibson" height="24" src="https://avatars3.githubusercontent.com/u/1216493?s=48&amp;v=4" width="24" />
            <a href="/DanielGibson">DanielGibson</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@xeekworx" height="24" src="https://avatars1.githubusercontent.com/u/6032840?s=48&amp;v=4" width="24" />
            <a href="/xeekworx">xeekworx</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@karjonas" height="24" src="https://avatars3.githubusercontent.com/u/754587?s=48&amp;v=4" width="24" />
            <a href="/karjonas">karjonas</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@Skylark13" height="24" src="https://avatars1.githubusercontent.com/u/907768?s=48&amp;v=4" width="24" />
            <a href="/Skylark13">Skylark13</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@fahickman" height="24" src="https://avatars0.githubusercontent.com/u/10904832?s=48&amp;v=4" width="24" />
            <a href="/fahickman">fahickman</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@guillaumechereau" height="24" src="https://avatars3.githubusercontent.com/u/107679?s=48&amp;v=4" width="24" />
            <a href="/guillaumechereau">guillaumechereau</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@cap" height="24" src="https://avatars0.githubusercontent.com/u/22780?s=48&amp;v=4" width="24" />
            <a href="/cap">cap</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@zerhacken" height="24" src="https://avatars1.githubusercontent.com/u/1444972?s=48&amp;v=4" width="24" />
            <a href="/zerhacken">zerhacken</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@Benjins" height="24" src="https://avatars1.githubusercontent.com/u/6193112?s=48&amp;v=4" width="24" />
            <a href="/Benjins">Benjins</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@rygorous" height="24" src="https://avatars1.githubusercontent.com/u/1077496?s=48&amp;v=4" width="24" />
            <a href="/rygorous">rygorous</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@romigrou" height="24" src="https://avatars0.githubusercontent.com/u/15167357?s=48&amp;v=4" width="24" />
            <a href="/romigrou">romigrou</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@pboettch" height="24" src="https://avatars2.githubusercontent.com/u/442684?s=48&amp;v=4" width="24" />
            <a href="/pboettch">pboettch</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@rwhitworth" height="24" src="https://avatars2.githubusercontent.com/u/7214365?s=48&amp;v=4" width="24" />
            <a href="/rwhitworth">rwhitworth</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@kosua20" height="24" src="https://avatars0.githubusercontent.com/u/3199516?s=48&amp;v=4" width="24" />
            <a href="/kosua20">kosua20</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@jorgenpt" height="24" src="https://avatars1.githubusercontent.com/u/21258?s=48&amp;v=4" width="24" />
            <a href="/jorgenpt">jorgenpt</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@filipwasil" height="24" src="https://avatars2.githubusercontent.com/u/1853117?s=48&amp;v=4" width="24" />
            <a href="/filipwasil">filipwasil</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@ejulien" height="24" src="https://avatars1.githubusercontent.com/u/4431372?s=48&amp;v=4" width="24" />
            <a href="/ejulien">ejulien</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@oon3m0oo" height="24" src="https://avatars3.githubusercontent.com/u/11841654?s=48&amp;v=4" width="24" />
            <a href="/oon3m0oo">oon3m0oo</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@serge-rgb" height="24" src="https://avatars0.githubusercontent.com/u/282970?s=48&amp;v=4" width="24" />
            <a href="/serge-rgb">serge-rgb</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@baldurk" height="24" src="https://avatars1.githubusercontent.com/u/661798?s=48&amp;v=4" width="24" />
            <a href="/baldurk">baldurk</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@akx" height="24" src="https://avatars1.githubusercontent.com/u/58669?s=48&amp;v=4" width="24" />
            <a href="/akx">akx</a>
          </li>
      </ul>
    </div>
  </div>



  <div class="file">
    <div class="file-header">
  <div class="file-actions">

    <div class="BtnGroup">
      <a id="raw-url" class="btn btn-sm BtnGroup-item" href="/nothings/stb/raw/master/stb_image_write.h">Raw</a>
        <a class="btn btn-sm js-update-url-with-hash BtnGroup-item" data-hotkey="b" href="/nothings/stb/blame/master/stb_image_write.h">Blame</a>
      <a rel="nofollow" class="btn btn-sm BtnGroup-item" href="/nothings/stb/commits/master/stb_image_write.h">History</a>
    </div>

        <a class="btn-octicon tooltipped tooltipped-nw"
           href="x-github-client://openRepo/https://github.com/nothings/stb?branch=master&amp;filepath=stb_image_write.h"
           aria-label="Open this file in GitHub Desktop"
           data-ga-click="Repository, open with desktop, type:windows">
            <svg class="octicon octicon-device-desktop" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M15 2H1c-.55 0-1 .45-1 1v9c0 .55.45 1 1 1h5.34c-.25.61-.86 1.39-2.34 2h8c-1.48-.61-2.09-1.39-2.34-2H15c.55 0 1-.45 1-1V3c0-.55-.45-1-1-1zm0 9H1V3h14v8z"/></svg>
        </a>

          <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="inline-form js-update-url-with-hash" action="/nothings/stb/edit/master/stb_image_write.h" accept-charset="UTF-8" method="post"><input name="utf8" type="hidden" value="&#x2713;" /><input type="hidden" name="authenticity_token" value="Q5PnEI/YNo3aqH1uwOcRNdRcSCs8gUQqAam7jKg3Z+1A+R8H8AWGcr3w2xLzqGsLOVMcJgFX+086emCuuWNt0g==" />
            <button class="btn-octicon tooltipped tooltipped-nw" type="submit"
              aria-label="Fork this project and edit the file" data-hotkey="e" data-disable-with>
              <svg class="octicon octicon-pencil" viewBox="0 0 14 16" version="1.1" width="14" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M0 12v3h3l8-8-3-3-8 8zm3 2H1v-2h1v1h1v1zm10.3-9.3L12 6 9 3l1.3-1.3a.996.996 0 0 1 1.41 0l1.59 1.59c.39.39.39 1.02 0 1.41z"/></svg>
            </button>
</form>
        <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="inline-form" action="/nothings/stb/delete/master/stb_image_write.h" accept-charset="UTF-8" method="post"><input name="utf8" type="hidden" value="&#x2713;" /><input type="hidden" name="authenticity_token" value="0yCSnIbwKmz6cO4AaIL2LaHx98XPVmavgyEpw/yc0yx0xwE+UOKNbxc9Z3cKQdtIIDPjyIIHBpF7DwGCtnJfHQ==" />
          <button class="btn-octicon btn-octicon-danger tooltipped tooltipped-nw" type="submit"
            aria-label="Fork this project and delete the file" data-disable-with>
            <svg class="octicon octicon-trashcan" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M11 2H9c0-.55-.45-1-1-1H5c-.55 0-1 .45-1 1H2c-.55 0-1 .45-1 1v1c0 .55.45 1 1 1v9c0 .55.45 1 1 1h7c.55 0 1-.45 1-1V5c.55 0 1-.45 1-1V3c0-.55-.45-1-1-1zm-1 12H3V5h1v8h1V5h1v8h1V5h1v8h1V5h1v9zm1-10H2V3h9v1z"/></svg>
          </button>
</form>  </div>

  <div class="file-info">
      1569 lines (1381 sloc)
      <span class="file-info-divider"></span>
    63 KB
  </div>
</div>

    

  <div itemprop="text" class="blob-wrapper data type-c">
      <table class="highlight tab-size js-file-line-container" data-tab-size="8">
      <tr>
        <td id="L1" class="blob-num js-line-number" data-line-number="1"></td>
        <td id="LC1" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">/*</span> stb_image_write - v1.09 - public domain - http://nothings.org/stb/stb_image_write.h</span></td>
      </tr>
      <tr>
        <td id="L2" class="blob-num js-line-number" data-line-number="2"></td>
        <td id="LC2" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   writes out PNG/BMP/TGA/JPEG/HDR images to C stdio - Sean Barrett 2010-2015</span></td>
      </tr>
      <tr>
        <td id="L3" class="blob-num js-line-number" data-line-number="3"></td>
        <td id="LC3" class="blob-code blob-code-inner js-file-line"><span class="pl-c">                                     no warranty implied; use at your own risk</span></td>
      </tr>
      <tr>
        <td id="L4" class="blob-num js-line-number" data-line-number="4"></td>
        <td id="LC4" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L5" class="blob-num js-line-number" data-line-number="5"></td>
        <td id="LC5" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Before #including,</span></td>
      </tr>
      <tr>
        <td id="L6" class="blob-num js-line-number" data-line-number="6"></td>
        <td id="LC6" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L7" class="blob-num js-line-number" data-line-number="7"></td>
        <td id="LC7" class="blob-code blob-code-inner js-file-line"><span class="pl-c">       #define STB_IMAGE_WRITE_IMPLEMENTATION</span></td>
      </tr>
      <tr>
        <td id="L8" class="blob-num js-line-number" data-line-number="8"></td>
        <td id="LC8" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L9" class="blob-num js-line-number" data-line-number="9"></td>
        <td id="LC9" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   in the file that you want to have the implementation.</span></td>
      </tr>
      <tr>
        <td id="L10" class="blob-num js-line-number" data-line-number="10"></td>
        <td id="LC10" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L11" class="blob-num js-line-number" data-line-number="11"></td>
        <td id="LC11" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Will probably not work correctly with strict-aliasing optimizations.</span></td>
      </tr>
      <tr>
        <td id="L12" class="blob-num js-line-number" data-line-number="12"></td>
        <td id="LC12" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L13" class="blob-num js-line-number" data-line-number="13"></td>
        <td id="LC13" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   If using a modern Microsoft Compiler, non-safe versions of CRT calls may cause </span></td>
      </tr>
      <tr>
        <td id="L14" class="blob-num js-line-number" data-line-number="14"></td>
        <td id="LC14" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   compilation warnings or even errors. To avoid this, also before #including,</span></td>
      </tr>
      <tr>
        <td id="L15" class="blob-num js-line-number" data-line-number="15"></td>
        <td id="LC15" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L16" class="blob-num js-line-number" data-line-number="16"></td>
        <td id="LC16" class="blob-code blob-code-inner js-file-line"><span class="pl-c">       #define STBI_MSC_SECURE_CRT</span></td>
      </tr>
      <tr>
        <td id="L17" class="blob-num js-line-number" data-line-number="17"></td>
        <td id="LC17" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L18" class="blob-num js-line-number" data-line-number="18"></td>
        <td id="LC18" class="blob-code blob-code-inner js-file-line"><span class="pl-c">ABOUT:</span></td>
      </tr>
      <tr>
        <td id="L19" class="blob-num js-line-number" data-line-number="19"></td>
        <td id="LC19" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L20" class="blob-num js-line-number" data-line-number="20"></td>
        <td id="LC20" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   This header file is a library for writing images to C stdio. It could be</span></td>
      </tr>
      <tr>
        <td id="L21" class="blob-num js-line-number" data-line-number="21"></td>
        <td id="LC21" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   adapted to write to memory or a general streaming interface; let me know.</span></td>
      </tr>
      <tr>
        <td id="L22" class="blob-num js-line-number" data-line-number="22"></td>
        <td id="LC22" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L23" class="blob-num js-line-number" data-line-number="23"></td>
        <td id="LC23" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   The PNG output is not optimal; it is 20-50% larger than the file</span></td>
      </tr>
      <tr>
        <td id="L24" class="blob-num js-line-number" data-line-number="24"></td>
        <td id="LC24" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   written by a decent optimizing implementation; though providing a custom</span></td>
      </tr>
      <tr>
        <td id="L25" class="blob-num js-line-number" data-line-number="25"></td>
        <td id="LC25" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   zlib compress function (see STBIW_ZLIB_COMPRESS) can mitigate that.</span></td>
      </tr>
      <tr>
        <td id="L26" class="blob-num js-line-number" data-line-number="26"></td>
        <td id="LC26" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   This library is designed for source code compactness and simplicity,</span></td>
      </tr>
      <tr>
        <td id="L27" class="blob-num js-line-number" data-line-number="27"></td>
        <td id="LC27" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   not optimal image file size or run-time performance.</span></td>
      </tr>
      <tr>
        <td id="L28" class="blob-num js-line-number" data-line-number="28"></td>
        <td id="LC28" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L29" class="blob-num js-line-number" data-line-number="29"></td>
        <td id="LC29" class="blob-code blob-code-inner js-file-line"><span class="pl-c">BUILDING:</span></td>
      </tr>
      <tr>
        <td id="L30" class="blob-num js-line-number" data-line-number="30"></td>
        <td id="LC30" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L31" class="blob-num js-line-number" data-line-number="31"></td>
        <td id="LC31" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   You can #define STBIW_ASSERT(x) before the #include to avoid using assert.h.</span></td>
      </tr>
      <tr>
        <td id="L32" class="blob-num js-line-number" data-line-number="32"></td>
        <td id="LC32" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   You can #define STBIW_MALLOC(), STBIW_REALLOC(), and STBIW_FREE() to replace</span></td>
      </tr>
      <tr>
        <td id="L33" class="blob-num js-line-number" data-line-number="33"></td>
        <td id="LC33" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   malloc,realloc,free.</span></td>
      </tr>
      <tr>
        <td id="L34" class="blob-num js-line-number" data-line-number="34"></td>
        <td id="LC34" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   You can #define STBIW_MEMMOVE() to replace memmove()</span></td>
      </tr>
      <tr>
        <td id="L35" class="blob-num js-line-number" data-line-number="35"></td>
        <td id="LC35" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   You can #define STBIW_ZLIB_COMPRESS to use a custom zlib-style compress function</span></td>
      </tr>
      <tr>
        <td id="L36" class="blob-num js-line-number" data-line-number="36"></td>
        <td id="LC36" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   for PNG compression (instead of the builtin one), it must have the following signature:</span></td>
      </tr>
      <tr>
        <td id="L37" class="blob-num js-line-number" data-line-number="37"></td>
        <td id="LC37" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   unsigned char * my_compress(unsigned char *data, int data_len, int *out_len, int quality);</span></td>
      </tr>
      <tr>
        <td id="L38" class="blob-num js-line-number" data-line-number="38"></td>
        <td id="LC38" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   The returned data will be freed with STBIW_FREE() (free() by default),</span></td>
      </tr>
      <tr>
        <td id="L39" class="blob-num js-line-number" data-line-number="39"></td>
        <td id="LC39" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   so it must be heap allocated with STBIW_MALLOC() (malloc() by default),</span></td>
      </tr>
      <tr>
        <td id="L40" class="blob-num js-line-number" data-line-number="40"></td>
        <td id="LC40" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L41" class="blob-num js-line-number" data-line-number="41"></td>
        <td id="LC41" class="blob-code blob-code-inner js-file-line"><span class="pl-c">USAGE:</span></td>
      </tr>
      <tr>
        <td id="L42" class="blob-num js-line-number" data-line-number="42"></td>
        <td id="LC42" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L43" class="blob-num js-line-number" data-line-number="43"></td>
        <td id="LC43" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   There are five functions, one for each image file format:</span></td>
      </tr>
      <tr>
        <td id="L44" class="blob-num js-line-number" data-line-number="44"></td>
        <td id="LC44" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L45" class="blob-num js-line-number" data-line-number="45"></td>
        <td id="LC45" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     int stbi_write_png(char const *filename, int w, int h, int comp, const void *data, int stride_in_bytes);</span></td>
      </tr>
      <tr>
        <td id="L46" class="blob-num js-line-number" data-line-number="46"></td>
        <td id="LC46" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     int stbi_write_bmp(char const *filename, int w, int h, int comp, const void *data);</span></td>
      </tr>
      <tr>
        <td id="L47" class="blob-num js-line-number" data-line-number="47"></td>
        <td id="LC47" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     int stbi_write_tga(char const *filename, int w, int h, int comp, const void *data);</span></td>
      </tr>
      <tr>
        <td id="L48" class="blob-num js-line-number" data-line-number="48"></td>
        <td id="LC48" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     int stbi_write_jpg(char const *filename, int w, int h, int comp, const void *data, int quality);</span></td>
      </tr>
      <tr>
        <td id="L49" class="blob-num js-line-number" data-line-number="49"></td>
        <td id="LC49" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     int stbi_write_hdr(char const *filename, int w, int h, int comp, const float *data);</span></td>
      </tr>
      <tr>
        <td id="L50" class="blob-num js-line-number" data-line-number="50"></td>
        <td id="LC50" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L51" class="blob-num js-line-number" data-line-number="51"></td>
        <td id="LC51" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     void stbi_flip_vertically_on_write(int flag); // flag is non-zero to flip data vertically</span></td>
      </tr>
      <tr>
        <td id="L52" class="blob-num js-line-number" data-line-number="52"></td>
        <td id="LC52" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L53" class="blob-num js-line-number" data-line-number="53"></td>
        <td id="LC53" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   There are also five equivalent functions that use an arbitrary write function. You are</span></td>
      </tr>
      <tr>
        <td id="L54" class="blob-num js-line-number" data-line-number="54"></td>
        <td id="LC54" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   expected to open/close your file-equivalent before and after calling these:</span></td>
      </tr>
      <tr>
        <td id="L55" class="blob-num js-line-number" data-line-number="55"></td>
        <td id="LC55" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L56" class="blob-num js-line-number" data-line-number="56"></td>
        <td id="LC56" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     int stbi_write_png_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data, int stride_in_bytes);</span></td>
      </tr>
      <tr>
        <td id="L57" class="blob-num js-line-number" data-line-number="57"></td>
        <td id="LC57" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     int stbi_write_bmp_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data);</span></td>
      </tr>
      <tr>
        <td id="L58" class="blob-num js-line-number" data-line-number="58"></td>
        <td id="LC58" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     int stbi_write_tga_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data);</span></td>
      </tr>
      <tr>
        <td id="L59" class="blob-num js-line-number" data-line-number="59"></td>
        <td id="LC59" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     int stbi_write_hdr_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const float *data);</span></td>
      </tr>
      <tr>
        <td id="L60" class="blob-num js-line-number" data-line-number="60"></td>
        <td id="LC60" class="blob-code blob-code-inner js-file-line"><span class="pl-c">     int stbi_write_jpg_to_func(stbi_write_func *func, void *context, int x, int y, int comp, const void *data, int quality);</span></td>
      </tr>
      <tr>
        <td id="L61" class="blob-num js-line-number" data-line-number="61"></td>
        <td id="LC61" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L62" class="blob-num js-line-number" data-line-number="62"></td>
        <td id="LC62" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   where the callback is:</span></td>
      </tr>
      <tr>
        <td id="L63" class="blob-num js-line-number" data-line-number="63"></td>
        <td id="LC63" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      void stbi_write_func(void *context, void *data, int size);</span></td>
      </tr>
      <tr>
        <td id="L64" class="blob-num js-line-number" data-line-number="64"></td>
        <td id="LC64" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L65" class="blob-num js-line-number" data-line-number="65"></td>
        <td id="LC65" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   You can configure it with these global variables:</span></td>
      </tr>
      <tr>
        <td id="L66" class="blob-num js-line-number" data-line-number="66"></td>
        <td id="LC66" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      int stbi_write_tga_with_rle;             // defaults to true; set to 0 to disable RLE</span></td>
      </tr>
      <tr>
        <td id="L67" class="blob-num js-line-number" data-line-number="67"></td>
        <td id="LC67" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      int stbi_write_png_compression_level;    // defaults to 8; set to higher for more compression</span></td>
      </tr>
      <tr>
        <td id="L68" class="blob-num js-line-number" data-line-number="68"></td>
        <td id="LC68" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      int stbi_write_force_png_filter;         // defaults to -1; set to 0..5 to force a filter mode</span></td>
      </tr>
      <tr>
        <td id="L69" class="blob-num js-line-number" data-line-number="69"></td>
        <td id="LC69" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L70" class="blob-num js-line-number" data-line-number="70"></td>
        <td id="LC70" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L71" class="blob-num js-line-number" data-line-number="71"></td>
        <td id="LC71" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   You can define STBI_WRITE_NO_STDIO to disable the file variant of these</span></td>
      </tr>
      <tr>
        <td id="L72" class="blob-num js-line-number" data-line-number="72"></td>
        <td id="LC72" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   functions, so the library will not use stdio.h at all. However, this will</span></td>
      </tr>
      <tr>
        <td id="L73" class="blob-num js-line-number" data-line-number="73"></td>
        <td id="LC73" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   also disable HDR writing, because it requires stdio for formatted output.</span></td>
      </tr>
      <tr>
        <td id="L74" class="blob-num js-line-number" data-line-number="74"></td>
        <td id="LC74" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L75" class="blob-num js-line-number" data-line-number="75"></td>
        <td id="LC75" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Each function returns 0 on failure and non-0 on success.</span></td>
      </tr>
      <tr>
        <td id="L76" class="blob-num js-line-number" data-line-number="76"></td>
        <td id="LC76" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L77" class="blob-num js-line-number" data-line-number="77"></td>
        <td id="LC77" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   The functions create an image file defined by the parameters. The image</span></td>
      </tr>
      <tr>
        <td id="L78" class="blob-num js-line-number" data-line-number="78"></td>
        <td id="LC78" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   is a rectangle of pixels stored from left-to-right, top-to-bottom.</span></td>
      </tr>
      <tr>
        <td id="L79" class="blob-num js-line-number" data-line-number="79"></td>
        <td id="LC79" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Each pixel contains &#39;comp&#39; channels of data stored interleaved with 8-bits</span></td>
      </tr>
      <tr>
        <td id="L80" class="blob-num js-line-number" data-line-number="80"></td>
        <td id="LC80" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   per channel, in the following order: 1=Y, 2=YA, 3=RGB, 4=RGBA. (Y is</span></td>
      </tr>
      <tr>
        <td id="L81" class="blob-num js-line-number" data-line-number="81"></td>
        <td id="LC81" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   monochrome color.) The rectangle is &#39;w&#39; pixels wide and &#39;h&#39; pixels tall.</span></td>
      </tr>
      <tr>
        <td id="L82" class="blob-num js-line-number" data-line-number="82"></td>
        <td id="LC82" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   The *data pointer points to the first byte of the top-left-most pixel.</span></td>
      </tr>
      <tr>
        <td id="L83" class="blob-num js-line-number" data-line-number="83"></td>
        <td id="LC83" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   For PNG, &quot;stride_in_bytes&quot; is the distance in bytes from the first byte of</span></td>
      </tr>
      <tr>
        <td id="L84" class="blob-num js-line-number" data-line-number="84"></td>
        <td id="LC84" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   a row of pixels to the first byte of the next row of pixels.</span></td>
      </tr>
      <tr>
        <td id="L85" class="blob-num js-line-number" data-line-number="85"></td>
        <td id="LC85" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L86" class="blob-num js-line-number" data-line-number="86"></td>
        <td id="LC86" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   PNG creates output files with the same number of components as the input.</span></td>
      </tr>
      <tr>
        <td id="L87" class="blob-num js-line-number" data-line-number="87"></td>
        <td id="LC87" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   The BMP format expands Y to RGB in the file format and does not</span></td>
      </tr>
      <tr>
        <td id="L88" class="blob-num js-line-number" data-line-number="88"></td>
        <td id="LC88" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   output alpha.</span></td>
      </tr>
      <tr>
        <td id="L89" class="blob-num js-line-number" data-line-number="89"></td>
        <td id="LC89" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L90" class="blob-num js-line-number" data-line-number="90"></td>
        <td id="LC90" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   PNG supports writing rectangles of data even when the bytes storing rows of</span></td>
      </tr>
      <tr>
        <td id="L91" class="blob-num js-line-number" data-line-number="91"></td>
        <td id="LC91" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   data are not consecutive in memory (e.g. sub-rectangles of a larger image),</span></td>
      </tr>
      <tr>
        <td id="L92" class="blob-num js-line-number" data-line-number="92"></td>
        <td id="LC92" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   by supplying the stride between the beginning of adjacent rows. The other</span></td>
      </tr>
      <tr>
        <td id="L93" class="blob-num js-line-number" data-line-number="93"></td>
        <td id="LC93" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   formats do not. (Thus you cannot write a native-format BMP through the BMP</span></td>
      </tr>
      <tr>
        <td id="L94" class="blob-num js-line-number" data-line-number="94"></td>
        <td id="LC94" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   writer, both because it is in BGR order and because it may have padding</span></td>
      </tr>
      <tr>
        <td id="L95" class="blob-num js-line-number" data-line-number="95"></td>
        <td id="LC95" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   at the end of the line.)</span></td>
      </tr>
      <tr>
        <td id="L96" class="blob-num js-line-number" data-line-number="96"></td>
        <td id="LC96" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L97" class="blob-num js-line-number" data-line-number="97"></td>
        <td id="LC97" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   PNG allows you to set the deflate compression level by setting the global</span></td>
      </tr>
      <tr>
        <td id="L98" class="blob-num js-line-number" data-line-number="98"></td>
        <td id="LC98" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   variable &#39;stbi_write_png_compression_level&#39; (it defaults to 8).</span></td>
      </tr>
      <tr>
        <td id="L99" class="blob-num js-line-number" data-line-number="99"></td>
        <td id="LC99" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L100" class="blob-num js-line-number" data-line-number="100"></td>
        <td id="LC100" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   HDR expects linear float data. Since the format is always 32-bit rgb(e)</span></td>
      </tr>
      <tr>
        <td id="L101" class="blob-num js-line-number" data-line-number="101"></td>
        <td id="LC101" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   data, alpha (if provided) is discarded, and for monochrome data it is</span></td>
      </tr>
      <tr>
        <td id="L102" class="blob-num js-line-number" data-line-number="102"></td>
        <td id="LC102" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   replicated across all three channels.</span></td>
      </tr>
      <tr>
        <td id="L103" class="blob-num js-line-number" data-line-number="103"></td>
        <td id="LC103" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L104" class="blob-num js-line-number" data-line-number="104"></td>
        <td id="LC104" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   TGA supports RLE or non-RLE compressed data. To use non-RLE-compressed</span></td>
      </tr>
      <tr>
        <td id="L105" class="blob-num js-line-number" data-line-number="105"></td>
        <td id="LC105" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   data, set the global variable &#39;stbi_write_tga_with_rle&#39; to 0.</span></td>
      </tr>
      <tr>
        <td id="L106" class="blob-num js-line-number" data-line-number="106"></td>
        <td id="LC106" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   </span></td>
      </tr>
      <tr>
        <td id="L107" class="blob-num js-line-number" data-line-number="107"></td>
        <td id="LC107" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   JPEG does ignore alpha channels in input data; quality is between 1 and 100.</span></td>
      </tr>
      <tr>
        <td id="L108" class="blob-num js-line-number" data-line-number="108"></td>
        <td id="LC108" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Higher quality looks better but results in a bigger image.</span></td>
      </tr>
      <tr>
        <td id="L109" class="blob-num js-line-number" data-line-number="109"></td>
        <td id="LC109" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   JPEG baseline (no JPEG progressive).</span></td>
      </tr>
      <tr>
        <td id="L110" class="blob-num js-line-number" data-line-number="110"></td>
        <td id="LC110" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L111" class="blob-num js-line-number" data-line-number="111"></td>
        <td id="LC111" class="blob-code blob-code-inner js-file-line"><span class="pl-c">CREDITS:</span></td>
      </tr>
      <tr>
        <td id="L112" class="blob-num js-line-number" data-line-number="112"></td>
        <td id="LC112" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L113" class="blob-num js-line-number" data-line-number="113"></td>
        <td id="LC113" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L114" class="blob-num js-line-number" data-line-number="114"></td>
        <td id="LC114" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Sean Barrett           -    PNG/BMP/TGA </span></td>
      </tr>
      <tr>
        <td id="L115" class="blob-num js-line-number" data-line-number="115"></td>
        <td id="LC115" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Baldur Karlsson        -    HDR</span></td>
      </tr>
      <tr>
        <td id="L116" class="blob-num js-line-number" data-line-number="116"></td>
        <td id="LC116" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Jean-Sebastien Guay    -    TGA monochrome</span></td>
      </tr>
      <tr>
        <td id="L117" class="blob-num js-line-number" data-line-number="117"></td>
        <td id="LC117" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Tim Kelsey             -    misc enhancements</span></td>
      </tr>
      <tr>
        <td id="L118" class="blob-num js-line-number" data-line-number="118"></td>
        <td id="LC118" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Alan Hickman           -    TGA RLE</span></td>
      </tr>
      <tr>
        <td id="L119" class="blob-num js-line-number" data-line-number="119"></td>
        <td id="LC119" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Emmanuel Julien        -    initial file IO callback implementation</span></td>
      </tr>
      <tr>
        <td id="L120" class="blob-num js-line-number" data-line-number="120"></td>
        <td id="LC120" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Jon Olick              -    original jo_jpeg.cpp code</span></td>
      </tr>
      <tr>
        <td id="L121" class="blob-num js-line-number" data-line-number="121"></td>
        <td id="LC121" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Daniel Gibson          -    integrate JPEG, allow external zlib</span></td>
      </tr>
      <tr>
        <td id="L122" class="blob-num js-line-number" data-line-number="122"></td>
        <td id="LC122" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   Aarni Koskela          -    allow choosing PNG filter</span></td>
      </tr>
      <tr>
        <td id="L123" class="blob-num js-line-number" data-line-number="123"></td>
        <td id="LC123" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L124" class="blob-num js-line-number" data-line-number="124"></td>
        <td id="LC124" class="blob-code blob-code-inner js-file-line"><span class="pl-c">   bugfixes:</span></td>
      </tr>
      <tr>
        <td id="L125" class="blob-num js-line-number" data-line-number="125"></td>
        <td id="LC125" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      github:Chribba</span></td>
      </tr>
      <tr>
        <td id="L126" class="blob-num js-line-number" data-line-number="126"></td>
        <td id="LC126" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      Guillaume Chereau</span></td>
      </tr>
      <tr>
        <td id="L127" class="blob-num js-line-number" data-line-number="127"></td>
        <td id="LC127" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      github:jry2</span></td>
      </tr>
      <tr>
        <td id="L128" class="blob-num js-line-number" data-line-number="128"></td>
        <td id="LC128" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      github:romigrou</span></td>
      </tr>
      <tr>
        <td id="L129" class="blob-num js-line-number" data-line-number="129"></td>
        <td id="LC129" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      Sergio Gonzalez</span></td>
      </tr>
      <tr>
        <td id="L130" class="blob-num js-line-number" data-line-number="130"></td>
        <td id="LC130" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      Jonas Karlsson</span></td>
      </tr>
      <tr>
        <td id="L131" class="blob-num js-line-number" data-line-number="131"></td>
        <td id="LC131" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      Filip Wasil</span></td>
      </tr>
      <tr>
        <td id="L132" class="blob-num js-line-number" data-line-number="132"></td>
        <td id="LC132" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      Thatcher Ulrich</span></td>
      </tr>
      <tr>
        <td id="L133" class="blob-num js-line-number" data-line-number="133"></td>
        <td id="LC133" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      github:poppolopoppo</span></td>
      </tr>
      <tr>
        <td id="L134" class="blob-num js-line-number" data-line-number="134"></td>
        <td id="LC134" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      Patrick Boettcher</span></td>
      </tr>
      <tr>
        <td id="L135" class="blob-num js-line-number" data-line-number="135"></td>
        <td id="LC135" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      github:xeekworx</span></td>
      </tr>
      <tr>
        <td id="L136" class="blob-num js-line-number" data-line-number="136"></td>
        <td id="LC136" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      Cap Petschulat</span></td>
      </tr>
      <tr>
        <td id="L137" class="blob-num js-line-number" data-line-number="137"></td>
        <td id="LC137" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      Simon Rodriguez</span></td>
      </tr>
      <tr>
        <td id="L138" class="blob-num js-line-number" data-line-number="138"></td>
        <td id="LC138" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      Ivan Tikhonov</span></td>
      </tr>
      <tr>
        <td id="L139" class="blob-num js-line-number" data-line-number="139"></td>
        <td id="LC139" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      github:ignotion</span></td>
      </tr>
      <tr>
        <td id="L140" class="blob-num js-line-number" data-line-number="140"></td>
        <td id="LC140" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      Adam Schackart</span></td>
      </tr>
      <tr>
        <td id="L141" class="blob-num js-line-number" data-line-number="141"></td>
        <td id="LC141" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L142" class="blob-num js-line-number" data-line-number="142"></td>
        <td id="LC142" class="blob-code blob-code-inner js-file-line"><span class="pl-c">LICENSE</span></td>
      </tr>
      <tr>
        <td id="L143" class="blob-num js-line-number" data-line-number="143"></td>
        <td id="LC143" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L144" class="blob-num js-line-number" data-line-number="144"></td>
        <td id="LC144" class="blob-code blob-code-inner js-file-line"><span class="pl-c">  See end of file for license information.</span></td>
      </tr>
      <tr>
        <td id="L145" class="blob-num js-line-number" data-line-number="145"></td>
        <td id="LC145" class="blob-code blob-code-inner js-file-line"><span class="pl-c"></span></td>
      </tr>
      <tr>
        <td id="L146" class="blob-num js-line-number" data-line-number="146"></td>
        <td id="LC146" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L147" class="blob-num js-line-number" data-line-number="147"></td>
        <td id="LC147" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L148" class="blob-num js-line-number" data-line-number="148"></td>
        <td id="LC148" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> INCLUDE_STB_IMAGE_WRITE_H</td>
      </tr>
      <tr>
        <td id="L149" class="blob-num js-line-number" data-line-number="149"></td>
        <td id="LC149" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">INCLUDE_STB_IMAGE_WRITE_H</span></td>
      </tr>
      <tr>
        <td id="L150" class="blob-num js-line-number" data-line-number="150"></td>
        <td id="LC150" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L151" class="blob-num js-line-number" data-line-number="151"></td>
        <td id="LC151" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> if STB_IMAGE_WRITE_STATIC causes problems, try defining STBIWDEF to &#39;inline&#39; or &#39;static inline&#39;</span></td>
      </tr>
      <tr>
        <td id="L152" class="blob-num js-line-number" data-line-number="152"></td>
        <td id="LC152" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBIWDEF</td>
      </tr>
      <tr>
        <td id="L153" class="blob-num js-line-number" data-line-number="153"></td>
        <td id="LC153" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifdef</span> STB_IMAGE_WRITE_STATIC</td>
      </tr>
      <tr>
        <td id="L154" class="blob-num js-line-number" data-line-number="154"></td>
        <td id="LC154" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STBIWDEF</span>  <span class="pl-k">static</span></td>
      </tr>
      <tr>
        <td id="L155" class="blob-num js-line-number" data-line-number="155"></td>
        <td id="LC155" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L156" class="blob-num js-line-number" data-line-number="156"></td>
        <td id="LC156" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifdef</span> __cplusplus</td>
      </tr>
      <tr>
        <td id="L157" class="blob-num js-line-number" data-line-number="157"></td>
        <td id="LC157" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STBIWDEF</span>  <span class="pl-k">extern</span> <span class="pl-s"><span class="pl-pds">&quot;</span>C<span class="pl-pds">&quot;</span></span></td>
      </tr>
      <tr>
        <td id="L158" class="blob-num js-line-number" data-line-number="158"></td>
        <td id="LC158" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L159" class="blob-num js-line-number" data-line-number="159"></td>
        <td id="LC159" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STBIWDEF</span>  <span class="pl-k">extern</span></td>
      </tr>
      <tr>
        <td id="L160" class="blob-num js-line-number" data-line-number="160"></td>
        <td id="LC160" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L161" class="blob-num js-line-number" data-line-number="161"></td>
        <td id="LC161" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L162" class="blob-num js-line-number" data-line-number="162"></td>
        <td id="LC162" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L163" class="blob-num js-line-number" data-line-number="163"></td>
        <td id="LC163" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L164" class="blob-num js-line-number" data-line-number="164"></td>
        <td id="LC164" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STB_IMAGE_WRITE_STATIC  <span class="pl-c"><span class="pl-c">//</span> C++ forbids static forward declarations</span></td>
      </tr>
      <tr>
        <td id="L165" class="blob-num js-line-number" data-line-number="165"></td>
        <td id="LC165" class="blob-code blob-code-inner js-file-line"><span class="pl-k">extern</span> <span class="pl-k">int</span> stbi_write_tga_with_rle;</td>
      </tr>
      <tr>
        <td id="L166" class="blob-num js-line-number" data-line-number="166"></td>
        <td id="LC166" class="blob-code blob-code-inner js-file-line"><span class="pl-k">extern</span> <span class="pl-k">int</span> stbi_write_png_compression_level;</td>
      </tr>
      <tr>
        <td id="L167" class="blob-num js-line-number" data-line-number="167"></td>
        <td id="LC167" class="blob-code blob-code-inner js-file-line"><span class="pl-k">extern</span> <span class="pl-k">int</span> stbi_write_force_png_filter;</td>
      </tr>
      <tr>
        <td id="L168" class="blob-num js-line-number" data-line-number="168"></td>
        <td id="LC168" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L169" class="blob-num js-line-number" data-line-number="169"></td>
        <td id="LC169" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L170" class="blob-num js-line-number" data-line-number="170"></td>
        <td id="LC170" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBI_WRITE_NO_STDIO</td>
      </tr>
      <tr>
        <td id="L171" class="blob-num js-line-number" data-line-number="171"></td>
        <td id="LC171" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_png</span>(<span class="pl-k">char</span> <span class="pl-k">const</span> *filename, <span class="pl-k">int</span> w, <span class="pl-k">int</span> h, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span>  *data, <span class="pl-k">int</span> stride_in_bytes);</td>
      </tr>
      <tr>
        <td id="L172" class="blob-num js-line-number" data-line-number="172"></td>
        <td id="LC172" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_bmp</span>(<span class="pl-k">char</span> <span class="pl-k">const</span> *filename, <span class="pl-k">int</span> w, <span class="pl-k">int</span> h, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span>  *data);</td>
      </tr>
      <tr>
        <td id="L173" class="blob-num js-line-number" data-line-number="173"></td>
        <td id="LC173" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_tga</span>(<span class="pl-k">char</span> <span class="pl-k">const</span> *filename, <span class="pl-k">int</span> w, <span class="pl-k">int</span> h, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span>  *data);</td>
      </tr>
      <tr>
        <td id="L174" class="blob-num js-line-number" data-line-number="174"></td>
        <td id="LC174" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_hdr</span>(<span class="pl-k">char</span> <span class="pl-k">const</span> *filename, <span class="pl-k">int</span> w, <span class="pl-k">int</span> h, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">float</span> *data);</td>
      </tr>
      <tr>
        <td id="L175" class="blob-num js-line-number" data-line-number="175"></td>
        <td id="LC175" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_jpg</span>(<span class="pl-k">char</span> <span class="pl-k">const</span> *filename, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span>  *data, <span class="pl-k">int</span> quality);</td>
      </tr>
      <tr>
        <td id="L176" class="blob-num js-line-number" data-line-number="176"></td>
        <td id="LC176" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L177" class="blob-num js-line-number" data-line-number="177"></td>
        <td id="LC177" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L178" class="blob-num js-line-number" data-line-number="178"></td>
        <td id="LC178" class="blob-code blob-code-inner js-file-line"><span class="pl-k">typedef</span> <span class="pl-k">void</span> <span class="pl-en">stbi_write_func</span>(<span class="pl-k">void</span> *context, <span class="pl-k">void</span> *data, <span class="pl-k">int</span> size);</td>
      </tr>
      <tr>
        <td id="L179" class="blob-num js-line-number" data-line-number="179"></td>
        <td id="LC179" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L180" class="blob-num js-line-number" data-line-number="180"></td>
        <td id="LC180" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_png_to_func</span>(stbi_write_func *func, <span class="pl-k">void</span> *context, <span class="pl-k">int</span> w, <span class="pl-k">int</span> h, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span>  *data, <span class="pl-k">int</span> stride_in_bytes);</td>
      </tr>
      <tr>
        <td id="L181" class="blob-num js-line-number" data-line-number="181"></td>
        <td id="LC181" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_bmp_to_func</span>(stbi_write_func *func, <span class="pl-k">void</span> *context, <span class="pl-k">int</span> w, <span class="pl-k">int</span> h, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span>  *data);</td>
      </tr>
      <tr>
        <td id="L182" class="blob-num js-line-number" data-line-number="182"></td>
        <td id="LC182" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_tga_to_func</span>(stbi_write_func *func, <span class="pl-k">void</span> *context, <span class="pl-k">int</span> w, <span class="pl-k">int</span> h, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span>  *data);</td>
      </tr>
      <tr>
        <td id="L183" class="blob-num js-line-number" data-line-number="183"></td>
        <td id="LC183" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_hdr_to_func</span>(stbi_write_func *func, <span class="pl-k">void</span> *context, <span class="pl-k">int</span> w, <span class="pl-k">int</span> h, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">float</span> *data);</td>
      </tr>
      <tr>
        <td id="L184" class="blob-num js-line-number" data-line-number="184"></td>
        <td id="LC184" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_jpg_to_func</span>(stbi_write_func *func, <span class="pl-k">void</span> *context, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span>  *data, <span class="pl-k">int</span> quality);</td>
      </tr>
      <tr>
        <td id="L185" class="blob-num js-line-number" data-line-number="185"></td>
        <td id="LC185" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L186" class="blob-num js-line-number" data-line-number="186"></td>
        <td id="LC186" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">void</span> <span class="pl-en">stbi_flip_vertically_on_write</span>(<span class="pl-k">int</span> flip_boolean);</td>
      </tr>
      <tr>
        <td id="L187" class="blob-num js-line-number" data-line-number="187"></td>
        <td id="LC187" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L188" class="blob-num js-line-number" data-line-number="188"></td>
        <td id="LC188" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span><span class="pl-c"><span class="pl-c">//</span>INCLUDE_STB_IMAGE_WRITE_H</span></td>
      </tr>
      <tr>
        <td id="L189" class="blob-num js-line-number" data-line-number="189"></td>
        <td id="LC189" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L190" class="blob-num js-line-number" data-line-number="190"></td>
        <td id="LC190" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifdef</span> STB_IMAGE_WRITE_IMPLEMENTATION</td>
      </tr>
      <tr>
        <td id="L191" class="blob-num js-line-number" data-line-number="191"></td>
        <td id="LC191" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L192" class="blob-num js-line-number" data-line-number="192"></td>
        <td id="LC192" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifdef</span> _WIN32</td>
      </tr>
      <tr>
        <td id="L193" class="blob-num js-line-number" data-line-number="193"></td>
        <td id="LC193" class="blob-code blob-code-inner js-file-line">   #<span class="pl-k">ifndef</span> _CRT_SECURE_NO_WARNINGS</td>
      </tr>
      <tr>
        <td id="L194" class="blob-num js-line-number" data-line-number="194"></td>
        <td id="LC194" class="blob-code blob-code-inner js-file-line">   #<span class="pl-k">define</span> <span class="pl-en">_CRT_SECURE_NO_WARNINGS</span></td>
      </tr>
      <tr>
        <td id="L195" class="blob-num js-line-number" data-line-number="195"></td>
        <td id="LC195" class="blob-code blob-code-inner js-file-line">   #<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L196" class="blob-num js-line-number" data-line-number="196"></td>
        <td id="LC196" class="blob-code blob-code-inner js-file-line">   #<span class="pl-k">ifndef</span> _CRT_NONSTDC_NO_DEPRECATE</td>
      </tr>
      <tr>
        <td id="L197" class="blob-num js-line-number" data-line-number="197"></td>
        <td id="LC197" class="blob-code blob-code-inner js-file-line">   #<span class="pl-k">define</span> <span class="pl-en">_CRT_NONSTDC_NO_DEPRECATE</span></td>
      </tr>
      <tr>
        <td id="L198" class="blob-num js-line-number" data-line-number="198"></td>
        <td id="LC198" class="blob-code blob-code-inner js-file-line">   #<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L199" class="blob-num js-line-number" data-line-number="199"></td>
        <td id="LC199" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L200" class="blob-num js-line-number" data-line-number="200"></td>
        <td id="LC200" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L201" class="blob-num js-line-number" data-line-number="201"></td>
        <td id="LC201" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBI_WRITE_NO_STDIO</td>
      </tr>
      <tr>
        <td id="L202" class="blob-num js-line-number" data-line-number="202"></td>
        <td id="LC202" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">include</span> <span class="pl-s"><span class="pl-pds">&lt;</span>stdio.h<span class="pl-pds">&gt;</span></span></td>
      </tr>
      <tr>
        <td id="L203" class="blob-num js-line-number" data-line-number="203"></td>
        <td id="LC203" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span> <span class="pl-c"><span class="pl-c">//</span> STBI_WRITE_NO_STDIO</span></td>
      </tr>
      <tr>
        <td id="L204" class="blob-num js-line-number" data-line-number="204"></td>
        <td id="LC204" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L205" class="blob-num js-line-number" data-line-number="205"></td>
        <td id="LC205" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">include</span> <span class="pl-s"><span class="pl-pds">&lt;</span>stdarg.h<span class="pl-pds">&gt;</span></span></td>
      </tr>
      <tr>
        <td id="L206" class="blob-num js-line-number" data-line-number="206"></td>
        <td id="LC206" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">include</span> <span class="pl-s"><span class="pl-pds">&lt;</span>stdlib.h<span class="pl-pds">&gt;</span></span></td>
      </tr>
      <tr>
        <td id="L207" class="blob-num js-line-number" data-line-number="207"></td>
        <td id="LC207" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">include</span> <span class="pl-s"><span class="pl-pds">&lt;</span>string.h<span class="pl-pds">&gt;</span></span></td>
      </tr>
      <tr>
        <td id="L208" class="blob-num js-line-number" data-line-number="208"></td>
        <td id="LC208" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">include</span> <span class="pl-s"><span class="pl-pds">&lt;</span>math.h<span class="pl-pds">&gt;</span></span></td>
      </tr>
      <tr>
        <td id="L209" class="blob-num js-line-number" data-line-number="209"></td>
        <td id="LC209" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L210" class="blob-num js-line-number" data-line-number="210"></td>
        <td id="LC210" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">if</span> defined(STBIW_MALLOC) &amp;&amp; defined(STBIW_FREE) &amp;&amp; (defined(STBIW_REALLOC) || defined(STBIW_REALLOC_SIZED))</td>
      </tr>
      <tr>
        <td id="L211" class="blob-num js-line-number" data-line-number="211"></td>
        <td id="LC211" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> ok</span></td>
      </tr>
      <tr>
        <td id="L212" class="blob-num js-line-number" data-line-number="212"></td>
        <td id="LC212" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">elif</span> !defined(STBIW_MALLOC) &amp;&amp; !defined(STBIW_FREE) &amp;&amp; !defined(STBIW_REALLOC) &amp;&amp; !defined(STBIW_REALLOC_SIZED)</td>
      </tr>
      <tr>
        <td id="L213" class="blob-num js-line-number" data-line-number="213"></td>
        <td id="LC213" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> ok</span></td>
      </tr>
      <tr>
        <td id="L214" class="blob-num js-line-number" data-line-number="214"></td>
        <td id="LC214" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L215" class="blob-num js-line-number" data-line-number="215"></td>
        <td id="LC215" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">error</span> &quot;Must define all or none of STBIW_MALLOC, STBIW_FREE, and STBIW_REALLOC (or STBIW_REALLOC_SIZED).&quot;</td>
      </tr>
      <tr>
        <td id="L216" class="blob-num js-line-number" data-line-number="216"></td>
        <td id="LC216" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L217" class="blob-num js-line-number" data-line-number="217"></td>
        <td id="LC217" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L218" class="blob-num js-line-number" data-line-number="218"></td>
        <td id="LC218" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBIW_MALLOC</td>
      </tr>
      <tr>
        <td id="L219" class="blob-num js-line-number" data-line-number="219"></td>
        <td id="LC219" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STBIW_MALLOC</span>(<span class="pl-v">sz</span>)        malloc(sz)</td>
      </tr>
      <tr>
        <td id="L220" class="blob-num js-line-number" data-line-number="220"></td>
        <td id="LC220" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STBIW_REALLOC</span>(<span class="pl-v">p,newsz</span>)  realloc(p,newsz)</td>
      </tr>
      <tr>
        <td id="L221" class="blob-num js-line-number" data-line-number="221"></td>
        <td id="LC221" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STBIW_FREE</span>(<span class="pl-v">p</span>)           free(p)</td>
      </tr>
      <tr>
        <td id="L222" class="blob-num js-line-number" data-line-number="222"></td>
        <td id="LC222" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L223" class="blob-num js-line-number" data-line-number="223"></td>
        <td id="LC223" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L224" class="blob-num js-line-number" data-line-number="224"></td>
        <td id="LC224" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBIW_REALLOC_SIZED</td>
      </tr>
      <tr>
        <td id="L225" class="blob-num js-line-number" data-line-number="225"></td>
        <td id="LC225" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STBIW_REALLOC_SIZED</span>(<span class="pl-v">p,oldsz,newsz</span>) STBIW_REALLOC(p,newsz)</td>
      </tr>
      <tr>
        <td id="L226" class="blob-num js-line-number" data-line-number="226"></td>
        <td id="LC226" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L227" class="blob-num js-line-number" data-line-number="227"></td>
        <td id="LC227" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L228" class="blob-num js-line-number" data-line-number="228"></td>
        <td id="LC228" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L229" class="blob-num js-line-number" data-line-number="229"></td>
        <td id="LC229" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBIW_MEMMOVE</td>
      </tr>
      <tr>
        <td id="L230" class="blob-num js-line-number" data-line-number="230"></td>
        <td id="LC230" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STBIW_MEMMOVE</span>(<span class="pl-v">a,b,sz</span>) memmove(a,b,sz)</td>
      </tr>
      <tr>
        <td id="L231" class="blob-num js-line-number" data-line-number="231"></td>
        <td id="LC231" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L232" class="blob-num js-line-number" data-line-number="232"></td>
        <td id="LC232" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L233" class="blob-num js-line-number" data-line-number="233"></td>
        <td id="LC233" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L234" class="blob-num js-line-number" data-line-number="234"></td>
        <td id="LC234" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBIW_ASSERT</td>
      </tr>
      <tr>
        <td id="L235" class="blob-num js-line-number" data-line-number="235"></td>
        <td id="LC235" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">include</span> <span class="pl-s"><span class="pl-pds">&lt;</span>assert.h<span class="pl-pds">&gt;</span></span></td>
      </tr>
      <tr>
        <td id="L236" class="blob-num js-line-number" data-line-number="236"></td>
        <td id="LC236" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STBIW_ASSERT</span>(<span class="pl-v">x</span>) assert(x)</td>
      </tr>
      <tr>
        <td id="L237" class="blob-num js-line-number" data-line-number="237"></td>
        <td id="LC237" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L238" class="blob-num js-line-number" data-line-number="238"></td>
        <td id="LC238" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L239" class="blob-num js-line-number" data-line-number="239"></td>
        <td id="LC239" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STBIW_UCHAR</span>(<span class="pl-v">x</span>) (<span class="pl-k">unsigned</span> <span class="pl-k">char</span>) ((x) &amp; <span class="pl-c1">0xff</span>)</td>
      </tr>
      <tr>
        <td id="L240" class="blob-num js-line-number" data-line-number="240"></td>
        <td id="LC240" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L241" class="blob-num js-line-number" data-line-number="241"></td>
        <td id="LC241" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifdef</span> STB_IMAGE_WRITE_STATIC</td>
      </tr>
      <tr>
        <td id="L242" class="blob-num js-line-number" data-line-number="242"></td>
        <td id="LC242" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> stbi__flip_vertically_on_write=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L243" class="blob-num js-line-number" data-line-number="243"></td>
        <td id="LC243" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> stbi_write_png_compression_level = <span class="pl-c1">8</span>;</td>
      </tr>
      <tr>
        <td id="L244" class="blob-num js-line-number" data-line-number="244"></td>
        <td id="LC244" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> stbi_write_tga_with_rle = <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L245" class="blob-num js-line-number" data-line-number="245"></td>
        <td id="LC245" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> stbi_write_force_png_filter = -<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L246" class="blob-num js-line-number" data-line-number="246"></td>
        <td id="LC246" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L247" class="blob-num js-line-number" data-line-number="247"></td>
        <td id="LC247" class="blob-code blob-code-inner js-file-line"><span class="pl-k">int</span> stbi_write_png_compression_level = <span class="pl-c1">8</span>;</td>
      </tr>
      <tr>
        <td id="L248" class="blob-num js-line-number" data-line-number="248"></td>
        <td id="LC248" class="blob-code blob-code-inner js-file-line"><span class="pl-k">int</span> stbi__flip_vertically_on_write=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L249" class="blob-num js-line-number" data-line-number="249"></td>
        <td id="LC249" class="blob-code blob-code-inner js-file-line"><span class="pl-k">int</span> stbi_write_tga_with_rle = <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L250" class="blob-num js-line-number" data-line-number="250"></td>
        <td id="LC250" class="blob-code blob-code-inner js-file-line"><span class="pl-k">int</span> stbi_write_force_png_filter = -<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L251" class="blob-num js-line-number" data-line-number="251"></td>
        <td id="LC251" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L252" class="blob-num js-line-number" data-line-number="252"></td>
        <td id="LC252" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L253" class="blob-num js-line-number" data-line-number="253"></td>
        <td id="LC253" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">void</span> <span class="pl-en">stbi_flip_vertically_on_write</span>(<span class="pl-k">int</span> flag)</td>
      </tr>
      <tr>
        <td id="L254" class="blob-num js-line-number" data-line-number="254"></td>
        <td id="LC254" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L255" class="blob-num js-line-number" data-line-number="255"></td>
        <td id="LC255" class="blob-code blob-code-inner js-file-line">   stbi__flip_vertically_on_write = flag;</td>
      </tr>
      <tr>
        <td id="L256" class="blob-num js-line-number" data-line-number="256"></td>
        <td id="LC256" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L257" class="blob-num js-line-number" data-line-number="257"></td>
        <td id="LC257" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L258" class="blob-num js-line-number" data-line-number="258"></td>
        <td id="LC258" class="blob-code blob-code-inner js-file-line"><span class="pl-k">typedef</span> <span class="pl-k">struct</span></td>
      </tr>
      <tr>
        <td id="L259" class="blob-num js-line-number" data-line-number="259"></td>
        <td id="LC259" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L260" class="blob-num js-line-number" data-line-number="260"></td>
        <td id="LC260" class="blob-code blob-code-inner js-file-line">   stbi_write_func *func;</td>
      </tr>
      <tr>
        <td id="L261" class="blob-num js-line-number" data-line-number="261"></td>
        <td id="LC261" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">void</span> *context;</td>
      </tr>
      <tr>
        <td id="L262" class="blob-num js-line-number" data-line-number="262"></td>
        <td id="LC262" class="blob-code blob-code-inner js-file-line">} stbi__write_context;</td>
      </tr>
      <tr>
        <td id="L263" class="blob-num js-line-number" data-line-number="263"></td>
        <td id="LC263" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L264" class="blob-num js-line-number" data-line-number="264"></td>
        <td id="LC264" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> initialize a callback-based context</span></td>
      </tr>
      <tr>
        <td id="L265" class="blob-num js-line-number" data-line-number="265"></td>
        <td id="LC265" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbi__start_write_callbacks</span>(stbi__write_context *s, stbi_write_func *c, <span class="pl-k">void</span> *context)</td>
      </tr>
      <tr>
        <td id="L266" class="blob-num js-line-number" data-line-number="266"></td>
        <td id="LC266" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L267" class="blob-num js-line-number" data-line-number="267"></td>
        <td id="LC267" class="blob-code blob-code-inner js-file-line">   s-&gt;<span class="pl-smi">func</span>    = c;</td>
      </tr>
      <tr>
        <td id="L268" class="blob-num js-line-number" data-line-number="268"></td>
        <td id="LC268" class="blob-code blob-code-inner js-file-line">   s-&gt;<span class="pl-smi">context</span> = context;</td>
      </tr>
      <tr>
        <td id="L269" class="blob-num js-line-number" data-line-number="269"></td>
        <td id="LC269" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L270" class="blob-num js-line-number" data-line-number="270"></td>
        <td id="LC270" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L271" class="blob-num js-line-number" data-line-number="271"></td>
        <td id="LC271" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBI_WRITE_NO_STDIO</td>
      </tr>
      <tr>
        <td id="L272" class="blob-num js-line-number" data-line-number="272"></td>
        <td id="LC272" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L273" class="blob-num js-line-number" data-line-number="273"></td>
        <td id="LC273" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbi__stdio_write</span>(<span class="pl-k">void</span> *context, <span class="pl-k">void</span> *data, <span class="pl-k">int</span> size)</td>
      </tr>
      <tr>
        <td id="L274" class="blob-num js-line-number" data-line-number="274"></td>
        <td id="LC274" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L275" class="blob-num js-line-number" data-line-number="275"></td>
        <td id="LC275" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">fwrite</span>(data,<span class="pl-c1">1</span>,size,(<span class="pl-c1">FILE</span>*) context);</td>
      </tr>
      <tr>
        <td id="L276" class="blob-num js-line-number" data-line-number="276"></td>
        <td id="LC276" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L277" class="blob-num js-line-number" data-line-number="277"></td>
        <td id="LC277" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L278" class="blob-num js-line-number" data-line-number="278"></td>
        <td id="LC278" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> <span class="pl-en">stbi__start_write_file</span>(stbi__write_context *s, <span class="pl-k">const</span> <span class="pl-k">char</span> *filename)</td>
      </tr>
      <tr>
        <td id="L279" class="blob-num js-line-number" data-line-number="279"></td>
        <td id="LC279" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L280" class="blob-num js-line-number" data-line-number="280"></td>
        <td id="LC280" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">FILE</span> *f;</td>
      </tr>
      <tr>
        <td id="L281" class="blob-num js-line-number" data-line-number="281"></td>
        <td id="LC281" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifdef</span> STBI_MSC_SECURE_CRT</td>
      </tr>
      <tr>
        <td id="L282" class="blob-num js-line-number" data-line-number="282"></td>
        <td id="LC282" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (<span class="pl-c1">fopen_s</span>(&amp;f, filename, <span class="pl-s"><span class="pl-pds">&quot;</span>wb<span class="pl-pds">&quot;</span></span>))</td>
      </tr>
      <tr>
        <td id="L283" class="blob-num js-line-number" data-line-number="283"></td>
        <td id="LC283" class="blob-code blob-code-inner js-file-line">      f = <span class="pl-c1">NULL</span>;</td>
      </tr>
      <tr>
        <td id="L284" class="blob-num js-line-number" data-line-number="284"></td>
        <td id="LC284" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L285" class="blob-num js-line-number" data-line-number="285"></td>
        <td id="LC285" class="blob-code blob-code-inner js-file-line">   f = <span class="pl-c1">fopen</span>(filename, <span class="pl-s"><span class="pl-pds">&quot;</span>wb<span class="pl-pds">&quot;</span></span>);</td>
      </tr>
      <tr>
        <td id="L286" class="blob-num js-line-number" data-line-number="286"></td>
        <td id="LC286" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L287" class="blob-num js-line-number" data-line-number="287"></td>
        <td id="LC287" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbi__start_write_callbacks</span>(s, stbi__stdio_write, (<span class="pl-k">void</span> *) f);</td>
      </tr>
      <tr>
        <td id="L288" class="blob-num js-line-number" data-line-number="288"></td>
        <td id="LC288" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> f != <span class="pl-c1">NULL</span>;</td>
      </tr>
      <tr>
        <td id="L289" class="blob-num js-line-number" data-line-number="289"></td>
        <td id="LC289" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L290" class="blob-num js-line-number" data-line-number="290"></td>
        <td id="LC290" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L291" class="blob-num js-line-number" data-line-number="291"></td>
        <td id="LC291" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbi__end_write_file</span>(stbi__write_context *s)</td>
      </tr>
      <tr>
        <td id="L292" class="blob-num js-line-number" data-line-number="292"></td>
        <td id="LC292" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L293" class="blob-num js-line-number" data-line-number="293"></td>
        <td id="LC293" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">fclose</span>((<span class="pl-c1">FILE</span> *)s-&gt;<span class="pl-smi">context</span>);</td>
      </tr>
      <tr>
        <td id="L294" class="blob-num js-line-number" data-line-number="294"></td>
        <td id="LC294" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L295" class="blob-num js-line-number" data-line-number="295"></td>
        <td id="LC295" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L296" class="blob-num js-line-number" data-line-number="296"></td>
        <td id="LC296" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span> <span class="pl-c"><span class="pl-c">//</span> !STBI_WRITE_NO_STDIO</span></td>
      </tr>
      <tr>
        <td id="L297" class="blob-num js-line-number" data-line-number="297"></td>
        <td id="LC297" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L298" class="blob-num js-line-number" data-line-number="298"></td>
        <td id="LC298" class="blob-code blob-code-inner js-file-line"><span class="pl-k">typedef</span> <span class="pl-k">unsigned</span> <span class="pl-k">int</span> stbiw_uint32;</td>
      </tr>
      <tr>
        <td id="L299" class="blob-num js-line-number" data-line-number="299"></td>
        <td id="LC299" class="blob-code blob-code-inner js-file-line"><span class="pl-k">typedef</span> <span class="pl-k">int</span> stb_image_write_test[<span class="pl-k">sizeof</span>(stbiw_uint32)==<span class="pl-c1">4</span> ? <span class="pl-c1">1</span> : -<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L300" class="blob-num js-line-number" data-line-number="300"></td>
        <td id="LC300" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L301" class="blob-num js-line-number" data-line-number="301"></td>
        <td id="LC301" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__writefv</span>(stbi__write_context *s, <span class="pl-k">const</span> <span class="pl-k">char</span> *fmt, <span class="pl-c1">va_list</span> v)</td>
      </tr>
      <tr>
        <td id="L302" class="blob-num js-line-number" data-line-number="302"></td>
        <td id="LC302" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L303" class="blob-num js-line-number" data-line-number="303"></td>
        <td id="LC303" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">while</span> (*fmt) {</td>
      </tr>
      <tr>
        <td id="L304" class="blob-num js-line-number" data-line-number="304"></td>
        <td id="LC304" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">switch</span> (*fmt++) {</td>
      </tr>
      <tr>
        <td id="L305" class="blob-num js-line-number" data-line-number="305"></td>
        <td id="LC305" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-s"><span class="pl-pds">&#39;</span> <span class="pl-pds">&#39;</span></span>: <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L306" class="blob-num js-line-number" data-line-number="306"></td>
        <td id="LC306" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-s"><span class="pl-pds">&#39;</span>1<span class="pl-pds">&#39;</span></span>: { <span class="pl-k">unsigned</span> <span class="pl-k">char</span> x = <span class="pl-c1">STBIW_UCHAR</span>(<span class="pl-c1">va_arg</span>(v, <span class="pl-k">int</span>));</td>
      </tr>
      <tr>
        <td id="L307" class="blob-num js-line-number" data-line-number="307"></td>
        <td id="LC307" class="blob-code blob-code-inner js-file-line">                     s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>,&amp;x,<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L308" class="blob-num js-line-number" data-line-number="308"></td>
        <td id="LC308" class="blob-code blob-code-inner js-file-line">                     <span class="pl-k">break</span>; }</td>
      </tr>
      <tr>
        <td id="L309" class="blob-num js-line-number" data-line-number="309"></td>
        <td id="LC309" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-s"><span class="pl-pds">&#39;</span>2<span class="pl-pds">&#39;</span></span>: { <span class="pl-k">int</span> x = <span class="pl-c1">va_arg</span>(v,<span class="pl-k">int</span>);</td>
      </tr>
      <tr>
        <td id="L310" class="blob-num js-line-number" data-line-number="310"></td>
        <td id="LC310" class="blob-code blob-code-inner js-file-line">                     <span class="pl-k">unsigned</span> <span class="pl-k">char</span> b[<span class="pl-c1">2</span>];</td>
      </tr>
      <tr>
        <td id="L311" class="blob-num js-line-number" data-line-number="311"></td>
        <td id="LC311" class="blob-code blob-code-inner js-file-line">                     b[<span class="pl-c1">0</span>] = <span class="pl-c1">STBIW_UCHAR</span>(x);</td>
      </tr>
      <tr>
        <td id="L312" class="blob-num js-line-number" data-line-number="312"></td>
        <td id="LC312" class="blob-code blob-code-inner js-file-line">                     b[<span class="pl-c1">1</span>] = <span class="pl-c1">STBIW_UCHAR</span>(x&gt;&gt;<span class="pl-c1">8</span>);</td>
      </tr>
      <tr>
        <td id="L313" class="blob-num js-line-number" data-line-number="313"></td>
        <td id="LC313" class="blob-code blob-code-inner js-file-line">                     s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>,b,<span class="pl-c1">2</span>);</td>
      </tr>
      <tr>
        <td id="L314" class="blob-num js-line-number" data-line-number="314"></td>
        <td id="LC314" class="blob-code blob-code-inner js-file-line">                     <span class="pl-k">break</span>; }</td>
      </tr>
      <tr>
        <td id="L315" class="blob-num js-line-number" data-line-number="315"></td>
        <td id="LC315" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-s"><span class="pl-pds">&#39;</span>4<span class="pl-pds">&#39;</span></span>: { stbiw_uint32 x = <span class="pl-c1">va_arg</span>(v,<span class="pl-k">int</span>);</td>
      </tr>
      <tr>
        <td id="L316" class="blob-num js-line-number" data-line-number="316"></td>
        <td id="LC316" class="blob-code blob-code-inner js-file-line">                     <span class="pl-k">unsigned</span> <span class="pl-k">char</span> b[<span class="pl-c1">4</span>];</td>
      </tr>
      <tr>
        <td id="L317" class="blob-num js-line-number" data-line-number="317"></td>
        <td id="LC317" class="blob-code blob-code-inner js-file-line">                     b[<span class="pl-c1">0</span>]=<span class="pl-c1">STBIW_UCHAR</span>(x);</td>
      </tr>
      <tr>
        <td id="L318" class="blob-num js-line-number" data-line-number="318"></td>
        <td id="LC318" class="blob-code blob-code-inner js-file-line">                     b[<span class="pl-c1">1</span>]=<span class="pl-c1">STBIW_UCHAR</span>(x&gt;&gt;<span class="pl-c1">8</span>);</td>
      </tr>
      <tr>
        <td id="L319" class="blob-num js-line-number" data-line-number="319"></td>
        <td id="LC319" class="blob-code blob-code-inner js-file-line">                     b[<span class="pl-c1">2</span>]=<span class="pl-c1">STBIW_UCHAR</span>(x&gt;&gt;<span class="pl-c1">16</span>);</td>
      </tr>
      <tr>
        <td id="L320" class="blob-num js-line-number" data-line-number="320"></td>
        <td id="LC320" class="blob-code blob-code-inner js-file-line">                     b[<span class="pl-c1">3</span>]=<span class="pl-c1">STBIW_UCHAR</span>(x&gt;&gt;<span class="pl-c1">24</span>);</td>
      </tr>
      <tr>
        <td id="L321" class="blob-num js-line-number" data-line-number="321"></td>
        <td id="LC321" class="blob-code blob-code-inner js-file-line">                     s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>,b,<span class="pl-c1">4</span>);</td>
      </tr>
      <tr>
        <td id="L322" class="blob-num js-line-number" data-line-number="322"></td>
        <td id="LC322" class="blob-code blob-code-inner js-file-line">                     <span class="pl-k">break</span>; }</td>
      </tr>
      <tr>
        <td id="L323" class="blob-num js-line-number" data-line-number="323"></td>
        <td id="LC323" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">default</span>:</td>
      </tr>
      <tr>
        <td id="L324" class="blob-num js-line-number" data-line-number="324"></td>
        <td id="LC324" class="blob-code blob-code-inner js-file-line">            <span class="pl-c1">STBIW_ASSERT</span>(<span class="pl-c1">0</span>);</td>
      </tr>
      <tr>
        <td id="L325" class="blob-num js-line-number" data-line-number="325"></td>
        <td id="LC325" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">return</span>;</td>
      </tr>
      <tr>
        <td id="L326" class="blob-num js-line-number" data-line-number="326"></td>
        <td id="LC326" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L327" class="blob-num js-line-number" data-line-number="327"></td>
        <td id="LC327" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L328" class="blob-num js-line-number" data-line-number="328"></td>
        <td id="LC328" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L329" class="blob-num js-line-number" data-line-number="329"></td>
        <td id="LC329" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L330" class="blob-num js-line-number" data-line-number="330"></td>
        <td id="LC330" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__writef</span>(stbi__write_context *s, <span class="pl-k">const</span> <span class="pl-k">char</span> *fmt, ...)</td>
      </tr>
      <tr>
        <td id="L331" class="blob-num js-line-number" data-line-number="331"></td>
        <td id="LC331" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L332" class="blob-num js-line-number" data-line-number="332"></td>
        <td id="LC332" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">va_list</span> v;</td>
      </tr>
      <tr>
        <td id="L333" class="blob-num js-line-number" data-line-number="333"></td>
        <td id="LC333" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">va_start</span>(v, fmt);</td>
      </tr>
      <tr>
        <td id="L334" class="blob-num js-line-number" data-line-number="334"></td>
        <td id="LC334" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__writefv</span>(s, fmt, v);</td>
      </tr>
      <tr>
        <td id="L335" class="blob-num js-line-number" data-line-number="335"></td>
        <td id="LC335" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">va_end</span>(v);</td>
      </tr>
      <tr>
        <td id="L336" class="blob-num js-line-number" data-line-number="336"></td>
        <td id="LC336" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L337" class="blob-num js-line-number" data-line-number="337"></td>
        <td id="LC337" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L338" class="blob-num js-line-number" data-line-number="338"></td>
        <td id="LC338" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__putc</span>(stbi__write_context *s, <span class="pl-k">unsigned</span> <span class="pl-k">char</span> c)</td>
      </tr>
      <tr>
        <td id="L339" class="blob-num js-line-number" data-line-number="339"></td>
        <td id="LC339" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L340" class="blob-num js-line-number" data-line-number="340"></td>
        <td id="LC340" class="blob-code blob-code-inner js-file-line">   s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, &amp;c, <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L341" class="blob-num js-line-number" data-line-number="341"></td>
        <td id="LC341" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L342" class="blob-num js-line-number" data-line-number="342"></td>
        <td id="LC342" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L343" class="blob-num js-line-number" data-line-number="343"></td>
        <td id="LC343" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__write3</span>(stbi__write_context *s, <span class="pl-k">unsigned</span> <span class="pl-k">char</span> a, <span class="pl-k">unsigned</span> <span class="pl-k">char</span> b, <span class="pl-k">unsigned</span> <span class="pl-k">char</span> c)</td>
      </tr>
      <tr>
        <td id="L344" class="blob-num js-line-number" data-line-number="344"></td>
        <td id="LC344" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L345" class="blob-num js-line-number" data-line-number="345"></td>
        <td id="LC345" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> arr[<span class="pl-c1">3</span>];</td>
      </tr>
      <tr>
        <td id="L346" class="blob-num js-line-number" data-line-number="346"></td>
        <td id="LC346" class="blob-code blob-code-inner js-file-line">   arr[<span class="pl-c1">0</span>] = a, arr[<span class="pl-c1">1</span>] = b, arr[<span class="pl-c1">2</span>] = c;</td>
      </tr>
      <tr>
        <td id="L347" class="blob-num js-line-number" data-line-number="347"></td>
        <td id="LC347" class="blob-code blob-code-inner js-file-line">   s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, arr, <span class="pl-c1">3</span>);</td>
      </tr>
      <tr>
        <td id="L348" class="blob-num js-line-number" data-line-number="348"></td>
        <td id="LC348" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L349" class="blob-num js-line-number" data-line-number="349"></td>
        <td id="LC349" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L350" class="blob-num js-line-number" data-line-number="350"></td>
        <td id="LC350" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__write_pixel</span>(stbi__write_context *s, <span class="pl-k">int</span> rgb_dir, <span class="pl-k">int</span> comp, <span class="pl-k">int</span> write_alpha, <span class="pl-k">int</span> expand_mono, <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *d)</td>
      </tr>
      <tr>
        <td id="L351" class="blob-num js-line-number" data-line-number="351"></td>
        <td id="LC351" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L352" class="blob-num js-line-number" data-line-number="352"></td>
        <td id="LC352" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> bg[<span class="pl-c1">3</span>] = { <span class="pl-c1">255</span>, <span class="pl-c1">0</span>, <span class="pl-c1">255</span>}, px[<span class="pl-c1">3</span>];</td>
      </tr>
      <tr>
        <td id="L353" class="blob-num js-line-number" data-line-number="353"></td>
        <td id="LC353" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> k;</td>
      </tr>
      <tr>
        <td id="L354" class="blob-num js-line-number" data-line-number="354"></td>
        <td id="LC354" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L355" class="blob-num js-line-number" data-line-number="355"></td>
        <td id="LC355" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (write_alpha &lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L356" class="blob-num js-line-number" data-line-number="356"></td>
        <td id="LC356" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, &amp;d[comp - <span class="pl-c1">1</span>], <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L357" class="blob-num js-line-number" data-line-number="357"></td>
        <td id="LC357" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L358" class="blob-num js-line-number" data-line-number="358"></td>
        <td id="LC358" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">switch</span> (comp) {</td>
      </tr>
      <tr>
        <td id="L359" class="blob-num js-line-number" data-line-number="359"></td>
        <td id="LC359" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">2</span>: <span class="pl-c"><span class="pl-c">//</span> 2 pixels = mono + alpha, alpha is written separately, so same as 1-channel case</span></td>
      </tr>
      <tr>
        <td id="L360" class="blob-num js-line-number" data-line-number="360"></td>
        <td id="LC360" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">1</span>:</td>
      </tr>
      <tr>
        <td id="L361" class="blob-num js-line-number" data-line-number="361"></td>
        <td id="LC361" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">if</span> (expand_mono)</td>
      </tr>
      <tr>
        <td id="L362" class="blob-num js-line-number" data-line-number="362"></td>
        <td id="LC362" class="blob-code blob-code-inner js-file-line">            <span class="pl-c1">stbiw__write3</span>(s, d[<span class="pl-c1">0</span>], d[<span class="pl-c1">0</span>], d[<span class="pl-c1">0</span>]); <span class="pl-c"><span class="pl-c">//</span> monochrome bmp</span></td>
      </tr>
      <tr>
        <td id="L363" class="blob-num js-line-number" data-line-number="363"></td>
        <td id="LC363" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L364" class="blob-num js-line-number" data-line-number="364"></td>
        <td id="LC364" class="blob-code blob-code-inner js-file-line">            s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, d, <span class="pl-c1">1</span>);  <span class="pl-c"><span class="pl-c">//</span> monochrome TGA</span></td>
      </tr>
      <tr>
        <td id="L365" class="blob-num js-line-number" data-line-number="365"></td>
        <td id="LC365" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L366" class="blob-num js-line-number" data-line-number="366"></td>
        <td id="LC366" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">4</span>:</td>
      </tr>
      <tr>
        <td id="L367" class="blob-num js-line-number" data-line-number="367"></td>
        <td id="LC367" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">if</span> (!write_alpha) {</td>
      </tr>
      <tr>
        <td id="L368" class="blob-num js-line-number" data-line-number="368"></td>
        <td id="LC368" class="blob-code blob-code-inner js-file-line">            <span class="pl-c"><span class="pl-c">//</span> composite against pink background</span></td>
      </tr>
      <tr>
        <td id="L369" class="blob-num js-line-number" data-line-number="369"></td>
        <td id="LC369" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">for</span> (k = <span class="pl-c1">0</span>; k &lt; <span class="pl-c1">3</span>; ++k)</td>
      </tr>
      <tr>
        <td id="L370" class="blob-num js-line-number" data-line-number="370"></td>
        <td id="LC370" class="blob-code blob-code-inner js-file-line">               px[k] = bg[k] + ((d[k] - bg[k]) * d[<span class="pl-c1">3</span>]) / <span class="pl-c1">255</span>;</td>
      </tr>
      <tr>
        <td id="L371" class="blob-num js-line-number" data-line-number="371"></td>
        <td id="LC371" class="blob-code blob-code-inner js-file-line">            <span class="pl-c1">stbiw__write3</span>(s, px[<span class="pl-c1">1</span> - rgb_dir], px[<span class="pl-c1">1</span>], px[<span class="pl-c1">1</span> + rgb_dir]);</td>
      </tr>
      <tr>
        <td id="L372" class="blob-num js-line-number" data-line-number="372"></td>
        <td id="LC372" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L373" class="blob-num js-line-number" data-line-number="373"></td>
        <td id="LC373" class="blob-code blob-code-inner js-file-line">         }</td>
      </tr>
      <tr>
        <td id="L374" class="blob-num js-line-number" data-line-number="374"></td>
        <td id="LC374" class="blob-code blob-code-inner js-file-line">         <span class="pl-c"><span class="pl-c">/*</span> FALLTHROUGH <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L375" class="blob-num js-line-number" data-line-number="375"></td>
        <td id="LC375" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">case</span> <span class="pl-c1">3</span>:</td>
      </tr>
      <tr>
        <td id="L376" class="blob-num js-line-number" data-line-number="376"></td>
        <td id="LC376" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__write3</span>(s, d[<span class="pl-c1">1</span> - rgb_dir], d[<span class="pl-c1">1</span>], d[<span class="pl-c1">1</span> + rgb_dir]);</td>
      </tr>
      <tr>
        <td id="L377" class="blob-num js-line-number" data-line-number="377"></td>
        <td id="LC377" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L378" class="blob-num js-line-number" data-line-number="378"></td>
        <td id="LC378" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L379" class="blob-num js-line-number" data-line-number="379"></td>
        <td id="LC379" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (write_alpha &gt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L380" class="blob-num js-line-number" data-line-number="380"></td>
        <td id="LC380" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, &amp;d[comp - <span class="pl-c1">1</span>], <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L381" class="blob-num js-line-number" data-line-number="381"></td>
        <td id="LC381" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L382" class="blob-num js-line-number" data-line-number="382"></td>
        <td id="LC382" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L383" class="blob-num js-line-number" data-line-number="383"></td>
        <td id="LC383" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__write_pixels</span>(stbi__write_context *s, <span class="pl-k">int</span> rgb_dir, <span class="pl-k">int</span> vdir, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">void</span> *data, <span class="pl-k">int</span> write_alpha, <span class="pl-k">int</span> scanline_pad, <span class="pl-k">int</span> expand_mono)</td>
      </tr>
      <tr>
        <td id="L384" class="blob-num js-line-number" data-line-number="384"></td>
        <td id="LC384" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L385" class="blob-num js-line-number" data-line-number="385"></td>
        <td id="LC385" class="blob-code blob-code-inner js-file-line">   stbiw_uint32 zero = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L386" class="blob-num js-line-number" data-line-number="386"></td>
        <td id="LC386" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> i,j, j_end;</td>
      </tr>
      <tr>
        <td id="L387" class="blob-num js-line-number" data-line-number="387"></td>
        <td id="LC387" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L388" class="blob-num js-line-number" data-line-number="388"></td>
        <td id="LC388" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (y &lt;= <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L389" class="blob-num js-line-number" data-line-number="389"></td>
        <td id="LC389" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span>;</td>
      </tr>
      <tr>
        <td id="L390" class="blob-num js-line-number" data-line-number="390"></td>
        <td id="LC390" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L391" class="blob-num js-line-number" data-line-number="391"></td>
        <td id="LC391" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (stbi__flip_vertically_on_write)</td>
      </tr>
      <tr>
        <td id="L392" class="blob-num js-line-number" data-line-number="392"></td>
        <td id="LC392" class="blob-code blob-code-inner js-file-line">      vdir *= -<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L393" class="blob-num js-line-number" data-line-number="393"></td>
        <td id="LC393" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L394" class="blob-num js-line-number" data-line-number="394"></td>
        <td id="LC394" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (vdir &lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L395" class="blob-num js-line-number" data-line-number="395"></td>
        <td id="LC395" class="blob-code blob-code-inner js-file-line">      j_end = -<span class="pl-c1">1</span>, j = y-<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L396" class="blob-num js-line-number" data-line-number="396"></td>
        <td id="LC396" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L397" class="blob-num js-line-number" data-line-number="397"></td>
        <td id="LC397" class="blob-code blob-code-inner js-file-line">      j_end =  y, j = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L398" class="blob-num js-line-number" data-line-number="398"></td>
        <td id="LC398" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L399" class="blob-num js-line-number" data-line-number="399"></td>
        <td id="LC399" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span> (; j != j_end; j += vdir) {</td>
      </tr>
      <tr>
        <td id="L400" class="blob-num js-line-number" data-line-number="400"></td>
        <td id="LC400" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (i=<span class="pl-c1">0</span>; i &lt; x; ++i) {</td>
      </tr>
      <tr>
        <td id="L401" class="blob-num js-line-number" data-line-number="401"></td>
        <td id="LC401" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *d = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *) data + (j*x+i)*comp;</td>
      </tr>
      <tr>
        <td id="L402" class="blob-num js-line-number" data-line-number="402"></td>
        <td id="LC402" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__write_pixel</span>(s, rgb_dir, comp, write_alpha, expand_mono, d);</td>
      </tr>
      <tr>
        <td id="L403" class="blob-num js-line-number" data-line-number="403"></td>
        <td id="LC403" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L404" class="blob-num js-line-number" data-line-number="404"></td>
        <td id="LC404" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, &amp;zero, scanline_pad);</td>
      </tr>
      <tr>
        <td id="L405" class="blob-num js-line-number" data-line-number="405"></td>
        <td id="LC405" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L406" class="blob-num js-line-number" data-line-number="406"></td>
        <td id="LC406" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L407" class="blob-num js-line-number" data-line-number="407"></td>
        <td id="LC407" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L408" class="blob-num js-line-number" data-line-number="408"></td>
        <td id="LC408" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> <span class="pl-en">stbiw__outfile</span>(stbi__write_context *s, <span class="pl-k">int</span> rgb_dir, <span class="pl-k">int</span> vdir, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">int</span> expand_mono, <span class="pl-k">void</span> *data, <span class="pl-k">int</span> alpha, <span class="pl-k">int</span> pad, <span class="pl-k">const</span> <span class="pl-k">char</span> *fmt, ...)</td>
      </tr>
      <tr>
        <td id="L409" class="blob-num js-line-number" data-line-number="409"></td>
        <td id="LC409" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L410" class="blob-num js-line-number" data-line-number="410"></td>
        <td id="LC410" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (y &lt; <span class="pl-c1">0</span> || x &lt; <span class="pl-c1">0</span>) {</td>
      </tr>
      <tr>
        <td id="L411" class="blob-num js-line-number" data-line-number="411"></td>
        <td id="LC411" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L412" class="blob-num js-line-number" data-line-number="412"></td>
        <td id="LC412" class="blob-code blob-code-inner js-file-line">   } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L413" class="blob-num js-line-number" data-line-number="413"></td>
        <td id="LC413" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">va_list</span> v;</td>
      </tr>
      <tr>
        <td id="L414" class="blob-num js-line-number" data-line-number="414"></td>
        <td id="LC414" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">va_start</span>(v, fmt);</td>
      </tr>
      <tr>
        <td id="L415" class="blob-num js-line-number" data-line-number="415"></td>
        <td id="LC415" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__writefv</span>(s, fmt, v);</td>
      </tr>
      <tr>
        <td id="L416" class="blob-num js-line-number" data-line-number="416"></td>
        <td id="LC416" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">va_end</span>(v);</td>
      </tr>
      <tr>
        <td id="L417" class="blob-num js-line-number" data-line-number="417"></td>
        <td id="LC417" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__write_pixels</span>(s,rgb_dir,vdir,x,y,comp,data,alpha,pad, expand_mono);</td>
      </tr>
      <tr>
        <td id="L418" class="blob-num js-line-number" data-line-number="418"></td>
        <td id="LC418" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L419" class="blob-num js-line-number" data-line-number="419"></td>
        <td id="LC419" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L420" class="blob-num js-line-number" data-line-number="420"></td>
        <td id="LC420" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L421" class="blob-num js-line-number" data-line-number="421"></td>
        <td id="LC421" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L422" class="blob-num js-line-number" data-line-number="422"></td>
        <td id="LC422" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> <span class="pl-en">stbi_write_bmp_core</span>(stbi__write_context *s, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span> *data)</td>
      </tr>
      <tr>
        <td id="L423" class="blob-num js-line-number" data-line-number="423"></td>
        <td id="LC423" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L424" class="blob-num js-line-number" data-line-number="424"></td>
        <td id="LC424" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> pad = (-x*<span class="pl-c1">3</span>) &amp; <span class="pl-c1">3</span>;</td>
      </tr>
      <tr>
        <td id="L425" class="blob-num js-line-number" data-line-number="425"></td>
        <td id="LC425" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">stbiw__outfile</span>(s,-<span class="pl-c1">1</span>,-<span class="pl-c1">1</span>,x,y,comp,<span class="pl-c1">1</span>,(<span class="pl-k">void</span> *) data,<span class="pl-c1">0</span>,pad,</td>
      </tr>
      <tr>
        <td id="L426" class="blob-num js-line-number" data-line-number="426"></td>
        <td id="LC426" class="blob-code blob-code-inner js-file-line">           <span class="pl-s"><span class="pl-pds">&quot;</span>11 4 22 4<span class="pl-pds">&quot;</span></span> <span class="pl-s"><span class="pl-pds">&quot;</span>4 44 22 444444<span class="pl-pds">&quot;</span></span>,</td>
      </tr>
      <tr>
        <td id="L427" class="blob-num js-line-number" data-line-number="427"></td>
        <td id="LC427" class="blob-code blob-code-inner js-file-line">           <span class="pl-s"><span class="pl-pds">&#39;</span>B<span class="pl-pds">&#39;</span></span>, <span class="pl-s"><span class="pl-pds">&#39;</span>M<span class="pl-pds">&#39;</span></span>, <span class="pl-c1">14</span>+<span class="pl-c1">40</span>+(x*<span class="pl-c1">3</span>+pad)*y, <span class="pl-c1">0</span>,<span class="pl-c1">0</span>, <span class="pl-c1">14</span>+<span class="pl-c1">40</span>,  <span class="pl-c"><span class="pl-c">//</span> file header</span></td>
      </tr>
      <tr>
        <td id="L428" class="blob-num js-line-number" data-line-number="428"></td>
        <td id="LC428" class="blob-code blob-code-inner js-file-line">            <span class="pl-c1">40</span>, x,y, <span class="pl-c1">1</span>,<span class="pl-c1">24</span>, <span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>);             <span class="pl-c"><span class="pl-c">//</span> bitmap header</span></td>
      </tr>
      <tr>
        <td id="L429" class="blob-num js-line-number" data-line-number="429"></td>
        <td id="LC429" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L430" class="blob-num js-line-number" data-line-number="430"></td>
        <td id="LC430" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L431" class="blob-num js-line-number" data-line-number="431"></td>
        <td id="LC431" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_bmp_to_func</span>(stbi_write_func *func, <span class="pl-k">void</span> *context, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span> *data)</td>
      </tr>
      <tr>
        <td id="L432" class="blob-num js-line-number" data-line-number="432"></td>
        <td id="LC432" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L433" class="blob-num js-line-number" data-line-number="433"></td>
        <td id="LC433" class="blob-code blob-code-inner js-file-line">   stbi__write_context s;</td>
      </tr>
      <tr>
        <td id="L434" class="blob-num js-line-number" data-line-number="434"></td>
        <td id="LC434" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbi__start_write_callbacks</span>(&amp;s, func, context);</td>
      </tr>
      <tr>
        <td id="L435" class="blob-num js-line-number" data-line-number="435"></td>
        <td id="LC435" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">stbi_write_bmp_core</span>(&amp;s, x, y, comp, data);</td>
      </tr>
      <tr>
        <td id="L436" class="blob-num js-line-number" data-line-number="436"></td>
        <td id="LC436" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L437" class="blob-num js-line-number" data-line-number="437"></td>
        <td id="LC437" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L438" class="blob-num js-line-number" data-line-number="438"></td>
        <td id="LC438" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBI_WRITE_NO_STDIO</td>
      </tr>
      <tr>
        <td id="L439" class="blob-num js-line-number" data-line-number="439"></td>
        <td id="LC439" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_bmp</span>(<span class="pl-k">char</span> <span class="pl-k">const</span> *filename, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span> *data)</td>
      </tr>
      <tr>
        <td id="L440" class="blob-num js-line-number" data-line-number="440"></td>
        <td id="LC440" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L441" class="blob-num js-line-number" data-line-number="441"></td>
        <td id="LC441" class="blob-code blob-code-inner js-file-line">   stbi__write_context s;</td>
      </tr>
      <tr>
        <td id="L442" class="blob-num js-line-number" data-line-number="442"></td>
        <td id="LC442" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (<span class="pl-c1">stbi__start_write_file</span>(&amp;s,filename)) {</td>
      </tr>
      <tr>
        <td id="L443" class="blob-num js-line-number" data-line-number="443"></td>
        <td id="LC443" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> r = <span class="pl-c1">stbi_write_bmp_core</span>(&amp;s, x, y, comp, data);</td>
      </tr>
      <tr>
        <td id="L444" class="blob-num js-line-number" data-line-number="444"></td>
        <td id="LC444" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbi__end_write_file</span>(&amp;s);</td>
      </tr>
      <tr>
        <td id="L445" class="blob-num js-line-number" data-line-number="445"></td>
        <td id="LC445" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> r;</td>
      </tr>
      <tr>
        <td id="L446" class="blob-num js-line-number" data-line-number="446"></td>
        <td id="LC446" class="blob-code blob-code-inner js-file-line">   } <span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L447" class="blob-num js-line-number" data-line-number="447"></td>
        <td id="LC447" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L448" class="blob-num js-line-number" data-line-number="448"></td>
        <td id="LC448" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L449" class="blob-num js-line-number" data-line-number="449"></td>
        <td id="LC449" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span> <span class="pl-c"><span class="pl-c">//</span>!STBI_WRITE_NO_STDIO</span></td>
      </tr>
      <tr>
        <td id="L450" class="blob-num js-line-number" data-line-number="450"></td>
        <td id="LC450" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L451" class="blob-num js-line-number" data-line-number="451"></td>
        <td id="LC451" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> <span class="pl-en">stbi_write_tga_core</span>(stbi__write_context *s, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">void</span> *data)</td>
      </tr>
      <tr>
        <td id="L452" class="blob-num js-line-number" data-line-number="452"></td>
        <td id="LC452" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L453" class="blob-num js-line-number" data-line-number="453"></td>
        <td id="LC453" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> has_alpha = (comp == <span class="pl-c1">2</span> || comp == <span class="pl-c1">4</span>);</td>
      </tr>
      <tr>
        <td id="L454" class="blob-num js-line-number" data-line-number="454"></td>
        <td id="LC454" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> colorbytes = has_alpha ? comp-<span class="pl-c1">1</span> : comp;</td>
      </tr>
      <tr>
        <td id="L455" class="blob-num js-line-number" data-line-number="455"></td>
        <td id="LC455" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> format = colorbytes &lt; <span class="pl-c1">2</span> ? <span class="pl-c1">3</span> : <span class="pl-c1">2</span>; <span class="pl-c"><span class="pl-c">//</span> 3 color channels (RGB/RGBA) = 2, 1 color channel (Y/YA) = 3</span></td>
      </tr>
      <tr>
        <td id="L456" class="blob-num js-line-number" data-line-number="456"></td>
        <td id="LC456" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L457" class="blob-num js-line-number" data-line-number="457"></td>
        <td id="LC457" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (y &lt; <span class="pl-c1">0</span> || x &lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L458" class="blob-num js-line-number" data-line-number="458"></td>
        <td id="LC458" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L459" class="blob-num js-line-number" data-line-number="459"></td>
        <td id="LC459" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L460" class="blob-num js-line-number" data-line-number="460"></td>
        <td id="LC460" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (!stbi_write_tga_with_rle) {</td>
      </tr>
      <tr>
        <td id="L461" class="blob-num js-line-number" data-line-number="461"></td>
        <td id="LC461" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">stbiw__outfile</span>(s, -<span class="pl-c1">1</span>, -<span class="pl-c1">1</span>, x, y, comp, <span class="pl-c1">0</span>, (<span class="pl-k">void</span> *) data, has_alpha, <span class="pl-c1">0</span>,</td>
      </tr>
      <tr>
        <td id="L462" class="blob-num js-line-number" data-line-number="462"></td>
        <td id="LC462" class="blob-code blob-code-inner js-file-line">         <span class="pl-s"><span class="pl-pds">&quot;</span>111 221 2222 11<span class="pl-pds">&quot;</span></span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, format, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span>, x, y, (colorbytes + has_alpha) * <span class="pl-c1">8</span>, has_alpha * <span class="pl-c1">8</span>);</td>
      </tr>
      <tr>
        <td id="L463" class="blob-num js-line-number" data-line-number="463"></td>
        <td id="LC463" class="blob-code blob-code-inner js-file-line">   } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L464" class="blob-num js-line-number" data-line-number="464"></td>
        <td id="LC464" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> i,j,k;</td>
      </tr>
      <tr>
        <td id="L465" class="blob-num js-line-number" data-line-number="465"></td>
        <td id="LC465" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> jend, jdir;</td>
      </tr>
      <tr>
        <td id="L466" class="blob-num js-line-number" data-line-number="466"></td>
        <td id="LC466" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L467" class="blob-num js-line-number" data-line-number="467"></td>
        <td id="LC467" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__writef</span>(s, <span class="pl-s"><span class="pl-pds">&quot;</span>111 221 2222 11<span class="pl-pds">&quot;</span></span>, <span class="pl-c1">0</span>,<span class="pl-c1">0</span>,format+<span class="pl-c1">8</span>, <span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>, <span class="pl-c1">0</span>,<span class="pl-c1">0</span>,x,y, (colorbytes + has_alpha) * <span class="pl-c1">8</span>, has_alpha * <span class="pl-c1">8</span>);</td>
      </tr>
      <tr>
        <td id="L468" class="blob-num js-line-number" data-line-number="468"></td>
        <td id="LC468" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L469" class="blob-num js-line-number" data-line-number="469"></td>
        <td id="LC469" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (stbi__flip_vertically_on_write) {</td>
      </tr>
      <tr>
        <td id="L470" class="blob-num js-line-number" data-line-number="470"></td>
        <td id="LC470" class="blob-code blob-code-inner js-file-line">         j = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L471" class="blob-num js-line-number" data-line-number="471"></td>
        <td id="LC471" class="blob-code blob-code-inner js-file-line">         jend = y;</td>
      </tr>
      <tr>
        <td id="L472" class="blob-num js-line-number" data-line-number="472"></td>
        <td id="LC472" class="blob-code blob-code-inner js-file-line">         jdir = <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L473" class="blob-num js-line-number" data-line-number="473"></td>
        <td id="LC473" class="blob-code blob-code-inner js-file-line">      } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L474" class="blob-num js-line-number" data-line-number="474"></td>
        <td id="LC474" class="blob-code blob-code-inner js-file-line">         j = y-<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L475" class="blob-num js-line-number" data-line-number="475"></td>
        <td id="LC475" class="blob-code blob-code-inner js-file-line">         jend = -<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L476" class="blob-num js-line-number" data-line-number="476"></td>
        <td id="LC476" class="blob-code blob-code-inner js-file-line">         jdir = -<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L477" class="blob-num js-line-number" data-line-number="477"></td>
        <td id="LC477" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L478" class="blob-num js-line-number" data-line-number="478"></td>
        <td id="LC478" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (; j != jend; j += jdir) {</td>
      </tr>
      <tr>
        <td id="L479" class="blob-num js-line-number" data-line-number="479"></td>
        <td id="LC479" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *row = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *) data + j * x * comp;</td>
      </tr>
      <tr>
        <td id="L480" class="blob-num js-line-number" data-line-number="480"></td>
        <td id="LC480" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">int</span> len;</td>
      </tr>
      <tr>
        <td id="L481" class="blob-num js-line-number" data-line-number="481"></td>
        <td id="LC481" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L482" class="blob-num js-line-number" data-line-number="482"></td>
        <td id="LC482" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">for</span> (i = <span class="pl-c1">0</span>; i &lt; x; i += len) {</td>
      </tr>
      <tr>
        <td id="L483" class="blob-num js-line-number" data-line-number="483"></td>
        <td id="LC483" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *begin = row + i * comp;</td>
      </tr>
      <tr>
        <td id="L484" class="blob-num js-line-number" data-line-number="484"></td>
        <td id="LC484" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">int</span> diff = <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L485" class="blob-num js-line-number" data-line-number="485"></td>
        <td id="LC485" class="blob-code blob-code-inner js-file-line">            len = <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L486" class="blob-num js-line-number" data-line-number="486"></td>
        <td id="LC486" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L487" class="blob-num js-line-number" data-line-number="487"></td>
        <td id="LC487" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">if</span> (i &lt; x - <span class="pl-c1">1</span>) {</td>
      </tr>
      <tr>
        <td id="L488" class="blob-num js-line-number" data-line-number="488"></td>
        <td id="LC488" class="blob-code blob-code-inner js-file-line">               ++len;</td>
      </tr>
      <tr>
        <td id="L489" class="blob-num js-line-number" data-line-number="489"></td>
        <td id="LC489" class="blob-code blob-code-inner js-file-line">               diff = <span class="pl-c1">memcmp</span>(begin, row + (i + <span class="pl-c1">1</span>) * comp, comp);</td>
      </tr>
      <tr>
        <td id="L490" class="blob-num js-line-number" data-line-number="490"></td>
        <td id="LC490" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">if</span> (diff) {</td>
      </tr>
      <tr>
        <td id="L491" class="blob-num js-line-number" data-line-number="491"></td>
        <td id="LC491" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *prev = begin;</td>
      </tr>
      <tr>
        <td id="L492" class="blob-num js-line-number" data-line-number="492"></td>
        <td id="LC492" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">for</span> (k = i + <span class="pl-c1">2</span>; k &lt; x &amp;&amp; len &lt; <span class="pl-c1">128</span>; ++k) {</td>
      </tr>
      <tr>
        <td id="L493" class="blob-num js-line-number" data-line-number="493"></td>
        <td id="LC493" class="blob-code blob-code-inner js-file-line">                     <span class="pl-k">if</span> (<span class="pl-c1">memcmp</span>(prev, row + k * comp, comp)) {</td>
      </tr>
      <tr>
        <td id="L494" class="blob-num js-line-number" data-line-number="494"></td>
        <td id="LC494" class="blob-code blob-code-inner js-file-line">                        prev += comp;</td>
      </tr>
      <tr>
        <td id="L495" class="blob-num js-line-number" data-line-number="495"></td>
        <td id="LC495" class="blob-code blob-code-inner js-file-line">                        ++len;</td>
      </tr>
      <tr>
        <td id="L496" class="blob-num js-line-number" data-line-number="496"></td>
        <td id="LC496" class="blob-code blob-code-inner js-file-line">                     } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L497" class="blob-num js-line-number" data-line-number="497"></td>
        <td id="LC497" class="blob-code blob-code-inner js-file-line">                        --len;</td>
      </tr>
      <tr>
        <td id="L498" class="blob-num js-line-number" data-line-number="498"></td>
        <td id="LC498" class="blob-code blob-code-inner js-file-line">                        <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L499" class="blob-num js-line-number" data-line-number="499"></td>
        <td id="LC499" class="blob-code blob-code-inner js-file-line">                     }</td>
      </tr>
      <tr>
        <td id="L500" class="blob-num js-line-number" data-line-number="500"></td>
        <td id="LC500" class="blob-code blob-code-inner js-file-line">                  }</td>
      </tr>
      <tr>
        <td id="L501" class="blob-num js-line-number" data-line-number="501"></td>
        <td id="LC501" class="blob-code blob-code-inner js-file-line">               } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L502" class="blob-num js-line-number" data-line-number="502"></td>
        <td id="LC502" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">for</span> (k = i + <span class="pl-c1">2</span>; k &lt; x &amp;&amp; len &lt; <span class="pl-c1">128</span>; ++k) {</td>
      </tr>
      <tr>
        <td id="L503" class="blob-num js-line-number" data-line-number="503"></td>
        <td id="LC503" class="blob-code blob-code-inner js-file-line">                     <span class="pl-k">if</span> (!<span class="pl-c1">memcmp</span>(begin, row + k * comp, comp)) {</td>
      </tr>
      <tr>
        <td id="L504" class="blob-num js-line-number" data-line-number="504"></td>
        <td id="LC504" class="blob-code blob-code-inner js-file-line">                        ++len;</td>
      </tr>
      <tr>
        <td id="L505" class="blob-num js-line-number" data-line-number="505"></td>
        <td id="LC505" class="blob-code blob-code-inner js-file-line">                     } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L506" class="blob-num js-line-number" data-line-number="506"></td>
        <td id="LC506" class="blob-code blob-code-inner js-file-line">                        <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L507" class="blob-num js-line-number" data-line-number="507"></td>
        <td id="LC507" class="blob-code blob-code-inner js-file-line">                     }</td>
      </tr>
      <tr>
        <td id="L508" class="blob-num js-line-number" data-line-number="508"></td>
        <td id="LC508" class="blob-code blob-code-inner js-file-line">                  }</td>
      </tr>
      <tr>
        <td id="L509" class="blob-num js-line-number" data-line-number="509"></td>
        <td id="LC509" class="blob-code blob-code-inner js-file-line">               }</td>
      </tr>
      <tr>
        <td id="L510" class="blob-num js-line-number" data-line-number="510"></td>
        <td id="LC510" class="blob-code blob-code-inner js-file-line">            }</td>
      </tr>
      <tr>
        <td id="L511" class="blob-num js-line-number" data-line-number="511"></td>
        <td id="LC511" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L512" class="blob-num js-line-number" data-line-number="512"></td>
        <td id="LC512" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">if</span> (diff) {</td>
      </tr>
      <tr>
        <td id="L513" class="blob-num js-line-number" data-line-number="513"></td>
        <td id="LC513" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">unsigned</span> <span class="pl-k">char</span> header = <span class="pl-c1">STBIW_UCHAR</span>(len - <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L514" class="blob-num js-line-number" data-line-number="514"></td>
        <td id="LC514" class="blob-code blob-code-inner js-file-line">               s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, &amp;header, <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L515" class="blob-num js-line-number" data-line-number="515"></td>
        <td id="LC515" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">for</span> (k = <span class="pl-c1">0</span>; k &lt; len; ++k) {</td>
      </tr>
      <tr>
        <td id="L516" class="blob-num js-line-number" data-line-number="516"></td>
        <td id="LC516" class="blob-code blob-code-inner js-file-line">                  <span class="pl-c1">stbiw__write_pixel</span>(s, -<span class="pl-c1">1</span>, comp, has_alpha, <span class="pl-c1">0</span>, begin + k * comp);</td>
      </tr>
      <tr>
        <td id="L517" class="blob-num js-line-number" data-line-number="517"></td>
        <td id="LC517" class="blob-code blob-code-inner js-file-line">               }</td>
      </tr>
      <tr>
        <td id="L518" class="blob-num js-line-number" data-line-number="518"></td>
        <td id="LC518" class="blob-code blob-code-inner js-file-line">            } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L519" class="blob-num js-line-number" data-line-number="519"></td>
        <td id="LC519" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">unsigned</span> <span class="pl-k">char</span> header = <span class="pl-c1">STBIW_UCHAR</span>(len - <span class="pl-c1">129</span>);</td>
      </tr>
      <tr>
        <td id="L520" class="blob-num js-line-number" data-line-number="520"></td>
        <td id="LC520" class="blob-code blob-code-inner js-file-line">               s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, &amp;header, <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L521" class="blob-num js-line-number" data-line-number="521"></td>
        <td id="LC521" class="blob-code blob-code-inner js-file-line">               <span class="pl-c1">stbiw__write_pixel</span>(s, -<span class="pl-c1">1</span>, comp, has_alpha, <span class="pl-c1">0</span>, begin);</td>
      </tr>
      <tr>
        <td id="L522" class="blob-num js-line-number" data-line-number="522"></td>
        <td id="LC522" class="blob-code blob-code-inner js-file-line">            }</td>
      </tr>
      <tr>
        <td id="L523" class="blob-num js-line-number" data-line-number="523"></td>
        <td id="LC523" class="blob-code blob-code-inner js-file-line">         }</td>
      </tr>
      <tr>
        <td id="L524" class="blob-num js-line-number" data-line-number="524"></td>
        <td id="LC524" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L525" class="blob-num js-line-number" data-line-number="525"></td>
        <td id="LC525" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L526" class="blob-num js-line-number" data-line-number="526"></td>
        <td id="LC526" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L527" class="blob-num js-line-number" data-line-number="527"></td>
        <td id="LC527" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L528" class="blob-num js-line-number" data-line-number="528"></td>
        <td id="LC528" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L529" class="blob-num js-line-number" data-line-number="529"></td>
        <td id="LC529" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_tga_to_func</span>(stbi_write_func *func, <span class="pl-k">void</span> *context, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span> *data)</td>
      </tr>
      <tr>
        <td id="L530" class="blob-num js-line-number" data-line-number="530"></td>
        <td id="LC530" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L531" class="blob-num js-line-number" data-line-number="531"></td>
        <td id="LC531" class="blob-code blob-code-inner js-file-line">   stbi__write_context s;</td>
      </tr>
      <tr>
        <td id="L532" class="blob-num js-line-number" data-line-number="532"></td>
        <td id="LC532" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbi__start_write_callbacks</span>(&amp;s, func, context);</td>
      </tr>
      <tr>
        <td id="L533" class="blob-num js-line-number" data-line-number="533"></td>
        <td id="LC533" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">stbi_write_tga_core</span>(&amp;s, x, y, comp, (<span class="pl-k">void</span> *) data);</td>
      </tr>
      <tr>
        <td id="L534" class="blob-num js-line-number" data-line-number="534"></td>
        <td id="LC534" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L535" class="blob-num js-line-number" data-line-number="535"></td>
        <td id="LC535" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L536" class="blob-num js-line-number" data-line-number="536"></td>
        <td id="LC536" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBI_WRITE_NO_STDIO</td>
      </tr>
      <tr>
        <td id="L537" class="blob-num js-line-number" data-line-number="537"></td>
        <td id="LC537" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_tga</span>(<span class="pl-k">char</span> <span class="pl-k">const</span> *filename, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span> *data)</td>
      </tr>
      <tr>
        <td id="L538" class="blob-num js-line-number" data-line-number="538"></td>
        <td id="LC538" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L539" class="blob-num js-line-number" data-line-number="539"></td>
        <td id="LC539" class="blob-code blob-code-inner js-file-line">   stbi__write_context s;</td>
      </tr>
      <tr>
        <td id="L540" class="blob-num js-line-number" data-line-number="540"></td>
        <td id="LC540" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (<span class="pl-c1">stbi__start_write_file</span>(&amp;s,filename)) {</td>
      </tr>
      <tr>
        <td id="L541" class="blob-num js-line-number" data-line-number="541"></td>
        <td id="LC541" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> r = <span class="pl-c1">stbi_write_tga_core</span>(&amp;s, x, y, comp, (<span class="pl-k">void</span> *) data);</td>
      </tr>
      <tr>
        <td id="L542" class="blob-num js-line-number" data-line-number="542"></td>
        <td id="LC542" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbi__end_write_file</span>(&amp;s);</td>
      </tr>
      <tr>
        <td id="L543" class="blob-num js-line-number" data-line-number="543"></td>
        <td id="LC543" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> r;</td>
      </tr>
      <tr>
        <td id="L544" class="blob-num js-line-number" data-line-number="544"></td>
        <td id="LC544" class="blob-code blob-code-inner js-file-line">   } <span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L545" class="blob-num js-line-number" data-line-number="545"></td>
        <td id="LC545" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L546" class="blob-num js-line-number" data-line-number="546"></td>
        <td id="LC546" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L547" class="blob-num js-line-number" data-line-number="547"></td>
        <td id="LC547" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L548" class="blob-num js-line-number" data-line-number="548"></td>
        <td id="LC548" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L549" class="blob-num js-line-number" data-line-number="549"></td>
        <td id="LC549" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> *************************************************************************************************</span></td>
      </tr>
      <tr>
        <td id="L550" class="blob-num js-line-number" data-line-number="550"></td>
        <td id="LC550" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> Radiance RGBE HDR writer</span></td>
      </tr>
      <tr>
        <td id="L551" class="blob-num js-line-number" data-line-number="551"></td>
        <td id="LC551" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> by Baldur Karlsson</span></td>
      </tr>
      <tr>
        <td id="L552" class="blob-num js-line-number" data-line-number="552"></td>
        <td id="LC552" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L553" class="blob-num js-line-number" data-line-number="553"></td>
        <td id="LC553" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__max</span>(<span class="pl-v">a, b</span>)  ((a) &gt; (b) ? (a) : (b))</td>
      </tr>
      <tr>
        <td id="L554" class="blob-num js-line-number" data-line-number="554"></td>
        <td id="LC554" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L555" class="blob-num js-line-number" data-line-number="555"></td>
        <td id="LC555" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">stbiw__linear_to_rgbe</span>(<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *rgbe, <span class="pl-k">float</span> *linear)</td>
      </tr>
      <tr>
        <td id="L556" class="blob-num js-line-number" data-line-number="556"></td>
        <td id="LC556" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L557" class="blob-num js-line-number" data-line-number="557"></td>
        <td id="LC557" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> exponent;</td>
      </tr>
      <tr>
        <td id="L558" class="blob-num js-line-number" data-line-number="558"></td>
        <td id="LC558" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> maxcomp = <span class="pl-c1">stbiw__max</span>(linear[<span class="pl-c1">0</span>], <span class="pl-c1">stbiw__max</span>(linear[<span class="pl-c1">1</span>], linear[<span class="pl-c1">2</span>]));</td>
      </tr>
      <tr>
        <td id="L559" class="blob-num js-line-number" data-line-number="559"></td>
        <td id="LC559" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L560" class="blob-num js-line-number" data-line-number="560"></td>
        <td id="LC560" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (maxcomp &lt; 1e-<span class="pl-c1">32f</span>) {</td>
      </tr>
      <tr>
        <td id="L561" class="blob-num js-line-number" data-line-number="561"></td>
        <td id="LC561" class="blob-code blob-code-inner js-file-line">      rgbe[<span class="pl-c1">0</span>] = rgbe[<span class="pl-c1">1</span>] = rgbe[<span class="pl-c1">2</span>] = rgbe[<span class="pl-c1">3</span>] = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L562" class="blob-num js-line-number" data-line-number="562"></td>
        <td id="LC562" class="blob-code blob-code-inner js-file-line">   } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L563" class="blob-num js-line-number" data-line-number="563"></td>
        <td id="LC563" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">float</span> normalize = (<span class="pl-k">float</span>) <span class="pl-c1">frexp</span>(maxcomp, &amp;exponent) * <span class="pl-c1">256</span>.<span class="pl-c1">0f</span>/maxcomp;</td>
      </tr>
      <tr>
        <td id="L564" class="blob-num js-line-number" data-line-number="564"></td>
        <td id="LC564" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L565" class="blob-num js-line-number" data-line-number="565"></td>
        <td id="LC565" class="blob-code blob-code-inner js-file-line">      rgbe[<span class="pl-c1">0</span>] = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span>)(linear[<span class="pl-c1">0</span>] * normalize);</td>
      </tr>
      <tr>
        <td id="L566" class="blob-num js-line-number" data-line-number="566"></td>
        <td id="LC566" class="blob-code blob-code-inner js-file-line">      rgbe[<span class="pl-c1">1</span>] = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span>)(linear[<span class="pl-c1">1</span>] * normalize);</td>
      </tr>
      <tr>
        <td id="L567" class="blob-num js-line-number" data-line-number="567"></td>
        <td id="LC567" class="blob-code blob-code-inner js-file-line">      rgbe[<span class="pl-c1">2</span>] = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span>)(linear[<span class="pl-c1">2</span>] * normalize);</td>
      </tr>
      <tr>
        <td id="L568" class="blob-num js-line-number" data-line-number="568"></td>
        <td id="LC568" class="blob-code blob-code-inner js-file-line">      rgbe[<span class="pl-c1">3</span>] = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span>)(exponent + <span class="pl-c1">128</span>);</td>
      </tr>
      <tr>
        <td id="L569" class="blob-num js-line-number" data-line-number="569"></td>
        <td id="LC569" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L570" class="blob-num js-line-number" data-line-number="570"></td>
        <td id="LC570" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L571" class="blob-num js-line-number" data-line-number="571"></td>
        <td id="LC571" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L572" class="blob-num js-line-number" data-line-number="572"></td>
        <td id="LC572" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">stbiw__write_run_data</span>(stbi__write_context *s, <span class="pl-k">int</span> length, <span class="pl-k">unsigned</span> <span class="pl-k">char</span> databyte)</td>
      </tr>
      <tr>
        <td id="L573" class="blob-num js-line-number" data-line-number="573"></td>
        <td id="LC573" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L574" class="blob-num js-line-number" data-line-number="574"></td>
        <td id="LC574" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> lengthbyte = <span class="pl-c1">STBIW_UCHAR</span>(length+<span class="pl-c1">128</span>);</td>
      </tr>
      <tr>
        <td id="L575" class="blob-num js-line-number" data-line-number="575"></td>
        <td id="LC575" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_ASSERT</span>(length+<span class="pl-c1">128</span> &lt;= <span class="pl-c1">255</span>);</td>
      </tr>
      <tr>
        <td id="L576" class="blob-num js-line-number" data-line-number="576"></td>
        <td id="LC576" class="blob-code blob-code-inner js-file-line">   s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, &amp;lengthbyte, <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L577" class="blob-num js-line-number" data-line-number="577"></td>
        <td id="LC577" class="blob-code blob-code-inner js-file-line">   s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, &amp;databyte, <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L578" class="blob-num js-line-number" data-line-number="578"></td>
        <td id="LC578" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L579" class="blob-num js-line-number" data-line-number="579"></td>
        <td id="LC579" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L580" class="blob-num js-line-number" data-line-number="580"></td>
        <td id="LC580" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">stbiw__write_dump_data</span>(stbi__write_context *s, <span class="pl-k">int</span> length, <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *data)</td>
      </tr>
      <tr>
        <td id="L581" class="blob-num js-line-number" data-line-number="581"></td>
        <td id="LC581" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L582" class="blob-num js-line-number" data-line-number="582"></td>
        <td id="LC582" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> lengthbyte = <span class="pl-c1">STBIW_UCHAR</span>(length);</td>
      </tr>
      <tr>
        <td id="L583" class="blob-num js-line-number" data-line-number="583"></td>
        <td id="LC583" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_ASSERT</span>(length &lt;= <span class="pl-c1">128</span>); <span class="pl-c"><span class="pl-c">//</span> inconsistent with spec but consistent with official code</span></td>
      </tr>
      <tr>
        <td id="L584" class="blob-num js-line-number" data-line-number="584"></td>
        <td id="LC584" class="blob-code blob-code-inner js-file-line">   s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, &amp;lengthbyte, <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L585" class="blob-num js-line-number" data-line-number="585"></td>
        <td id="LC585" class="blob-code blob-code-inner js-file-line">   s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, data, length);</td>
      </tr>
      <tr>
        <td id="L586" class="blob-num js-line-number" data-line-number="586"></td>
        <td id="LC586" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L587" class="blob-num js-line-number" data-line-number="587"></td>
        <td id="LC587" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L588" class="blob-num js-line-number" data-line-number="588"></td>
        <td id="LC588" class="blob-code blob-code-inner js-file-line"><span class="pl-k">void</span> <span class="pl-en">stbiw__write_hdr_scanline</span>(stbi__write_context *s, <span class="pl-k">int</span> width, <span class="pl-k">int</span> ncomp, <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *scratch, <span class="pl-k">float</span> *scanline)</td>
      </tr>
      <tr>
        <td id="L589" class="blob-num js-line-number" data-line-number="589"></td>
        <td id="LC589" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L590" class="blob-num js-line-number" data-line-number="590"></td>
        <td id="LC590" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> scanlineheader[<span class="pl-c1">4</span>] = { <span class="pl-c1">2</span>, <span class="pl-c1">2</span>, <span class="pl-c1">0</span>, <span class="pl-c1">0</span> };</td>
      </tr>
      <tr>
        <td id="L591" class="blob-num js-line-number" data-line-number="591"></td>
        <td id="LC591" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> rgbe[<span class="pl-c1">4</span>];</td>
      </tr>
      <tr>
        <td id="L592" class="blob-num js-line-number" data-line-number="592"></td>
        <td id="LC592" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> linear[<span class="pl-c1">3</span>];</td>
      </tr>
      <tr>
        <td id="L593" class="blob-num js-line-number" data-line-number="593"></td>
        <td id="LC593" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> x;</td>
      </tr>
      <tr>
        <td id="L594" class="blob-num js-line-number" data-line-number="594"></td>
        <td id="LC594" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L595" class="blob-num js-line-number" data-line-number="595"></td>
        <td id="LC595" class="blob-code blob-code-inner js-file-line">   scanlineheader[<span class="pl-c1">2</span>] = (width&amp;<span class="pl-c1">0xff00</span>)&gt;&gt;<span class="pl-c1">8</span>;</td>
      </tr>
      <tr>
        <td id="L596" class="blob-num js-line-number" data-line-number="596"></td>
        <td id="LC596" class="blob-code blob-code-inner js-file-line">   scanlineheader[<span class="pl-c1">3</span>] = (width&amp;<span class="pl-c1">0x00ff</span>);</td>
      </tr>
      <tr>
        <td id="L597" class="blob-num js-line-number" data-line-number="597"></td>
        <td id="LC597" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L598" class="blob-num js-line-number" data-line-number="598"></td>
        <td id="LC598" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">/*</span> skip RLE for images too small or large <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L599" class="blob-num js-line-number" data-line-number="599"></td>
        <td id="LC599" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (width &lt; <span class="pl-c1">8</span> || width &gt;= <span class="pl-c1">32768</span>) {</td>
      </tr>
      <tr>
        <td id="L600" class="blob-num js-line-number" data-line-number="600"></td>
        <td id="LC600" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (x=<span class="pl-c1">0</span>; x &lt; width; x++) {</td>
      </tr>
      <tr>
        <td id="L601" class="blob-num js-line-number" data-line-number="601"></td>
        <td id="LC601" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">switch</span> (ncomp) {</td>
      </tr>
      <tr>
        <td id="L602" class="blob-num js-line-number" data-line-number="602"></td>
        <td id="LC602" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">case</span> <span class="pl-c1">4</span>: <span class="pl-c"><span class="pl-c">/*</span> fallthrough <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L603" class="blob-num js-line-number" data-line-number="603"></td>
        <td id="LC603" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">case</span> <span class="pl-c1">3</span>: linear[<span class="pl-c1">2</span>] = scanline[x*ncomp + <span class="pl-c1">2</span>];</td>
      </tr>
      <tr>
        <td id="L604" class="blob-num js-line-number" data-line-number="604"></td>
        <td id="LC604" class="blob-code blob-code-inner js-file-line">                    linear[<span class="pl-c1">1</span>] = scanline[x*ncomp + <span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L605" class="blob-num js-line-number" data-line-number="605"></td>
        <td id="LC605" class="blob-code blob-code-inner js-file-line">                    linear[<span class="pl-c1">0</span>] = scanline[x*ncomp + <span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L606" class="blob-num js-line-number" data-line-number="606"></td>
        <td id="LC606" class="blob-code blob-code-inner js-file-line">                    <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L607" class="blob-num js-line-number" data-line-number="607"></td>
        <td id="LC607" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">default</span>:</td>
      </tr>
      <tr>
        <td id="L608" class="blob-num js-line-number" data-line-number="608"></td>
        <td id="LC608" class="blob-code blob-code-inner js-file-line">                    linear[<span class="pl-c1">0</span>] = linear[<span class="pl-c1">1</span>] = linear[<span class="pl-c1">2</span>] = scanline[x*ncomp + <span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L609" class="blob-num js-line-number" data-line-number="609"></td>
        <td id="LC609" class="blob-code blob-code-inner js-file-line">                    <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L610" class="blob-num js-line-number" data-line-number="610"></td>
        <td id="LC610" class="blob-code blob-code-inner js-file-line">         }</td>
      </tr>
      <tr>
        <td id="L611" class="blob-num js-line-number" data-line-number="611"></td>
        <td id="LC611" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__linear_to_rgbe</span>(rgbe, linear);</td>
      </tr>
      <tr>
        <td id="L612" class="blob-num js-line-number" data-line-number="612"></td>
        <td id="LC612" class="blob-code blob-code-inner js-file-line">         s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, rgbe, <span class="pl-c1">4</span>);</td>
      </tr>
      <tr>
        <td id="L613" class="blob-num js-line-number" data-line-number="613"></td>
        <td id="LC613" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L614" class="blob-num js-line-number" data-line-number="614"></td>
        <td id="LC614" class="blob-code blob-code-inner js-file-line">   } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L615" class="blob-num js-line-number" data-line-number="615"></td>
        <td id="LC615" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> c,r;</td>
      </tr>
      <tr>
        <td id="L616" class="blob-num js-line-number" data-line-number="616"></td>
        <td id="LC616" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">/*</span> encode into scratch buffer <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L617" class="blob-num js-line-number" data-line-number="617"></td>
        <td id="LC617" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (x=<span class="pl-c1">0</span>; x &lt; width; x++) {</td>
      </tr>
      <tr>
        <td id="L618" class="blob-num js-line-number" data-line-number="618"></td>
        <td id="LC618" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">switch</span>(ncomp) {</td>
      </tr>
      <tr>
        <td id="L619" class="blob-num js-line-number" data-line-number="619"></td>
        <td id="LC619" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">case</span> <span class="pl-c1">4</span>: <span class="pl-c"><span class="pl-c">/*</span> fallthrough <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L620" class="blob-num js-line-number" data-line-number="620"></td>
        <td id="LC620" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">case</span> <span class="pl-c1">3</span>: linear[<span class="pl-c1">2</span>] = scanline[x*ncomp + <span class="pl-c1">2</span>];</td>
      </tr>
      <tr>
        <td id="L621" class="blob-num js-line-number" data-line-number="621"></td>
        <td id="LC621" class="blob-code blob-code-inner js-file-line">                    linear[<span class="pl-c1">1</span>] = scanline[x*ncomp + <span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L622" class="blob-num js-line-number" data-line-number="622"></td>
        <td id="LC622" class="blob-code blob-code-inner js-file-line">                    linear[<span class="pl-c1">0</span>] = scanline[x*ncomp + <span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L623" class="blob-num js-line-number" data-line-number="623"></td>
        <td id="LC623" class="blob-code blob-code-inner js-file-line">                    <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L624" class="blob-num js-line-number" data-line-number="624"></td>
        <td id="LC624" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">default</span>:</td>
      </tr>
      <tr>
        <td id="L625" class="blob-num js-line-number" data-line-number="625"></td>
        <td id="LC625" class="blob-code blob-code-inner js-file-line">                    linear[<span class="pl-c1">0</span>] = linear[<span class="pl-c1">1</span>] = linear[<span class="pl-c1">2</span>] = scanline[x*ncomp + <span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L626" class="blob-num js-line-number" data-line-number="626"></td>
        <td id="LC626" class="blob-code blob-code-inner js-file-line">                    <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L627" class="blob-num js-line-number" data-line-number="627"></td>
        <td id="LC627" class="blob-code blob-code-inner js-file-line">         }</td>
      </tr>
      <tr>
        <td id="L628" class="blob-num js-line-number" data-line-number="628"></td>
        <td id="LC628" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__linear_to_rgbe</span>(rgbe, linear);</td>
      </tr>
      <tr>
        <td id="L629" class="blob-num js-line-number" data-line-number="629"></td>
        <td id="LC629" class="blob-code blob-code-inner js-file-line">         scratch[x + width*<span class="pl-c1">0</span>] = rgbe[<span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L630" class="blob-num js-line-number" data-line-number="630"></td>
        <td id="LC630" class="blob-code blob-code-inner js-file-line">         scratch[x + width*<span class="pl-c1">1</span>] = rgbe[<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L631" class="blob-num js-line-number" data-line-number="631"></td>
        <td id="LC631" class="blob-code blob-code-inner js-file-line">         scratch[x + width*<span class="pl-c1">2</span>] = rgbe[<span class="pl-c1">2</span>];</td>
      </tr>
      <tr>
        <td id="L632" class="blob-num js-line-number" data-line-number="632"></td>
        <td id="LC632" class="blob-code blob-code-inner js-file-line">         scratch[x + width*<span class="pl-c1">3</span>] = rgbe[<span class="pl-c1">3</span>];</td>
      </tr>
      <tr>
        <td id="L633" class="blob-num js-line-number" data-line-number="633"></td>
        <td id="LC633" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L634" class="blob-num js-line-number" data-line-number="634"></td>
        <td id="LC634" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L635" class="blob-num js-line-number" data-line-number="635"></td>
        <td id="LC635" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, scanlineheader, <span class="pl-c1">4</span>);</td>
      </tr>
      <tr>
        <td id="L636" class="blob-num js-line-number" data-line-number="636"></td>
        <td id="LC636" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L637" class="blob-num js-line-number" data-line-number="637"></td>
        <td id="LC637" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">/*</span> RLE each component separately <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L638" class="blob-num js-line-number" data-line-number="638"></td>
        <td id="LC638" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (c=<span class="pl-c1">0</span>; c &lt; <span class="pl-c1">4</span>; c++) {</td>
      </tr>
      <tr>
        <td id="L639" class="blob-num js-line-number" data-line-number="639"></td>
        <td id="LC639" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *comp = &amp;scratch[width*c];</td>
      </tr>
      <tr>
        <td id="L640" class="blob-num js-line-number" data-line-number="640"></td>
        <td id="LC640" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L641" class="blob-num js-line-number" data-line-number="641"></td>
        <td id="LC641" class="blob-code blob-code-inner js-file-line">         x = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L642" class="blob-num js-line-number" data-line-number="642"></td>
        <td id="LC642" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">while</span> (x &lt; width) {</td>
      </tr>
      <tr>
        <td id="L643" class="blob-num js-line-number" data-line-number="643"></td>
        <td id="LC643" class="blob-code blob-code-inner js-file-line">            <span class="pl-c"><span class="pl-c">//</span> find first run</span></td>
      </tr>
      <tr>
        <td id="L644" class="blob-num js-line-number" data-line-number="644"></td>
        <td id="LC644" class="blob-code blob-code-inner js-file-line">            r = x;</td>
      </tr>
      <tr>
        <td id="L645" class="blob-num js-line-number" data-line-number="645"></td>
        <td id="LC645" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">while</span> (r+<span class="pl-c1">2</span> &lt; width) {</td>
      </tr>
      <tr>
        <td id="L646" class="blob-num js-line-number" data-line-number="646"></td>
        <td id="LC646" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">if</span> (comp[r] == comp[r+<span class="pl-c1">1</span>] &amp;&amp; comp[r] == comp[r+<span class="pl-c1">2</span>])</td>
      </tr>
      <tr>
        <td id="L647" class="blob-num js-line-number" data-line-number="647"></td>
        <td id="LC647" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L648" class="blob-num js-line-number" data-line-number="648"></td>
        <td id="LC648" class="blob-code blob-code-inner js-file-line">               ++r;</td>
      </tr>
      <tr>
        <td id="L649" class="blob-num js-line-number" data-line-number="649"></td>
        <td id="LC649" class="blob-code blob-code-inner js-file-line">            }</td>
      </tr>
      <tr>
        <td id="L650" class="blob-num js-line-number" data-line-number="650"></td>
        <td id="LC650" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">if</span> (r+<span class="pl-c1">2</span> &gt;= width)</td>
      </tr>
      <tr>
        <td id="L651" class="blob-num js-line-number" data-line-number="651"></td>
        <td id="LC651" class="blob-code blob-code-inner js-file-line">               r = width;</td>
      </tr>
      <tr>
        <td id="L652" class="blob-num js-line-number" data-line-number="652"></td>
        <td id="LC652" class="blob-code blob-code-inner js-file-line">            <span class="pl-c"><span class="pl-c">//</span> dump up to first run</span></td>
      </tr>
      <tr>
        <td id="L653" class="blob-num js-line-number" data-line-number="653"></td>
        <td id="LC653" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">while</span> (x &lt; r) {</td>
      </tr>
      <tr>
        <td id="L654" class="blob-num js-line-number" data-line-number="654"></td>
        <td id="LC654" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">int</span> len = r-x;</td>
      </tr>
      <tr>
        <td id="L655" class="blob-num js-line-number" data-line-number="655"></td>
        <td id="LC655" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">if</span> (len &gt; <span class="pl-c1">128</span>) len = <span class="pl-c1">128</span>;</td>
      </tr>
      <tr>
        <td id="L656" class="blob-num js-line-number" data-line-number="656"></td>
        <td id="LC656" class="blob-code blob-code-inner js-file-line">               <span class="pl-c1">stbiw__write_dump_data</span>(s, len, &amp;comp[x]);</td>
      </tr>
      <tr>
        <td id="L657" class="blob-num js-line-number" data-line-number="657"></td>
        <td id="LC657" class="blob-code blob-code-inner js-file-line">               x += len;</td>
      </tr>
      <tr>
        <td id="L658" class="blob-num js-line-number" data-line-number="658"></td>
        <td id="LC658" class="blob-code blob-code-inner js-file-line">            }</td>
      </tr>
      <tr>
        <td id="L659" class="blob-num js-line-number" data-line-number="659"></td>
        <td id="LC659" class="blob-code blob-code-inner js-file-line">            <span class="pl-c"><span class="pl-c">//</span> if there&#39;s a run, output it</span></td>
      </tr>
      <tr>
        <td id="L660" class="blob-num js-line-number" data-line-number="660"></td>
        <td id="LC660" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">if</span> (r+<span class="pl-c1">2</span> &lt; width) { <span class="pl-c"><span class="pl-c">//</span> same test as what we break out of in search loop, so only true if we break&#39;d</span></td>
      </tr>
      <tr>
        <td id="L661" class="blob-num js-line-number" data-line-number="661"></td>
        <td id="LC661" class="blob-code blob-code-inner js-file-line">               <span class="pl-c"><span class="pl-c">//</span> find next byte after run</span></td>
      </tr>
      <tr>
        <td id="L662" class="blob-num js-line-number" data-line-number="662"></td>
        <td id="LC662" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">while</span> (r &lt; width &amp;&amp; comp[r] == comp[x])</td>
      </tr>
      <tr>
        <td id="L663" class="blob-num js-line-number" data-line-number="663"></td>
        <td id="LC663" class="blob-code blob-code-inner js-file-line">                  ++r;</td>
      </tr>
      <tr>
        <td id="L664" class="blob-num js-line-number" data-line-number="664"></td>
        <td id="LC664" class="blob-code blob-code-inner js-file-line">               <span class="pl-c"><span class="pl-c">//</span> output run up to r</span></td>
      </tr>
      <tr>
        <td id="L665" class="blob-num js-line-number" data-line-number="665"></td>
        <td id="LC665" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">while</span> (x &lt; r) {</td>
      </tr>
      <tr>
        <td id="L666" class="blob-num js-line-number" data-line-number="666"></td>
        <td id="LC666" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">int</span> len = r-x;</td>
      </tr>
      <tr>
        <td id="L667" class="blob-num js-line-number" data-line-number="667"></td>
        <td id="LC667" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">if</span> (len &gt; <span class="pl-c1">127</span>) len = <span class="pl-c1">127</span>;</td>
      </tr>
      <tr>
        <td id="L668" class="blob-num js-line-number" data-line-number="668"></td>
        <td id="LC668" class="blob-code blob-code-inner js-file-line">                  <span class="pl-c1">stbiw__write_run_data</span>(s, len, comp[x]);</td>
      </tr>
      <tr>
        <td id="L669" class="blob-num js-line-number" data-line-number="669"></td>
        <td id="LC669" class="blob-code blob-code-inner js-file-line">                  x += len;</td>
      </tr>
      <tr>
        <td id="L670" class="blob-num js-line-number" data-line-number="670"></td>
        <td id="LC670" class="blob-code blob-code-inner js-file-line">               }</td>
      </tr>
      <tr>
        <td id="L671" class="blob-num js-line-number" data-line-number="671"></td>
        <td id="LC671" class="blob-code blob-code-inner js-file-line">            }</td>
      </tr>
      <tr>
        <td id="L672" class="blob-num js-line-number" data-line-number="672"></td>
        <td id="LC672" class="blob-code blob-code-inner js-file-line">         }</td>
      </tr>
      <tr>
        <td id="L673" class="blob-num js-line-number" data-line-number="673"></td>
        <td id="LC673" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L674" class="blob-num js-line-number" data-line-number="674"></td>
        <td id="LC674" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L675" class="blob-num js-line-number" data-line-number="675"></td>
        <td id="LC675" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L676" class="blob-num js-line-number" data-line-number="676"></td>
        <td id="LC676" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L677" class="blob-num js-line-number" data-line-number="677"></td>
        <td id="LC677" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> <span class="pl-en">stbi_write_hdr_core</span>(stbi__write_context *s, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">float</span> *data)</td>
      </tr>
      <tr>
        <td id="L678" class="blob-num js-line-number" data-line-number="678"></td>
        <td id="LC678" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L679" class="blob-num js-line-number" data-line-number="679"></td>
        <td id="LC679" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (y &lt;= <span class="pl-c1">0</span> || x &lt;= <span class="pl-c1">0</span> || data == <span class="pl-c1">NULL</span>)</td>
      </tr>
      <tr>
        <td id="L680" class="blob-num js-line-number" data-line-number="680"></td>
        <td id="LC680" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L681" class="blob-num js-line-number" data-line-number="681"></td>
        <td id="LC681" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L682" class="blob-num js-line-number" data-line-number="682"></td>
        <td id="LC682" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> Each component is stored separately. Allocate scratch space for full output scanline.</span></td>
      </tr>
      <tr>
        <td id="L683" class="blob-num js-line-number" data-line-number="683"></td>
        <td id="LC683" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *scratch = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *) <span class="pl-c1">STBIW_MALLOC</span>(x*<span class="pl-c1">4</span>);</td>
      </tr>
      <tr>
        <td id="L684" class="blob-num js-line-number" data-line-number="684"></td>
        <td id="LC684" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> i, len;</td>
      </tr>
      <tr>
        <td id="L685" class="blob-num js-line-number" data-line-number="685"></td>
        <td id="LC685" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">char</span> buffer[<span class="pl-c1">128</span>];</td>
      </tr>
      <tr>
        <td id="L686" class="blob-num js-line-number" data-line-number="686"></td>
        <td id="LC686" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">char</span> header[] = <span class="pl-s"><span class="pl-pds">&quot;</span>#?RADIANCE<span class="pl-cce">\n</span># Written by stb_image_write.h<span class="pl-cce">\n</span>FORMAT=32-bit_rle_rgbe<span class="pl-cce">\n</span><span class="pl-pds">&quot;</span></span>;</td>
      </tr>
      <tr>
        <td id="L687" class="blob-num js-line-number" data-line-number="687"></td>
        <td id="LC687" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, header, <span class="pl-k">sizeof</span>(header)-<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L688" class="blob-num js-line-number" data-line-number="688"></td>
        <td id="LC688" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L689" class="blob-num js-line-number" data-line-number="689"></td>
        <td id="LC689" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifdef</span> STBI_MSC_SECURE_CRT</td>
      </tr>
      <tr>
        <td id="L690" class="blob-num js-line-number" data-line-number="690"></td>
        <td id="LC690" class="blob-code blob-code-inner js-file-line">      len = <span class="pl-c1">sprintf_s</span>(buffer, <span class="pl-s"><span class="pl-pds">&quot;</span>EXPOSURE=          1.0000000000000<span class="pl-cce">\n\n</span>-Y <span class="pl-c1">%d</span> +X <span class="pl-c1">%d</span><span class="pl-cce">\n</span><span class="pl-pds">&quot;</span></span>, y, x);</td>
      </tr>
      <tr>
        <td id="L691" class="blob-num js-line-number" data-line-number="691"></td>
        <td id="LC691" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L692" class="blob-num js-line-number" data-line-number="692"></td>
        <td id="LC692" class="blob-code blob-code-inner js-file-line">      len = <span class="pl-c1">sprintf</span>(buffer, <span class="pl-s"><span class="pl-pds">&quot;</span>EXPOSURE=          1.0000000000000<span class="pl-cce">\n\n</span>-Y <span class="pl-c1">%d</span> +X <span class="pl-c1">%d</span><span class="pl-cce">\n</span><span class="pl-pds">&quot;</span></span>, y, x);</td>
      </tr>
      <tr>
        <td id="L693" class="blob-num js-line-number" data-line-number="693"></td>
        <td id="LC693" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L694" class="blob-num js-line-number" data-line-number="694"></td>
        <td id="LC694" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, buffer, len);</td>
      </tr>
      <tr>
        <td id="L695" class="blob-num js-line-number" data-line-number="695"></td>
        <td id="LC695" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L696" class="blob-num js-line-number" data-line-number="696"></td>
        <td id="LC696" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span>(i=<span class="pl-c1">0</span>; i &lt; y; i++)</td>
      </tr>
      <tr>
        <td id="L697" class="blob-num js-line-number" data-line-number="697"></td>
        <td id="LC697" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__write_hdr_scanline</span>(s, x, comp, scratch, data + comp*x*(stbi__flip_vertically_on_write ? y-<span class="pl-c1">1</span>-i : i)*x);</td>
      </tr>
      <tr>
        <td id="L698" class="blob-num js-line-number" data-line-number="698"></td>
        <td id="LC698" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">STBIW_FREE</span>(scratch);</td>
      </tr>
      <tr>
        <td id="L699" class="blob-num js-line-number" data-line-number="699"></td>
        <td id="LC699" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L700" class="blob-num js-line-number" data-line-number="700"></td>
        <td id="LC700" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L701" class="blob-num js-line-number" data-line-number="701"></td>
        <td id="LC701" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L702" class="blob-num js-line-number" data-line-number="702"></td>
        <td id="LC702" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L703" class="blob-num js-line-number" data-line-number="703"></td>
        <td id="LC703" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_hdr_to_func</span>(stbi_write_func *func, <span class="pl-k">void</span> *context, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">float</span> *data)</td>
      </tr>
      <tr>
        <td id="L704" class="blob-num js-line-number" data-line-number="704"></td>
        <td id="LC704" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L705" class="blob-num js-line-number" data-line-number="705"></td>
        <td id="LC705" class="blob-code blob-code-inner js-file-line">   stbi__write_context s;</td>
      </tr>
      <tr>
        <td id="L706" class="blob-num js-line-number" data-line-number="706"></td>
        <td id="LC706" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbi__start_write_callbacks</span>(&amp;s, func, context);</td>
      </tr>
      <tr>
        <td id="L707" class="blob-num js-line-number" data-line-number="707"></td>
        <td id="LC707" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">stbi_write_hdr_core</span>(&amp;s, x, y, comp, (<span class="pl-k">float</span> *) data);</td>
      </tr>
      <tr>
        <td id="L708" class="blob-num js-line-number" data-line-number="708"></td>
        <td id="LC708" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L709" class="blob-num js-line-number" data-line-number="709"></td>
        <td id="LC709" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L710" class="blob-num js-line-number" data-line-number="710"></td>
        <td id="LC710" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBI_WRITE_NO_STDIO</td>
      </tr>
      <tr>
        <td id="L711" class="blob-num js-line-number" data-line-number="711"></td>
        <td id="LC711" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_hdr</span>(<span class="pl-k">char</span> <span class="pl-k">const</span> *filename, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">float</span> *data)</td>
      </tr>
      <tr>
        <td id="L712" class="blob-num js-line-number" data-line-number="712"></td>
        <td id="LC712" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L713" class="blob-num js-line-number" data-line-number="713"></td>
        <td id="LC713" class="blob-code blob-code-inner js-file-line">   stbi__write_context s;</td>
      </tr>
      <tr>
        <td id="L714" class="blob-num js-line-number" data-line-number="714"></td>
        <td id="LC714" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (<span class="pl-c1">stbi__start_write_file</span>(&amp;s,filename)) {</td>
      </tr>
      <tr>
        <td id="L715" class="blob-num js-line-number" data-line-number="715"></td>
        <td id="LC715" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> r = <span class="pl-c1">stbi_write_hdr_core</span>(&amp;s, x, y, comp, (<span class="pl-k">float</span> *) data);</td>
      </tr>
      <tr>
        <td id="L716" class="blob-num js-line-number" data-line-number="716"></td>
        <td id="LC716" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbi__end_write_file</span>(&amp;s);</td>
      </tr>
      <tr>
        <td id="L717" class="blob-num js-line-number" data-line-number="717"></td>
        <td id="LC717" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> r;</td>
      </tr>
      <tr>
        <td id="L718" class="blob-num js-line-number" data-line-number="718"></td>
        <td id="LC718" class="blob-code blob-code-inner js-file-line">   } <span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L719" class="blob-num js-line-number" data-line-number="719"></td>
        <td id="LC719" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L720" class="blob-num js-line-number" data-line-number="720"></td>
        <td id="LC720" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L721" class="blob-num js-line-number" data-line-number="721"></td>
        <td id="LC721" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span> <span class="pl-c"><span class="pl-c">//</span> STBI_WRITE_NO_STDIO</span></td>
      </tr>
      <tr>
        <td id="L722" class="blob-num js-line-number" data-line-number="722"></td>
        <td id="LC722" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L723" class="blob-num js-line-number" data-line-number="723"></td>
        <td id="LC723" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L724" class="blob-num js-line-number" data-line-number="724"></td>
        <td id="LC724" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span>////////////////////////////////////////////////////////////////////////////</span></td>
      </tr>
      <tr>
        <td id="L725" class="blob-num js-line-number" data-line-number="725"></td>
        <td id="LC725" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span></span></td>
      </tr>
      <tr>
        <td id="L726" class="blob-num js-line-number" data-line-number="726"></td>
        <td id="LC726" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> PNG writer</span></td>
      </tr>
      <tr>
        <td id="L727" class="blob-num js-line-number" data-line-number="727"></td>
        <td id="LC727" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span></span></td>
      </tr>
      <tr>
        <td id="L728" class="blob-num js-line-number" data-line-number="728"></td>
        <td id="LC728" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L729" class="blob-num js-line-number" data-line-number="729"></td>
        <td id="LC729" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBIW_ZLIB_COMPRESS</td>
      </tr>
      <tr>
        <td id="L730" class="blob-num js-line-number" data-line-number="730"></td>
        <td id="LC730" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> stretchy buffer; stbiw__sbpush() == vector&lt;&gt;::push_back() -- stbiw__sbcount() == vector&lt;&gt;::size()</span></td>
      </tr>
      <tr>
        <td id="L731" class="blob-num js-line-number" data-line-number="731"></td>
        <td id="LC731" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__sbraw</span>(<span class="pl-v">a</span>) ((<span class="pl-k">int</span> *) (a) - <span class="pl-c1">2</span>)</td>
      </tr>
      <tr>
        <td id="L732" class="blob-num js-line-number" data-line-number="732"></td>
        <td id="LC732" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__sbm</span>(<span class="pl-v">a</span>)   stbiw__sbraw(a)[<span class="pl-c1">0</span>]</td>
      </tr>
      <tr>
        <td id="L733" class="blob-num js-line-number" data-line-number="733"></td>
        <td id="LC733" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__sbn</span>(<span class="pl-v">a</span>)   stbiw__sbraw(a)[<span class="pl-c1">1</span>]</td>
      </tr>
      <tr>
        <td id="L734" class="blob-num js-line-number" data-line-number="734"></td>
        <td id="LC734" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L735" class="blob-num js-line-number" data-line-number="735"></td>
        <td id="LC735" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__sbneedgrow</span>(<span class="pl-v">a,n</span>)  ((a)==<span class="pl-c1">0</span> || stbiw__sbn(a)+n &gt;= stbiw__sbm(a))</td>
      </tr>
      <tr>
        <td id="L736" class="blob-num js-line-number" data-line-number="736"></td>
        <td id="LC736" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__sbmaybegrow</span>(<span class="pl-v">a,n</span>) (stbiw__sbneedgrow(a,(n)) ? stbiw__sbgrow(a,n) : <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L737" class="blob-num js-line-number" data-line-number="737"></td>
        <td id="LC737" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__sbgrow</span>(<span class="pl-v">a,n</span>)  stbiw__sbgrowf((<span class="pl-k">void</span> **) &amp;(a), (n), <span class="pl-k">sizeof</span>(*(a)))</td>
      </tr>
      <tr>
        <td id="L738" class="blob-num js-line-number" data-line-number="738"></td>
        <td id="LC738" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L739" class="blob-num js-line-number" data-line-number="739"></td>
        <td id="LC739" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__sbpush</span>(<span class="pl-v">a, v</span>)      (stbiw__sbmaybegrow(a,<span class="pl-c1">1</span>), (a)[stbiw__sbn(a)++] = (v))</td>
      </tr>
      <tr>
        <td id="L740" class="blob-num js-line-number" data-line-number="740"></td>
        <td id="LC740" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__sbcount</span>(<span class="pl-v">a</span>)        ((a) ? stbiw__sbn(a) : <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L741" class="blob-num js-line-number" data-line-number="741"></td>
        <td id="LC741" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__sbfree</span>(<span class="pl-v">a</span>)         ((a) ? STBIW_FREE(stbiw__sbraw(a)),<span class="pl-c1">0</span> : <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L742" class="blob-num js-line-number" data-line-number="742"></td>
        <td id="LC742" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L743" class="blob-num js-line-number" data-line-number="743"></td>
        <td id="LC743" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> *<span class="pl-en">stbiw__sbgrowf</span>(<span class="pl-k">void</span> **arr, <span class="pl-k">int</span> increment, <span class="pl-k">int</span> itemsize)</td>
      </tr>
      <tr>
        <td id="L744" class="blob-num js-line-number" data-line-number="744"></td>
        <td id="LC744" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L745" class="blob-num js-line-number" data-line-number="745"></td>
        <td id="LC745" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> m = *arr ? <span class="pl-c1">2</span>*<span class="pl-c1">stbiw__sbm</span>(*arr)+increment : increment+<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L746" class="blob-num js-line-number" data-line-number="746"></td>
        <td id="LC746" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">void</span> *p = <span class="pl-c1">STBIW_REALLOC_SIZED</span>(*arr ? <span class="pl-c1">stbiw__sbraw</span>(*arr) : <span class="pl-c1">0</span>, *arr ? (<span class="pl-c1">stbiw__sbm</span>(*arr)*itemsize + <span class="pl-k">sizeof</span>(<span class="pl-k">int</span>)*<span class="pl-c1">2</span>) : <span class="pl-c1">0</span>, itemsize * m + <span class="pl-k">sizeof</span>(<span class="pl-k">int</span>)*<span class="pl-c1">2</span>);</td>
      </tr>
      <tr>
        <td id="L747" class="blob-num js-line-number" data-line-number="747"></td>
        <td id="LC747" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_ASSERT</span>(p);</td>
      </tr>
      <tr>
        <td id="L748" class="blob-num js-line-number" data-line-number="748"></td>
        <td id="LC748" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (p) {</td>
      </tr>
      <tr>
        <td id="L749" class="blob-num js-line-number" data-line-number="749"></td>
        <td id="LC749" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (!*arr) ((<span class="pl-k">int</span> *) p)[<span class="pl-c1">1</span>] = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L750" class="blob-num js-line-number" data-line-number="750"></td>
        <td id="LC750" class="blob-code blob-code-inner js-file-line">      *arr = (<span class="pl-k">void</span> *) ((<span class="pl-k">int</span> *) p + <span class="pl-c1">2</span>);</td>
      </tr>
      <tr>
        <td id="L751" class="blob-num js-line-number" data-line-number="751"></td>
        <td id="LC751" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__sbm</span>(*arr) = m;</td>
      </tr>
      <tr>
        <td id="L752" class="blob-num js-line-number" data-line-number="752"></td>
        <td id="LC752" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L753" class="blob-num js-line-number" data-line-number="753"></td>
        <td id="LC753" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> *arr;</td>
      </tr>
      <tr>
        <td id="L754" class="blob-num js-line-number" data-line-number="754"></td>
        <td id="LC754" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L755" class="blob-num js-line-number" data-line-number="755"></td>
        <td id="LC755" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L756" class="blob-num js-line-number" data-line-number="756"></td>
        <td id="LC756" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *<span class="pl-en">stbiw__zlib_flushf</span>(<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *data, <span class="pl-k">unsigned</span> <span class="pl-k">int</span> *bitbuffer, <span class="pl-k">int</span> *bitcount)</td>
      </tr>
      <tr>
        <td id="L757" class="blob-num js-line-number" data-line-number="757"></td>
        <td id="LC757" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L758" class="blob-num js-line-number" data-line-number="758"></td>
        <td id="LC758" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">while</span> (*bitcount &gt;= <span class="pl-c1">8</span>) {</td>
      </tr>
      <tr>
        <td id="L759" class="blob-num js-line-number" data-line-number="759"></td>
        <td id="LC759" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__sbpush</span>(data, <span class="pl-c1">STBIW_UCHAR</span>(*bitbuffer));</td>
      </tr>
      <tr>
        <td id="L760" class="blob-num js-line-number" data-line-number="760"></td>
        <td id="LC760" class="blob-code blob-code-inner js-file-line">      *bitbuffer &gt;&gt;= <span class="pl-c1">8</span>;</td>
      </tr>
      <tr>
        <td id="L761" class="blob-num js-line-number" data-line-number="761"></td>
        <td id="LC761" class="blob-code blob-code-inner js-file-line">      *bitcount -= <span class="pl-c1">8</span>;</td>
      </tr>
      <tr>
        <td id="L762" class="blob-num js-line-number" data-line-number="762"></td>
        <td id="LC762" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L763" class="blob-num js-line-number" data-line-number="763"></td>
        <td id="LC763" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> data;</td>
      </tr>
      <tr>
        <td id="L764" class="blob-num js-line-number" data-line-number="764"></td>
        <td id="LC764" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L765" class="blob-num js-line-number" data-line-number="765"></td>
        <td id="LC765" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L766" class="blob-num js-line-number" data-line-number="766"></td>
        <td id="LC766" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> <span class="pl-en">stbiw__zlib_bitrev</span>(<span class="pl-k">int</span> code, <span class="pl-k">int</span> codebits)</td>
      </tr>
      <tr>
        <td id="L767" class="blob-num js-line-number" data-line-number="767"></td>
        <td id="LC767" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L768" class="blob-num js-line-number" data-line-number="768"></td>
        <td id="LC768" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> res=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L769" class="blob-num js-line-number" data-line-number="769"></td>
        <td id="LC769" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">while</span> (codebits--) {</td>
      </tr>
      <tr>
        <td id="L770" class="blob-num js-line-number" data-line-number="770"></td>
        <td id="LC770" class="blob-code blob-code-inner js-file-line">      res = (res &lt;&lt; <span class="pl-c1">1</span>) | (code &amp; <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L771" class="blob-num js-line-number" data-line-number="771"></td>
        <td id="LC771" class="blob-code blob-code-inner js-file-line">      code &gt;&gt;= <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L772" class="blob-num js-line-number" data-line-number="772"></td>
        <td id="LC772" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L773" class="blob-num js-line-number" data-line-number="773"></td>
        <td id="LC773" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> res;</td>
      </tr>
      <tr>
        <td id="L774" class="blob-num js-line-number" data-line-number="774"></td>
        <td id="LC774" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L775" class="blob-num js-line-number" data-line-number="775"></td>
        <td id="LC775" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L776" class="blob-num js-line-number" data-line-number="776"></td>
        <td id="LC776" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">unsigned</span> <span class="pl-k">int</span> <span class="pl-en">stbiw__zlib_countm</span>(<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *a, <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *b, <span class="pl-k">int</span> limit)</td>
      </tr>
      <tr>
        <td id="L777" class="blob-num js-line-number" data-line-number="777"></td>
        <td id="LC777" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L778" class="blob-num js-line-number" data-line-number="778"></td>
        <td id="LC778" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> i;</td>
      </tr>
      <tr>
        <td id="L779" class="blob-num js-line-number" data-line-number="779"></td>
        <td id="LC779" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span> (i=<span class="pl-c1">0</span>; i &lt; limit &amp;&amp; i &lt; <span class="pl-c1">258</span>; ++i)</td>
      </tr>
      <tr>
        <td id="L780" class="blob-num js-line-number" data-line-number="780"></td>
        <td id="LC780" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (a[i] != b[i]) <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L781" class="blob-num js-line-number" data-line-number="781"></td>
        <td id="LC781" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> i;</td>
      </tr>
      <tr>
        <td id="L782" class="blob-num js-line-number" data-line-number="782"></td>
        <td id="LC782" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L783" class="blob-num js-line-number" data-line-number="783"></td>
        <td id="LC783" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L784" class="blob-num js-line-number" data-line-number="784"></td>
        <td id="LC784" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">unsigned</span> <span class="pl-k">int</span> <span class="pl-en">stbiw__zhash</span>(<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *data)</td>
      </tr>
      <tr>
        <td id="L785" class="blob-num js-line-number" data-line-number="785"></td>
        <td id="LC785" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L786" class="blob-num js-line-number" data-line-number="786"></td>
        <td id="LC786" class="blob-code blob-code-inner js-file-line">   stbiw_uint32 hash = data[<span class="pl-c1">0</span>] + (data[<span class="pl-c1">1</span>] &lt;&lt; <span class="pl-c1">8</span>) + (data[<span class="pl-c1">2</span>] &lt;&lt; <span class="pl-c1">16</span>);</td>
      </tr>
      <tr>
        <td id="L787" class="blob-num js-line-number" data-line-number="787"></td>
        <td id="LC787" class="blob-code blob-code-inner js-file-line">   hash ^= hash &lt;&lt; <span class="pl-c1">3</span>;</td>
      </tr>
      <tr>
        <td id="L788" class="blob-num js-line-number" data-line-number="788"></td>
        <td id="LC788" class="blob-code blob-code-inner js-file-line">   hash += hash &gt;&gt; <span class="pl-c1">5</span>;</td>
      </tr>
      <tr>
        <td id="L789" class="blob-num js-line-number" data-line-number="789"></td>
        <td id="LC789" class="blob-code blob-code-inner js-file-line">   hash ^= hash &lt;&lt; <span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L790" class="blob-num js-line-number" data-line-number="790"></td>
        <td id="LC790" class="blob-code blob-code-inner js-file-line">   hash += hash &gt;&gt; <span class="pl-c1">17</span>;</td>
      </tr>
      <tr>
        <td id="L791" class="blob-num js-line-number" data-line-number="791"></td>
        <td id="LC791" class="blob-code blob-code-inner js-file-line">   hash ^= hash &lt;&lt; <span class="pl-c1">25</span>;</td>
      </tr>
      <tr>
        <td id="L792" class="blob-num js-line-number" data-line-number="792"></td>
        <td id="LC792" class="blob-code blob-code-inner js-file-line">   hash += hash &gt;&gt; <span class="pl-c1">6</span>;</td>
      </tr>
      <tr>
        <td id="L793" class="blob-num js-line-number" data-line-number="793"></td>
        <td id="LC793" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> hash;</td>
      </tr>
      <tr>
        <td id="L794" class="blob-num js-line-number" data-line-number="794"></td>
        <td id="LC794" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L795" class="blob-num js-line-number" data-line-number="795"></td>
        <td id="LC795" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L796" class="blob-num js-line-number" data-line-number="796"></td>
        <td id="LC796" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__zlib_flush</span>() (out = stbiw__zlib_flushf(out, &amp;bitbuf, &amp;bitcount))</td>
      </tr>
      <tr>
        <td id="L797" class="blob-num js-line-number" data-line-number="797"></td>
        <td id="LC797" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__zlib_add</span>(<span class="pl-v">code,codebits</span>) \</td>
      </tr>
      <tr>
        <td id="L798" class="blob-num js-line-number" data-line-number="798"></td>
        <td id="LC798" class="blob-code blob-code-inner js-file-line">      (bitbuf |= (code) &lt;&lt; bitcount, bitcount += (codebits), stbiw__zlib_flush())</td>
      </tr>
      <tr>
        <td id="L799" class="blob-num js-line-number" data-line-number="799"></td>
        <td id="LC799" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__zlib_huffa</span>(<span class="pl-v">b,c</span>)  stbiw__zlib_add(stbiw__zlib_bitrev(b,c),c)</td>
      </tr>
      <tr>
        <td id="L800" class="blob-num js-line-number" data-line-number="800"></td>
        <td id="LC800" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> default huffman tables</span></td>
      </tr>
      <tr>
        <td id="L801" class="blob-num js-line-number" data-line-number="801"></td>
        <td id="LC801" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__zlib_huff1</span>(<span class="pl-v">n</span>)  stbiw__zlib_huffa(<span class="pl-c1">0x30</span> + (n), <span class="pl-c1">8</span>)</td>
      </tr>
      <tr>
        <td id="L802" class="blob-num js-line-number" data-line-number="802"></td>
        <td id="LC802" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__zlib_huff2</span>(<span class="pl-v">n</span>)  stbiw__zlib_huffa(<span class="pl-c1">0x190</span> + (n)-<span class="pl-c1">144</span>, <span class="pl-c1">9</span>)</td>
      </tr>
      <tr>
        <td id="L803" class="blob-num js-line-number" data-line-number="803"></td>
        <td id="LC803" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__zlib_huff3</span>(<span class="pl-v">n</span>)  stbiw__zlib_huffa(<span class="pl-c1">0</span> + (n)-<span class="pl-c1">256</span>,<span class="pl-c1">7</span>)</td>
      </tr>
      <tr>
        <td id="L804" class="blob-num js-line-number" data-line-number="804"></td>
        <td id="LC804" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__zlib_huff4</span>(<span class="pl-v">n</span>)  stbiw__zlib_huffa(<span class="pl-c1">0xc0</span> + (n)-<span class="pl-c1">280</span>,<span class="pl-c1">8</span>)</td>
      </tr>
      <tr>
        <td id="L805" class="blob-num js-line-number" data-line-number="805"></td>
        <td id="LC805" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__zlib_huff</span>(<span class="pl-v">n</span>)  ((n) &lt;= <span class="pl-c1">143</span> ? stbiw__zlib_huff1(n) : (n) &lt;= <span class="pl-c1">255</span> ? stbiw__zlib_huff2(n) : (n) &lt;= <span class="pl-c1">279</span> ? stbiw__zlib_huff3(n) : stbiw__zlib_huff4(n))</td>
      </tr>
      <tr>
        <td id="L806" class="blob-num js-line-number" data-line-number="806"></td>
        <td id="LC806" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__zlib_huffb</span>(<span class="pl-v">n</span>) ((n) &lt;= <span class="pl-c1">143</span> ? stbiw__zlib_huff1(n) : stbiw__zlib_huff2(n))</td>
      </tr>
      <tr>
        <td id="L807" class="blob-num js-line-number" data-line-number="807"></td>
        <td id="LC807" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L808" class="blob-num js-line-number" data-line-number="808"></td>
        <td id="LC808" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__ZHASH</span>   <span class="pl-c1">16384</span></td>
      </tr>
      <tr>
        <td id="L809" class="blob-num js-line-number" data-line-number="809"></td>
        <td id="LC809" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L810" class="blob-num js-line-number" data-line-number="810"></td>
        <td id="LC810" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span> <span class="pl-c"><span class="pl-c">//</span> STBIW_ZLIB_COMPRESS</span></td>
      </tr>
      <tr>
        <td id="L811" class="blob-num js-line-number" data-line-number="811"></td>
        <td id="LC811" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L812" class="blob-num js-line-number" data-line-number="812"></td>
        <td id="LC812" class="blob-code blob-code-inner js-file-line"><span class="pl-k">unsigned</span> <span class="pl-k">char</span> * <span class="pl-en">stbi_zlib_compress</span>(<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *data, <span class="pl-k">int</span> data_len, <span class="pl-k">int</span> *out_len, <span class="pl-k">int</span> quality)</td>
      </tr>
      <tr>
        <td id="L813" class="blob-num js-line-number" data-line-number="813"></td>
        <td id="LC813" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L814" class="blob-num js-line-number" data-line-number="814"></td>
        <td id="LC814" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifdef</span> STBIW_ZLIB_COMPRESS</td>
      </tr>
      <tr>
        <td id="L815" class="blob-num js-line-number" data-line-number="815"></td>
        <td id="LC815" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> user provided a zlib compress implementation, use that</span></td>
      </tr>
      <tr>
        <td id="L816" class="blob-num js-line-number" data-line-number="816"></td>
        <td id="LC816" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">STBIW_ZLIB_COMPRESS</span>(data, data_len, out_len, quality);</td>
      </tr>
      <tr>
        <td id="L817" class="blob-num js-line-number" data-line-number="817"></td>
        <td id="LC817" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">else</span> <span class="pl-c"><span class="pl-c">//</span> use builtin</span></td>
      </tr>
      <tr>
        <td id="L818" class="blob-num js-line-number" data-line-number="818"></td>
        <td id="LC818" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> lengthc[] = { <span class="pl-c1">3</span>,<span class="pl-c1">4</span>,<span class="pl-c1">5</span>,<span class="pl-c1">6</span>,<span class="pl-c1">7</span>,<span class="pl-c1">8</span>,<span class="pl-c1">9</span>,<span class="pl-c1">10</span>,<span class="pl-c1">11</span>,<span class="pl-c1">13</span>,<span class="pl-c1">15</span>,<span class="pl-c1">17</span>,<span class="pl-c1">19</span>,<span class="pl-c1">23</span>,<span class="pl-c1">27</span>,<span class="pl-c1">31</span>,<span class="pl-c1">35</span>,<span class="pl-c1">43</span>,<span class="pl-c1">51</span>,<span class="pl-c1">59</span>,<span class="pl-c1">67</span>,<span class="pl-c1">83</span>,<span class="pl-c1">99</span>,<span class="pl-c1">115</span>,<span class="pl-c1">131</span>,<span class="pl-c1">163</span>,<span class="pl-c1">195</span>,<span class="pl-c1">227</span>,<span class="pl-c1">258</span>, <span class="pl-c1">259</span> };</td>
      </tr>
      <tr>
        <td id="L819" class="blob-num js-line-number" data-line-number="819"></td>
        <td id="LC819" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span>  lengtheb[]= { <span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>, <span class="pl-c1">0</span>, <span class="pl-c1">1</span>, <span class="pl-c1">1</span>, <span class="pl-c1">1</span>, <span class="pl-c1">1</span>, <span class="pl-c1">2</span>, <span class="pl-c1">2</span>, <span class="pl-c1">2</span>, <span class="pl-c1">2</span>, <span class="pl-c1">3</span>, <span class="pl-c1">3</span>, <span class="pl-c1">3</span>, <span class="pl-c1">3</span>, <span class="pl-c1">4</span>, <span class="pl-c1">4</span>, <span class="pl-c1">4</span>,  <span class="pl-c1">4</span>,  <span class="pl-c1">5</span>,  <span class="pl-c1">5</span>,  <span class="pl-c1">5</span>,  <span class="pl-c1">5</span>,  <span class="pl-c1">0</span> };</td>
      </tr>
      <tr>
        <td id="L820" class="blob-num js-line-number" data-line-number="820"></td>
        <td id="LC820" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> distc[]   = { <span class="pl-c1">1</span>,<span class="pl-c1">2</span>,<span class="pl-c1">3</span>,<span class="pl-c1">4</span>,<span class="pl-c1">5</span>,<span class="pl-c1">7</span>,<span class="pl-c1">9</span>,<span class="pl-c1">13</span>,<span class="pl-c1">17</span>,<span class="pl-c1">25</span>,<span class="pl-c1">33</span>,<span class="pl-c1">49</span>,<span class="pl-c1">65</span>,<span class="pl-c1">97</span>,<span class="pl-c1">129</span>,<span class="pl-c1">193</span>,<span class="pl-c1">257</span>,<span class="pl-c1">385</span>,<span class="pl-c1">513</span>,<span class="pl-c1">769</span>,<span class="pl-c1">1025</span>,<span class="pl-c1">1537</span>,<span class="pl-c1">2049</span>,<span class="pl-c1">3073</span>,<span class="pl-c1">4097</span>,<span class="pl-c1">6145</span>,<span class="pl-c1">8193</span>,<span class="pl-c1">12289</span>,<span class="pl-c1">16385</span>,<span class="pl-c1">24577</span>, <span class="pl-c1">32768</span> };</td>
      </tr>
      <tr>
        <td id="L821" class="blob-num js-line-number" data-line-number="821"></td>
        <td id="LC821" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span>  disteb[]  = { <span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">2</span>,<span class="pl-c1">2</span>,<span class="pl-c1">3</span>,<span class="pl-c1">3</span>,<span class="pl-c1">4</span>,<span class="pl-c1">4</span>,<span class="pl-c1">5</span>,<span class="pl-c1">5</span>,<span class="pl-c1">6</span>,<span class="pl-c1">6</span>,<span class="pl-c1">7</span>,<span class="pl-c1">7</span>,<span class="pl-c1">8</span>,<span class="pl-c1">8</span>,<span class="pl-c1">9</span>,<span class="pl-c1">9</span>,<span class="pl-c1">10</span>,<span class="pl-c1">10</span>,<span class="pl-c1">11</span>,<span class="pl-c1">11</span>,<span class="pl-c1">12</span>,<span class="pl-c1">12</span>,<span class="pl-c1">13</span>,<span class="pl-c1">13</span> };</td>
      </tr>
      <tr>
        <td id="L822" class="blob-num js-line-number" data-line-number="822"></td>
        <td id="LC822" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">int</span> bitbuf=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L823" class="blob-num js-line-number" data-line-number="823"></td>
        <td id="LC823" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> i,j, bitcount=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L824" class="blob-num js-line-number" data-line-number="824"></td>
        <td id="LC824" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *out = <span class="pl-c1">NULL</span>;</td>
      </tr>
      <tr>
        <td id="L825" class="blob-num js-line-number" data-line-number="825"></td>
        <td id="LC825" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> ***hash_table = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span>***) <span class="pl-c1">STBIW_MALLOC</span>(stbiw__ZHASH * <span class="pl-k">sizeof</span>(<span class="pl-k">char</span>**));</td>
      </tr>
      <tr>
        <td id="L826" class="blob-num js-line-number" data-line-number="826"></td>
        <td id="LC826" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (hash_table == <span class="pl-c1">NULL</span>)</td>
      </tr>
      <tr>
        <td id="L827" class="blob-num js-line-number" data-line-number="827"></td>
        <td id="LC827" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">NULL</span>;</td>
      </tr>
      <tr>
        <td id="L828" class="blob-num js-line-number" data-line-number="828"></td>
        <td id="LC828" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (quality &lt; <span class="pl-c1">5</span>) quality = <span class="pl-c1">5</span>;</td>
      </tr>
      <tr>
        <td id="L829" class="blob-num js-line-number" data-line-number="829"></td>
        <td id="LC829" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L830" class="blob-num js-line-number" data-line-number="830"></td>
        <td id="LC830" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__sbpush</span>(out, <span class="pl-c1">0x78</span>);   <span class="pl-c"><span class="pl-c">//</span> DEFLATE 32K window</span></td>
      </tr>
      <tr>
        <td id="L831" class="blob-num js-line-number" data-line-number="831"></td>
        <td id="LC831" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__sbpush</span>(out, <span class="pl-c1">0x5e</span>);   <span class="pl-c"><span class="pl-c">//</span> FLEVEL = 1</span></td>
      </tr>
      <tr>
        <td id="L832" class="blob-num js-line-number" data-line-number="832"></td>
        <td id="LC832" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__zlib_add</span>(<span class="pl-c1">1</span>,<span class="pl-c1">1</span>);  <span class="pl-c"><span class="pl-c">//</span> BFINAL = 1</span></td>
      </tr>
      <tr>
        <td id="L833" class="blob-num js-line-number" data-line-number="833"></td>
        <td id="LC833" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__zlib_add</span>(<span class="pl-c1">1</span>,<span class="pl-c1">2</span>);  <span class="pl-c"><span class="pl-c">//</span> BTYPE = 1 -- fixed huffman</span></td>
      </tr>
      <tr>
        <td id="L834" class="blob-num js-line-number" data-line-number="834"></td>
        <td id="LC834" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L835" class="blob-num js-line-number" data-line-number="835"></td>
        <td id="LC835" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span> (i=<span class="pl-c1">0</span>; i &lt; stbiw__ZHASH; ++i)</td>
      </tr>
      <tr>
        <td id="L836" class="blob-num js-line-number" data-line-number="836"></td>
        <td id="LC836" class="blob-code blob-code-inner js-file-line">      hash_table[i] = <span class="pl-c1">NULL</span>;</td>
      </tr>
      <tr>
        <td id="L837" class="blob-num js-line-number" data-line-number="837"></td>
        <td id="LC837" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L838" class="blob-num js-line-number" data-line-number="838"></td>
        <td id="LC838" class="blob-code blob-code-inner js-file-line">   i=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L839" class="blob-num js-line-number" data-line-number="839"></td>
        <td id="LC839" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">while</span> (i &lt; data_len-<span class="pl-c1">3</span>) {</td>
      </tr>
      <tr>
        <td id="L840" class="blob-num js-line-number" data-line-number="840"></td>
        <td id="LC840" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> hash next 3 bytes of data to be compressed</span></td>
      </tr>
      <tr>
        <td id="L841" class="blob-num js-line-number" data-line-number="841"></td>
        <td id="LC841" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> h = <span class="pl-c1">stbiw__zhash</span>(data+i)&amp;(stbiw__ZHASH-<span class="pl-c1">1</span>), best=<span class="pl-c1">3</span>;</td>
      </tr>
      <tr>
        <td id="L842" class="blob-num js-line-number" data-line-number="842"></td>
        <td id="LC842" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *bestloc = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L843" class="blob-num js-line-number" data-line-number="843"></td>
        <td id="LC843" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">unsigned</span> <span class="pl-k">char</span> **hlist = hash_table[h];</td>
      </tr>
      <tr>
        <td id="L844" class="blob-num js-line-number" data-line-number="844"></td>
        <td id="LC844" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> n = <span class="pl-c1">stbiw__sbcount</span>(hlist);</td>
      </tr>
      <tr>
        <td id="L845" class="blob-num js-line-number" data-line-number="845"></td>
        <td id="LC845" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (j=<span class="pl-c1">0</span>; j &lt; n; ++j) {</td>
      </tr>
      <tr>
        <td id="L846" class="blob-num js-line-number" data-line-number="846"></td>
        <td id="LC846" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">if</span> (hlist[j]-data &gt; i-<span class="pl-c1">32768</span>) { <span class="pl-c"><span class="pl-c">//</span> if entry lies within window</span></td>
      </tr>
      <tr>
        <td id="L847" class="blob-num js-line-number" data-line-number="847"></td>
        <td id="LC847" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">int</span> d = <span class="pl-c1">stbiw__zlib_countm</span>(hlist[j], data+i, data_len-i);</td>
      </tr>
      <tr>
        <td id="L848" class="blob-num js-line-number" data-line-number="848"></td>
        <td id="LC848" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">if</span> (d &gt;= best) best=d,bestloc=hlist[j];</td>
      </tr>
      <tr>
        <td id="L849" class="blob-num js-line-number" data-line-number="849"></td>
        <td id="LC849" class="blob-code blob-code-inner js-file-line">         }</td>
      </tr>
      <tr>
        <td id="L850" class="blob-num js-line-number" data-line-number="850"></td>
        <td id="LC850" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L851" class="blob-num js-line-number" data-line-number="851"></td>
        <td id="LC851" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> when hash table entry is too long, delete half the entries</span></td>
      </tr>
      <tr>
        <td id="L852" class="blob-num js-line-number" data-line-number="852"></td>
        <td id="LC852" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (hash_table[h] &amp;&amp; <span class="pl-c1">stbiw__sbn</span>(hash_table[h]) == <span class="pl-c1">2</span>*quality) {</td>
      </tr>
      <tr>
        <td id="L853" class="blob-num js-line-number" data-line-number="853"></td>
        <td id="LC853" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">STBIW_MEMMOVE</span>(hash_table[h], hash_table[h]+quality, <span class="pl-k">sizeof</span>(hash_table[h][<span class="pl-c1">0</span>])*quality);</td>
      </tr>
      <tr>
        <td id="L854" class="blob-num js-line-number" data-line-number="854"></td>
        <td id="LC854" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__sbn</span>(hash_table[h]) = quality;</td>
      </tr>
      <tr>
        <td id="L855" class="blob-num js-line-number" data-line-number="855"></td>
        <td id="LC855" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L856" class="blob-num js-line-number" data-line-number="856"></td>
        <td id="LC856" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__sbpush</span>(hash_table[h],data+i);</td>
      </tr>
      <tr>
        <td id="L857" class="blob-num js-line-number" data-line-number="857"></td>
        <td id="LC857" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L858" class="blob-num js-line-number" data-line-number="858"></td>
        <td id="LC858" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bestloc) {</td>
      </tr>
      <tr>
        <td id="L859" class="blob-num js-line-number" data-line-number="859"></td>
        <td id="LC859" class="blob-code blob-code-inner js-file-line">         <span class="pl-c"><span class="pl-c">//</span> &quot;lazy matching&quot; - check match at *next* byte, and if it&#39;s better, do cur byte as literal</span></td>
      </tr>
      <tr>
        <td id="L860" class="blob-num js-line-number" data-line-number="860"></td>
        <td id="LC860" class="blob-code blob-code-inner js-file-line">         h = <span class="pl-c1">stbiw__zhash</span>(data+i+<span class="pl-c1">1</span>)&amp;(stbiw__ZHASH-<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L861" class="blob-num js-line-number" data-line-number="861"></td>
        <td id="LC861" class="blob-code blob-code-inner js-file-line">         hlist = hash_table[h];</td>
      </tr>
      <tr>
        <td id="L862" class="blob-num js-line-number" data-line-number="862"></td>
        <td id="LC862" class="blob-code blob-code-inner js-file-line">         n = <span class="pl-c1">stbiw__sbcount</span>(hlist);</td>
      </tr>
      <tr>
        <td id="L863" class="blob-num js-line-number" data-line-number="863"></td>
        <td id="LC863" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">for</span> (j=<span class="pl-c1">0</span>; j &lt; n; ++j) {</td>
      </tr>
      <tr>
        <td id="L864" class="blob-num js-line-number" data-line-number="864"></td>
        <td id="LC864" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">if</span> (hlist[j]-data &gt; i-<span class="pl-c1">32767</span>) {</td>
      </tr>
      <tr>
        <td id="L865" class="blob-num js-line-number" data-line-number="865"></td>
        <td id="LC865" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">int</span> e = <span class="pl-c1">stbiw__zlib_countm</span>(hlist[j], data+i+<span class="pl-c1">1</span>, data_len-i-<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L866" class="blob-num js-line-number" data-line-number="866"></td>
        <td id="LC866" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">if</span> (e &gt; best) { <span class="pl-c"><span class="pl-c">//</span> if next match is better, bail on current match</span></td>
      </tr>
      <tr>
        <td id="L867" class="blob-num js-line-number" data-line-number="867"></td>
        <td id="LC867" class="blob-code blob-code-inner js-file-line">                  bestloc = <span class="pl-c1">NULL</span>;</td>
      </tr>
      <tr>
        <td id="L868" class="blob-num js-line-number" data-line-number="868"></td>
        <td id="LC868" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L869" class="blob-num js-line-number" data-line-number="869"></td>
        <td id="LC869" class="blob-code blob-code-inner js-file-line">               }</td>
      </tr>
      <tr>
        <td id="L870" class="blob-num js-line-number" data-line-number="870"></td>
        <td id="LC870" class="blob-code blob-code-inner js-file-line">            }</td>
      </tr>
      <tr>
        <td id="L871" class="blob-num js-line-number" data-line-number="871"></td>
        <td id="LC871" class="blob-code blob-code-inner js-file-line">         }</td>
      </tr>
      <tr>
        <td id="L872" class="blob-num js-line-number" data-line-number="872"></td>
        <td id="LC872" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L873" class="blob-num js-line-number" data-line-number="873"></td>
        <td id="LC873" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L874" class="blob-num js-line-number" data-line-number="874"></td>
        <td id="LC874" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (bestloc) {</td>
      </tr>
      <tr>
        <td id="L875" class="blob-num js-line-number" data-line-number="875"></td>
        <td id="LC875" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">int</span> d = (<span class="pl-k">int</span>) (data+i - bestloc); <span class="pl-c"><span class="pl-c">//</span> distance back</span></td>
      </tr>
      <tr>
        <td id="L876" class="blob-num js-line-number" data-line-number="876"></td>
        <td id="LC876" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">STBIW_ASSERT</span>(d &lt;= <span class="pl-c1">32767</span> &amp;&amp; best &lt;= <span class="pl-c1">258</span>);</td>
      </tr>
      <tr>
        <td id="L877" class="blob-num js-line-number" data-line-number="877"></td>
        <td id="LC877" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">for</span> (j=<span class="pl-c1">0</span>; best &gt; lengthc[j+<span class="pl-c1">1</span>]-<span class="pl-c1">1</span>; ++j);</td>
      </tr>
      <tr>
        <td id="L878" class="blob-num js-line-number" data-line-number="878"></td>
        <td id="LC878" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__zlib_huff</span>(j+<span class="pl-c1">257</span>);</td>
      </tr>
      <tr>
        <td id="L879" class="blob-num js-line-number" data-line-number="879"></td>
        <td id="LC879" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">if</span> (lengtheb[j]) <span class="pl-c1">stbiw__zlib_add</span>(best - lengthc[j], lengtheb[j]);</td>
      </tr>
      <tr>
        <td id="L880" class="blob-num js-line-number" data-line-number="880"></td>
        <td id="LC880" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">for</span> (j=<span class="pl-c1">0</span>; d &gt; distc[j+<span class="pl-c1">1</span>]-<span class="pl-c1">1</span>; ++j);</td>
      </tr>
      <tr>
        <td id="L881" class="blob-num js-line-number" data-line-number="881"></td>
        <td id="LC881" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__zlib_add</span>(<span class="pl-c1">stbiw__zlib_bitrev</span>(j,<span class="pl-c1">5</span>),<span class="pl-c1">5</span>);</td>
      </tr>
      <tr>
        <td id="L882" class="blob-num js-line-number" data-line-number="882"></td>
        <td id="LC882" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">if</span> (disteb[j]) <span class="pl-c1">stbiw__zlib_add</span>(d - distc[j], disteb[j]);</td>
      </tr>
      <tr>
        <td id="L883" class="blob-num js-line-number" data-line-number="883"></td>
        <td id="LC883" class="blob-code blob-code-inner js-file-line">         i += best;</td>
      </tr>
      <tr>
        <td id="L884" class="blob-num js-line-number" data-line-number="884"></td>
        <td id="LC884" class="blob-code blob-code-inner js-file-line">      } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L885" class="blob-num js-line-number" data-line-number="885"></td>
        <td id="LC885" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__zlib_huffb</span>(data[i]);</td>
      </tr>
      <tr>
        <td id="L886" class="blob-num js-line-number" data-line-number="886"></td>
        <td id="LC886" class="blob-code blob-code-inner js-file-line">         ++i;</td>
      </tr>
      <tr>
        <td id="L887" class="blob-num js-line-number" data-line-number="887"></td>
        <td id="LC887" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L888" class="blob-num js-line-number" data-line-number="888"></td>
        <td id="LC888" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L889" class="blob-num js-line-number" data-line-number="889"></td>
        <td id="LC889" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> write out final bytes</span></td>
      </tr>
      <tr>
        <td id="L890" class="blob-num js-line-number" data-line-number="890"></td>
        <td id="LC890" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span> (;i &lt; data_len; ++i)</td>
      </tr>
      <tr>
        <td id="L891" class="blob-num js-line-number" data-line-number="891"></td>
        <td id="LC891" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__zlib_huffb</span>(data[i]);</td>
      </tr>
      <tr>
        <td id="L892" class="blob-num js-line-number" data-line-number="892"></td>
        <td id="LC892" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__zlib_huff</span>(<span class="pl-c1">256</span>); <span class="pl-c"><span class="pl-c">//</span> end of block</span></td>
      </tr>
      <tr>
        <td id="L893" class="blob-num js-line-number" data-line-number="893"></td>
        <td id="LC893" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> pad with 0 bits to byte boundary</span></td>
      </tr>
      <tr>
        <td id="L894" class="blob-num js-line-number" data-line-number="894"></td>
        <td id="LC894" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">while</span> (bitcount)</td>
      </tr>
      <tr>
        <td id="L895" class="blob-num js-line-number" data-line-number="895"></td>
        <td id="LC895" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__zlib_add</span>(<span class="pl-c1">0</span>,<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L896" class="blob-num js-line-number" data-line-number="896"></td>
        <td id="LC896" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L897" class="blob-num js-line-number" data-line-number="897"></td>
        <td id="LC897" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span> (i=<span class="pl-c1">0</span>; i &lt; stbiw__ZHASH; ++i)</td>
      </tr>
      <tr>
        <td id="L898" class="blob-num js-line-number" data-line-number="898"></td>
        <td id="LC898" class="blob-code blob-code-inner js-file-line">      (<span class="pl-k">void</span>) <span class="pl-c1">stbiw__sbfree</span>(hash_table[i]);</td>
      </tr>
      <tr>
        <td id="L899" class="blob-num js-line-number" data-line-number="899"></td>
        <td id="LC899" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_FREE</span>(hash_table);</td>
      </tr>
      <tr>
        <td id="L900" class="blob-num js-line-number" data-line-number="900"></td>
        <td id="LC900" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L901" class="blob-num js-line-number" data-line-number="901"></td>
        <td id="LC901" class="blob-code blob-code-inner js-file-line">   {</td>
      </tr>
      <tr>
        <td id="L902" class="blob-num js-line-number" data-line-number="902"></td>
        <td id="LC902" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> compute adler32 on input</span></td>
      </tr>
      <tr>
        <td id="L903" class="blob-num js-line-number" data-line-number="903"></td>
        <td id="LC903" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">unsigned</span> <span class="pl-k">int</span> s1=<span class="pl-c1">1</span>, s2=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L904" class="blob-num js-line-number" data-line-number="904"></td>
        <td id="LC904" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> blocklen = (<span class="pl-k">int</span>) (data_len % <span class="pl-c1">5552</span>);</td>
      </tr>
      <tr>
        <td id="L905" class="blob-num js-line-number" data-line-number="905"></td>
        <td id="LC905" class="blob-code blob-code-inner js-file-line">      j=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L906" class="blob-num js-line-number" data-line-number="906"></td>
        <td id="LC906" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">while</span> (j &lt; data_len) {</td>
      </tr>
      <tr>
        <td id="L907" class="blob-num js-line-number" data-line-number="907"></td>
        <td id="LC907" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">for</span> (i=<span class="pl-c1">0</span>; i &lt; blocklen; ++i) s1 += data[j+i], s2 += s1;</td>
      </tr>
      <tr>
        <td id="L908" class="blob-num js-line-number" data-line-number="908"></td>
        <td id="LC908" class="blob-code blob-code-inner js-file-line">         s1 %= <span class="pl-c1">65521</span>, s2 %= <span class="pl-c1">65521</span>;</td>
      </tr>
      <tr>
        <td id="L909" class="blob-num js-line-number" data-line-number="909"></td>
        <td id="LC909" class="blob-code blob-code-inner js-file-line">         j += blocklen;</td>
      </tr>
      <tr>
        <td id="L910" class="blob-num js-line-number" data-line-number="910"></td>
        <td id="LC910" class="blob-code blob-code-inner js-file-line">         blocklen = <span class="pl-c1">5552</span>;</td>
      </tr>
      <tr>
        <td id="L911" class="blob-num js-line-number" data-line-number="911"></td>
        <td id="LC911" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L912" class="blob-num js-line-number" data-line-number="912"></td>
        <td id="LC912" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__sbpush</span>(out, <span class="pl-c1">STBIW_UCHAR</span>(s2 &gt;&gt; <span class="pl-c1">8</span>));</td>
      </tr>
      <tr>
        <td id="L913" class="blob-num js-line-number" data-line-number="913"></td>
        <td id="LC913" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__sbpush</span>(out, <span class="pl-c1">STBIW_UCHAR</span>(s2));</td>
      </tr>
      <tr>
        <td id="L914" class="blob-num js-line-number" data-line-number="914"></td>
        <td id="LC914" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__sbpush</span>(out, <span class="pl-c1">STBIW_UCHAR</span>(s1 &gt;&gt; <span class="pl-c1">8</span>));</td>
      </tr>
      <tr>
        <td id="L915" class="blob-num js-line-number" data-line-number="915"></td>
        <td id="LC915" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__sbpush</span>(out, <span class="pl-c1">STBIW_UCHAR</span>(s1));</td>
      </tr>
      <tr>
        <td id="L916" class="blob-num js-line-number" data-line-number="916"></td>
        <td id="LC916" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L917" class="blob-num js-line-number" data-line-number="917"></td>
        <td id="LC917" class="blob-code blob-code-inner js-file-line">   *out_len = <span class="pl-c1">stbiw__sbn</span>(out);</td>
      </tr>
      <tr>
        <td id="L918" class="blob-num js-line-number" data-line-number="918"></td>
        <td id="LC918" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> make returned pointer freeable</span></td>
      </tr>
      <tr>
        <td id="L919" class="blob-num js-line-number" data-line-number="919"></td>
        <td id="LC919" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_MEMMOVE</span>(<span class="pl-c1">stbiw__sbraw</span>(out), out, *out_len);</td>
      </tr>
      <tr>
        <td id="L920" class="blob-num js-line-number" data-line-number="920"></td>
        <td id="LC920" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> (<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *) <span class="pl-c1">stbiw__sbraw</span>(out);</td>
      </tr>
      <tr>
        <td id="L921" class="blob-num js-line-number" data-line-number="921"></td>
        <td id="LC921" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span> <span class="pl-c"><span class="pl-c">//</span> STBIW_ZLIB_COMPRESS</span></td>
      </tr>
      <tr>
        <td id="L922" class="blob-num js-line-number" data-line-number="922"></td>
        <td id="LC922" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L923" class="blob-num js-line-number" data-line-number="923"></td>
        <td id="LC923" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L924" class="blob-num js-line-number" data-line-number="924"></td>
        <td id="LC924" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">unsigned</span> <span class="pl-k">int</span> <span class="pl-en">stbiw__crc32</span>(<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *buffer, <span class="pl-k">int</span> len)</td>
      </tr>
      <tr>
        <td id="L925" class="blob-num js-line-number" data-line-number="925"></td>
        <td id="LC925" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L926" class="blob-num js-line-number" data-line-number="926"></td>
        <td id="LC926" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">unsigned</span> <span class="pl-k">int</span> crc_table[<span class="pl-c1">256</span>] =</td>
      </tr>
      <tr>
        <td id="L927" class="blob-num js-line-number" data-line-number="927"></td>
        <td id="LC927" class="blob-code blob-code-inner js-file-line">   {</td>
      </tr>
      <tr>
        <td id="L928" class="blob-num js-line-number" data-line-number="928"></td>
        <td id="LC928" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x00000000</span>, <span class="pl-c1">0x77073096</span>, <span class="pl-c1">0xEE0E612C</span>, <span class="pl-c1">0x990951BA</span>, <span class="pl-c1">0x076DC419</span>, <span class="pl-c1">0x706AF48F</span>, <span class="pl-c1">0xE963A535</span>, <span class="pl-c1">0x9E6495A3</span>,</td>
      </tr>
      <tr>
        <td id="L929" class="blob-num js-line-number" data-line-number="929"></td>
        <td id="LC929" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x0eDB8832</span>, <span class="pl-c1">0x79DCB8A4</span>, <span class="pl-c1">0xE0D5E91E</span>, <span class="pl-c1">0x97D2D988</span>, <span class="pl-c1">0x09B64C2B</span>, <span class="pl-c1">0x7EB17CBD</span>, <span class="pl-c1">0xE7B82D07</span>, <span class="pl-c1">0x90BF1D91</span>,</td>
      </tr>
      <tr>
        <td id="L930" class="blob-num js-line-number" data-line-number="930"></td>
        <td id="LC930" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x1DB71064</span>, <span class="pl-c1">0x6AB020F2</span>, <span class="pl-c1">0xF3B97148</span>, <span class="pl-c1">0x84BE41DE</span>, <span class="pl-c1">0x1ADAD47D</span>, <span class="pl-c1">0x6DDDE4EB</span>, <span class="pl-c1">0xF4D4B551</span>, <span class="pl-c1">0x83D385C7</span>,</td>
      </tr>
      <tr>
        <td id="L931" class="blob-num js-line-number" data-line-number="931"></td>
        <td id="LC931" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x136C9856</span>, <span class="pl-c1">0x646BA8C0</span>, <span class="pl-c1">0xFD62F97A</span>, <span class="pl-c1">0x8A65C9EC</span>, <span class="pl-c1">0x14015C4F</span>, <span class="pl-c1">0x63066CD9</span>, <span class="pl-c1">0xFA0F3D63</span>, <span class="pl-c1">0x8D080DF5</span>,</td>
      </tr>
      <tr>
        <td id="L932" class="blob-num js-line-number" data-line-number="932"></td>
        <td id="LC932" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x3B6E20C8</span>, <span class="pl-c1">0x4C69105E</span>, <span class="pl-c1">0xD56041E4</span>, <span class="pl-c1">0xA2677172</span>, <span class="pl-c1">0x3C03E4D1</span>, <span class="pl-c1">0x4B04D447</span>, <span class="pl-c1">0xD20D85FD</span>, <span class="pl-c1">0xA50AB56B</span>,</td>
      </tr>
      <tr>
        <td id="L933" class="blob-num js-line-number" data-line-number="933"></td>
        <td id="LC933" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x35B5A8FA</span>, <span class="pl-c1">0x42B2986C</span>, <span class="pl-c1">0xDBBBC9D6</span>, <span class="pl-c1">0xACBCF940</span>, <span class="pl-c1">0x32D86CE3</span>, <span class="pl-c1">0x45DF5C75</span>, <span class="pl-c1">0xDCD60DCF</span>, <span class="pl-c1">0xABD13D59</span>,</td>
      </tr>
      <tr>
        <td id="L934" class="blob-num js-line-number" data-line-number="934"></td>
        <td id="LC934" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x26D930AC</span>, <span class="pl-c1">0x51DE003A</span>, <span class="pl-c1">0xC8D75180</span>, <span class="pl-c1">0xBFD06116</span>, <span class="pl-c1">0x21B4F4B5</span>, <span class="pl-c1">0x56B3C423</span>, <span class="pl-c1">0xCFBA9599</span>, <span class="pl-c1">0xB8BDA50F</span>,</td>
      </tr>
      <tr>
        <td id="L935" class="blob-num js-line-number" data-line-number="935"></td>
        <td id="LC935" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x2802B89E</span>, <span class="pl-c1">0x5F058808</span>, <span class="pl-c1">0xC60CD9B2</span>, <span class="pl-c1">0xB10BE924</span>, <span class="pl-c1">0x2F6F7C87</span>, <span class="pl-c1">0x58684C11</span>, <span class="pl-c1">0xC1611DAB</span>, <span class="pl-c1">0xB6662D3D</span>,</td>
      </tr>
      <tr>
        <td id="L936" class="blob-num js-line-number" data-line-number="936"></td>
        <td id="LC936" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x76DC4190</span>, <span class="pl-c1">0x01DB7106</span>, <span class="pl-c1">0x98D220BC</span>, <span class="pl-c1">0xEFD5102A</span>, <span class="pl-c1">0x71B18589</span>, <span class="pl-c1">0x06B6B51F</span>, <span class="pl-c1">0x9FBFE4A5</span>, <span class="pl-c1">0xE8B8D433</span>,</td>
      </tr>
      <tr>
        <td id="L937" class="blob-num js-line-number" data-line-number="937"></td>
        <td id="LC937" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x7807C9A2</span>, <span class="pl-c1">0x0F00F934</span>, <span class="pl-c1">0x9609A88E</span>, <span class="pl-c1">0xE10E9818</span>, <span class="pl-c1">0x7F6A0DBB</span>, <span class="pl-c1">0x086D3D2D</span>, <span class="pl-c1">0x91646C97</span>, <span class="pl-c1">0xE6635C01</span>,</td>
      </tr>
      <tr>
        <td id="L938" class="blob-num js-line-number" data-line-number="938"></td>
        <td id="LC938" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x6B6B51F4</span>, <span class="pl-c1">0x1C6C6162</span>, <span class="pl-c1">0x856530D8</span>, <span class="pl-c1">0xF262004E</span>, <span class="pl-c1">0x6C0695ED</span>, <span class="pl-c1">0x1B01A57B</span>, <span class="pl-c1">0x8208F4C1</span>, <span class="pl-c1">0xF50FC457</span>,</td>
      </tr>
      <tr>
        <td id="L939" class="blob-num js-line-number" data-line-number="939"></td>
        <td id="LC939" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x65B0D9C6</span>, <span class="pl-c1">0x12B7E950</span>, <span class="pl-c1">0x8BBEB8EA</span>, <span class="pl-c1">0xFCB9887C</span>, <span class="pl-c1">0x62DD1DDF</span>, <span class="pl-c1">0x15DA2D49</span>, <span class="pl-c1">0x8CD37CF3</span>, <span class="pl-c1">0xFBD44C65</span>,</td>
      </tr>
      <tr>
        <td id="L940" class="blob-num js-line-number" data-line-number="940"></td>
        <td id="LC940" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x4DB26158</span>, <span class="pl-c1">0x3AB551CE</span>, <span class="pl-c1">0xA3BC0074</span>, <span class="pl-c1">0xD4BB30E2</span>, <span class="pl-c1">0x4ADFA541</span>, <span class="pl-c1">0x3DD895D7</span>, <span class="pl-c1">0xA4D1C46D</span>, <span class="pl-c1">0xD3D6F4FB</span>,</td>
      </tr>
      <tr>
        <td id="L941" class="blob-num js-line-number" data-line-number="941"></td>
        <td id="LC941" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x4369E96A</span>, <span class="pl-c1">0x346ED9FC</span>, <span class="pl-c1">0xAD678846</span>, <span class="pl-c1">0xDA60B8D0</span>, <span class="pl-c1">0x44042D73</span>, <span class="pl-c1">0x33031DE5</span>, <span class="pl-c1">0xAA0A4C5F</span>, <span class="pl-c1">0xDD0D7CC9</span>,</td>
      </tr>
      <tr>
        <td id="L942" class="blob-num js-line-number" data-line-number="942"></td>
        <td id="LC942" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x5005713C</span>, <span class="pl-c1">0x270241AA</span>, <span class="pl-c1">0xBE0B1010</span>, <span class="pl-c1">0xC90C2086</span>, <span class="pl-c1">0x5768B525</span>, <span class="pl-c1">0x206F85B3</span>, <span class="pl-c1">0xB966D409</span>, <span class="pl-c1">0xCE61E49F</span>,</td>
      </tr>
      <tr>
        <td id="L943" class="blob-num js-line-number" data-line-number="943"></td>
        <td id="LC943" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x5EDEF90E</span>, <span class="pl-c1">0x29D9C998</span>, <span class="pl-c1">0xB0D09822</span>, <span class="pl-c1">0xC7D7A8B4</span>, <span class="pl-c1">0x59B33D17</span>, <span class="pl-c1">0x2EB40D81</span>, <span class="pl-c1">0xB7BD5C3B</span>, <span class="pl-c1">0xC0BA6CAD</span>,</td>
      </tr>
      <tr>
        <td id="L944" class="blob-num js-line-number" data-line-number="944"></td>
        <td id="LC944" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xEDB88320</span>, <span class="pl-c1">0x9ABFB3B6</span>, <span class="pl-c1">0x03B6E20C</span>, <span class="pl-c1">0x74B1D29A</span>, <span class="pl-c1">0xEAD54739</span>, <span class="pl-c1">0x9DD277AF</span>, <span class="pl-c1">0x04DB2615</span>, <span class="pl-c1">0x73DC1683</span>,</td>
      </tr>
      <tr>
        <td id="L945" class="blob-num js-line-number" data-line-number="945"></td>
        <td id="LC945" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xE3630B12</span>, <span class="pl-c1">0x94643B84</span>, <span class="pl-c1">0x0D6D6A3E</span>, <span class="pl-c1">0x7A6A5AA8</span>, <span class="pl-c1">0xE40ECF0B</span>, <span class="pl-c1">0x9309FF9D</span>, <span class="pl-c1">0x0A00AE27</span>, <span class="pl-c1">0x7D079EB1</span>,</td>
      </tr>
      <tr>
        <td id="L946" class="blob-num js-line-number" data-line-number="946"></td>
        <td id="LC946" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xF00F9344</span>, <span class="pl-c1">0x8708A3D2</span>, <span class="pl-c1">0x1E01F268</span>, <span class="pl-c1">0x6906C2FE</span>, <span class="pl-c1">0xF762575D</span>, <span class="pl-c1">0x806567CB</span>, <span class="pl-c1">0x196C3671</span>, <span class="pl-c1">0x6E6B06E7</span>,</td>
      </tr>
      <tr>
        <td id="L947" class="blob-num js-line-number" data-line-number="947"></td>
        <td id="LC947" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xFED41B76</span>, <span class="pl-c1">0x89D32BE0</span>, <span class="pl-c1">0x10DA7A5A</span>, <span class="pl-c1">0x67DD4ACC</span>, <span class="pl-c1">0xF9B9DF6F</span>, <span class="pl-c1">0x8EBEEFF9</span>, <span class="pl-c1">0x17B7BE43</span>, <span class="pl-c1">0x60B08ED5</span>,</td>
      </tr>
      <tr>
        <td id="L948" class="blob-num js-line-number" data-line-number="948"></td>
        <td id="LC948" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xD6D6A3E8</span>, <span class="pl-c1">0xA1D1937E</span>, <span class="pl-c1">0x38D8C2C4</span>, <span class="pl-c1">0x4FDFF252</span>, <span class="pl-c1">0xD1BB67F1</span>, <span class="pl-c1">0xA6BC5767</span>, <span class="pl-c1">0x3FB506DD</span>, <span class="pl-c1">0x48B2364B</span>,</td>
      </tr>
      <tr>
        <td id="L949" class="blob-num js-line-number" data-line-number="949"></td>
        <td id="LC949" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xD80D2BDA</span>, <span class="pl-c1">0xAF0A1B4C</span>, <span class="pl-c1">0x36034AF6</span>, <span class="pl-c1">0x41047A60</span>, <span class="pl-c1">0xDF60EFC3</span>, <span class="pl-c1">0xA867DF55</span>, <span class="pl-c1">0x316E8EEF</span>, <span class="pl-c1">0x4669BE79</span>,</td>
      </tr>
      <tr>
        <td id="L950" class="blob-num js-line-number" data-line-number="950"></td>
        <td id="LC950" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xCB61B38C</span>, <span class="pl-c1">0xBC66831A</span>, <span class="pl-c1">0x256FD2A0</span>, <span class="pl-c1">0x5268E236</span>, <span class="pl-c1">0xCC0C7795</span>, <span class="pl-c1">0xBB0B4703</span>, <span class="pl-c1">0x220216B9</span>, <span class="pl-c1">0x5505262F</span>,</td>
      </tr>
      <tr>
        <td id="L951" class="blob-num js-line-number" data-line-number="951"></td>
        <td id="LC951" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xC5BA3BBE</span>, <span class="pl-c1">0xB2BD0B28</span>, <span class="pl-c1">0x2BB45A92</span>, <span class="pl-c1">0x5CB36A04</span>, <span class="pl-c1">0xC2D7FFA7</span>, <span class="pl-c1">0xB5D0CF31</span>, <span class="pl-c1">0x2CD99E8B</span>, <span class="pl-c1">0x5BDEAE1D</span>,</td>
      </tr>
      <tr>
        <td id="L952" class="blob-num js-line-number" data-line-number="952"></td>
        <td id="LC952" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x9B64C2B0</span>, <span class="pl-c1">0xEC63F226</span>, <span class="pl-c1">0x756AA39C</span>, <span class="pl-c1">0x026D930A</span>, <span class="pl-c1">0x9C0906A9</span>, <span class="pl-c1">0xEB0E363F</span>, <span class="pl-c1">0x72076785</span>, <span class="pl-c1">0x05005713</span>,</td>
      </tr>
      <tr>
        <td id="L953" class="blob-num js-line-number" data-line-number="953"></td>
        <td id="LC953" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x95BF4A82</span>, <span class="pl-c1">0xE2B87A14</span>, <span class="pl-c1">0x7BB12BAE</span>, <span class="pl-c1">0x0CB61B38</span>, <span class="pl-c1">0x92D28E9B</span>, <span class="pl-c1">0xE5D5BE0D</span>, <span class="pl-c1">0x7CDCEFB7</span>, <span class="pl-c1">0x0BDBDF21</span>,</td>
      </tr>
      <tr>
        <td id="L954" class="blob-num js-line-number" data-line-number="954"></td>
        <td id="LC954" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x86D3D2D4</span>, <span class="pl-c1">0xF1D4E242</span>, <span class="pl-c1">0x68DDB3F8</span>, <span class="pl-c1">0x1FDA836E</span>, <span class="pl-c1">0x81BE16CD</span>, <span class="pl-c1">0xF6B9265B</span>, <span class="pl-c1">0x6FB077E1</span>, <span class="pl-c1">0x18B74777</span>,</td>
      </tr>
      <tr>
        <td id="L955" class="blob-num js-line-number" data-line-number="955"></td>
        <td id="LC955" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x88085AE6</span>, <span class="pl-c1">0xFF0F6A70</span>, <span class="pl-c1">0x66063BCA</span>, <span class="pl-c1">0x11010B5C</span>, <span class="pl-c1">0x8F659EFF</span>, <span class="pl-c1">0xF862AE69</span>, <span class="pl-c1">0x616BFFD3</span>, <span class="pl-c1">0x166CCF45</span>,</td>
      </tr>
      <tr>
        <td id="L956" class="blob-num js-line-number" data-line-number="956"></td>
        <td id="LC956" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xA00AE278</span>, <span class="pl-c1">0xD70DD2EE</span>, <span class="pl-c1">0x4E048354</span>, <span class="pl-c1">0x3903B3C2</span>, <span class="pl-c1">0xA7672661</span>, <span class="pl-c1">0xD06016F7</span>, <span class="pl-c1">0x4969474D</span>, <span class="pl-c1">0x3E6E77DB</span>,</td>
      </tr>
      <tr>
        <td id="L957" class="blob-num js-line-number" data-line-number="957"></td>
        <td id="LC957" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xAED16A4A</span>, <span class="pl-c1">0xD9D65ADC</span>, <span class="pl-c1">0x40DF0B66</span>, <span class="pl-c1">0x37D83BF0</span>, <span class="pl-c1">0xA9BCAE53</span>, <span class="pl-c1">0xDEBB9EC5</span>, <span class="pl-c1">0x47B2CF7F</span>, <span class="pl-c1">0x30B5FFE9</span>,</td>
      </tr>
      <tr>
        <td id="L958" class="blob-num js-line-number" data-line-number="958"></td>
        <td id="LC958" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xBDBDF21C</span>, <span class="pl-c1">0xCABAC28A</span>, <span class="pl-c1">0x53B39330</span>, <span class="pl-c1">0x24B4A3A6</span>, <span class="pl-c1">0xBAD03605</span>, <span class="pl-c1">0xCDD70693</span>, <span class="pl-c1">0x54DE5729</span>, <span class="pl-c1">0x23D967BF</span>,</td>
      </tr>
      <tr>
        <td id="L959" class="blob-num js-line-number" data-line-number="959"></td>
        <td id="LC959" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xB3667A2E</span>, <span class="pl-c1">0xC4614AB8</span>, <span class="pl-c1">0x5D681B02</span>, <span class="pl-c1">0x2A6F2B94</span>, <span class="pl-c1">0xB40BBE37</span>, <span class="pl-c1">0xC30C8EA1</span>, <span class="pl-c1">0x5A05DF1B</span>, <span class="pl-c1">0x2D02EF8D</span></td>
      </tr>
      <tr>
        <td id="L960" class="blob-num js-line-number" data-line-number="960"></td>
        <td id="LC960" class="blob-code blob-code-inner js-file-line">   };</td>
      </tr>
      <tr>
        <td id="L961" class="blob-num js-line-number" data-line-number="961"></td>
        <td id="LC961" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L962" class="blob-num js-line-number" data-line-number="962"></td>
        <td id="LC962" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">int</span> crc = ~<span class="pl-c1">0u</span>;</td>
      </tr>
      <tr>
        <td id="L963" class="blob-num js-line-number" data-line-number="963"></td>
        <td id="LC963" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> i;</td>
      </tr>
      <tr>
        <td id="L964" class="blob-num js-line-number" data-line-number="964"></td>
        <td id="LC964" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span> (i=<span class="pl-c1">0</span>; i &lt; len; ++i)</td>
      </tr>
      <tr>
        <td id="L965" class="blob-num js-line-number" data-line-number="965"></td>
        <td id="LC965" class="blob-code blob-code-inner js-file-line">      crc = (crc &gt;&gt; <span class="pl-c1">8</span>) ^ crc_table[buffer[i] ^ (crc &amp; <span class="pl-c1">0xff</span>)];</td>
      </tr>
      <tr>
        <td id="L966" class="blob-num js-line-number" data-line-number="966"></td>
        <td id="LC966" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> ~crc;</td>
      </tr>
      <tr>
        <td id="L967" class="blob-num js-line-number" data-line-number="967"></td>
        <td id="LC967" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L968" class="blob-num js-line-number" data-line-number="968"></td>
        <td id="LC968" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L969" class="blob-num js-line-number" data-line-number="969"></td>
        <td id="LC969" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__wpng4</span>(<span class="pl-v">o,a,b,c,d</span>) ((o)[<span class="pl-c1">0</span>]=STBIW_UCHAR(a),(o)[<span class="pl-c1">1</span>]=STBIW_UCHAR(b),(o)[<span class="pl-c1">2</span>]=STBIW_UCHAR(c),(o)[<span class="pl-c1">3</span>]=STBIW_UCHAR(d),(o)+=<span class="pl-c1">4</span>)</td>
      </tr>
      <tr>
        <td id="L970" class="blob-num js-line-number" data-line-number="970"></td>
        <td id="LC970" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__wp32</span>(<span class="pl-v">data,v</span>) stbiw__wpng4(data, (v)&gt;&gt;<span class="pl-c1">24</span>,(v)&gt;&gt;<span class="pl-c1">16</span>,(v)&gt;&gt;<span class="pl-c1">8</span>,(v));</td>
      </tr>
      <tr>
        <td id="L971" class="blob-num js-line-number" data-line-number="971"></td>
        <td id="LC971" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">define</span> <span class="pl-en">stbiw__wptag</span>(<span class="pl-v">data,s</span>) stbiw__wpng4(data, s[<span class="pl-c1">0</span>],s[<span class="pl-c1">1</span>],s[<span class="pl-c1">2</span>],s[<span class="pl-c1">3</span>])</td>
      </tr>
      <tr>
        <td id="L972" class="blob-num js-line-number" data-line-number="972"></td>
        <td id="LC972" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L973" class="blob-num js-line-number" data-line-number="973"></td>
        <td id="LC973" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__wpcrc</span>(<span class="pl-k">unsigned</span> <span class="pl-k">char</span> **data, <span class="pl-k">int</span> len)</td>
      </tr>
      <tr>
        <td id="L974" class="blob-num js-line-number" data-line-number="974"></td>
        <td id="LC974" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L975" class="blob-num js-line-number" data-line-number="975"></td>
        <td id="LC975" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">int</span> crc = <span class="pl-c1">stbiw__crc32</span>(*data - len - <span class="pl-c1">4</span>, len+<span class="pl-c1">4</span>);</td>
      </tr>
      <tr>
        <td id="L976" class="blob-num js-line-number" data-line-number="976"></td>
        <td id="LC976" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wp32</span>(*data, crc);</td>
      </tr>
      <tr>
        <td id="L977" class="blob-num js-line-number" data-line-number="977"></td>
        <td id="LC977" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L978" class="blob-num js-line-number" data-line-number="978"></td>
        <td id="LC978" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L979" class="blob-num js-line-number" data-line-number="979"></td>
        <td id="LC979" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> <span class="pl-en">stbiw__paeth</span>(<span class="pl-k">int</span> a, <span class="pl-k">int</span> b, <span class="pl-k">int</span> c)</td>
      </tr>
      <tr>
        <td id="L980" class="blob-num js-line-number" data-line-number="980"></td>
        <td id="LC980" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L981" class="blob-num js-line-number" data-line-number="981"></td>
        <td id="LC981" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> p = a + b - c, pa = <span class="pl-c1">abs</span>(p-a), pb = <span class="pl-c1">abs</span>(p-b), pc = <span class="pl-c1">abs</span>(p-c);</td>
      </tr>
      <tr>
        <td id="L982" class="blob-num js-line-number" data-line-number="982"></td>
        <td id="LC982" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (pa &lt;= pb &amp;&amp; pa &lt;= pc) <span class="pl-k">return</span> <span class="pl-c1">STBIW_UCHAR</span>(a);</td>
      </tr>
      <tr>
        <td id="L983" class="blob-num js-line-number" data-line-number="983"></td>
        <td id="LC983" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (pb &lt;= pc) <span class="pl-k">return</span> <span class="pl-c1">STBIW_UCHAR</span>(b);</td>
      </tr>
      <tr>
        <td id="L984" class="blob-num js-line-number" data-line-number="984"></td>
        <td id="LC984" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">STBIW_UCHAR</span>(c);</td>
      </tr>
      <tr>
        <td id="L985" class="blob-num js-line-number" data-line-number="985"></td>
        <td id="LC985" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L986" class="blob-num js-line-number" data-line-number="986"></td>
        <td id="LC986" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L987" class="blob-num js-line-number" data-line-number="987"></td>
        <td id="LC987" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">//</span> @OPTIMIZE: provide an option that always forces left-predict or paeth predict</span></td>
      </tr>
      <tr>
        <td id="L988" class="blob-num js-line-number" data-line-number="988"></td>
        <td id="LC988" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__encode_png_line</span>(<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *pixels, <span class="pl-k">int</span> stride_bytes, <span class="pl-k">int</span> width, <span class="pl-k">int</span> height, <span class="pl-k">int</span> y, <span class="pl-k">int</span> n, <span class="pl-k">int</span> filter_type, <span class="pl-k">signed</span> <span class="pl-k">char</span> *line_buffer)</td>
      </tr>
      <tr>
        <td id="L989" class="blob-num js-line-number" data-line-number="989"></td>
        <td id="LC989" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L990" class="blob-num js-line-number" data-line-number="990"></td>
        <td id="LC990" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">int</span> mapping[] = { <span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">2</span>,<span class="pl-c1">3</span>,<span class="pl-c1">4</span> };</td>
      </tr>
      <tr>
        <td id="L991" class="blob-num js-line-number" data-line-number="991"></td>
        <td id="LC991" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">int</span> firstmap[] = { <span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">0</span>,<span class="pl-c1">5</span>,<span class="pl-c1">6</span> };</td>
      </tr>
      <tr>
        <td id="L992" class="blob-num js-line-number" data-line-number="992"></td>
        <td id="LC992" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> *mymap = (y != <span class="pl-c1">0</span>) ? mapping : firstmap;</td>
      </tr>
      <tr>
        <td id="L993" class="blob-num js-line-number" data-line-number="993"></td>
        <td id="LC993" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> i;</td>
      </tr>
      <tr>
        <td id="L994" class="blob-num js-line-number" data-line-number="994"></td>
        <td id="LC994" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> type = mymap[filter_type];</td>
      </tr>
      <tr>
        <td id="L995" class="blob-num js-line-number" data-line-number="995"></td>
        <td id="LC995" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *z = pixels + stride_bytes * (stbi__flip_vertically_on_write ? height-<span class="pl-c1">1</span>-y : y);</td>
      </tr>
      <tr>
        <td id="L996" class="blob-num js-line-number" data-line-number="996"></td>
        <td id="LC996" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> signed_stride = stbi__flip_vertically_on_write ? -stride_bytes : stride_bytes;</td>
      </tr>
      <tr>
        <td id="L997" class="blob-num js-line-number" data-line-number="997"></td>
        <td id="LC997" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span> (i = <span class="pl-c1">0</span>; i &lt; n; ++i) {</td>
      </tr>
      <tr>
        <td id="L998" class="blob-num js-line-number" data-line-number="998"></td>
        <td id="LC998" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">switch</span> (type) {</td>
      </tr>
      <tr>
        <td id="L999" class="blob-num js-line-number" data-line-number="999"></td>
        <td id="LC999" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">0</span>: line_buffer[i] = z[i]; <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1000" class="blob-num js-line-number" data-line-number="1000"></td>
        <td id="LC1000" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">1</span>: line_buffer[i] = z[i]; <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1001" class="blob-num js-line-number" data-line-number="1001"></td>
        <td id="LC1001" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">2</span>: line_buffer[i] = z[i] - z[i-signed_stride]; <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1002" class="blob-num js-line-number" data-line-number="1002"></td>
        <td id="LC1002" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">3</span>: line_buffer[i] = z[i] - (z[i-signed_stride]&gt;&gt;<span class="pl-c1">1</span>); <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1003" class="blob-num js-line-number" data-line-number="1003"></td>
        <td id="LC1003" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">4</span>: line_buffer[i] = (<span class="pl-k">signed</span> <span class="pl-k">char</span>) (z[i] - <span class="pl-c1">stbiw__paeth</span>(<span class="pl-c1">0</span>,z[i-signed_stride],<span class="pl-c1">0</span>)); <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1004" class="blob-num js-line-number" data-line-number="1004"></td>
        <td id="LC1004" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">5</span>: line_buffer[i] = z[i]; <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1005" class="blob-num js-line-number" data-line-number="1005"></td>
        <td id="LC1005" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">6</span>: line_buffer[i] = z[i]; <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1006" class="blob-num js-line-number" data-line-number="1006"></td>
        <td id="LC1006" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1007" class="blob-num js-line-number" data-line-number="1007"></td>
        <td id="LC1007" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1008" class="blob-num js-line-number" data-line-number="1008"></td>
        <td id="LC1008" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span> (i=n; i &lt; width*n; ++i) {</td>
      </tr>
      <tr>
        <td id="L1009" class="blob-num js-line-number" data-line-number="1009"></td>
        <td id="LC1009" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">switch</span> (type) {</td>
      </tr>
      <tr>
        <td id="L1010" class="blob-num js-line-number" data-line-number="1010"></td>
        <td id="LC1010" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">0</span>: line_buffer[i] = z[i]; <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1011" class="blob-num js-line-number" data-line-number="1011"></td>
        <td id="LC1011" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">1</span>: line_buffer[i] = z[i] - z[i-n]; <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1012" class="blob-num js-line-number" data-line-number="1012"></td>
        <td id="LC1012" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">2</span>: line_buffer[i] = z[i] - z[i-signed_stride]; <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1013" class="blob-num js-line-number" data-line-number="1013"></td>
        <td id="LC1013" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">3</span>: line_buffer[i] = z[i] - ((z[i-n] + z[i-signed_stride])&gt;&gt;<span class="pl-c1">1</span>); <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1014" class="blob-num js-line-number" data-line-number="1014"></td>
        <td id="LC1014" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">4</span>: line_buffer[i] = z[i] - <span class="pl-c1">stbiw__paeth</span>(z[i-n], z[i-signed_stride], z[i-signed_stride-n]); <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1015" class="blob-num js-line-number" data-line-number="1015"></td>
        <td id="LC1015" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">5</span>: line_buffer[i] = z[i] - (z[i-n]&gt;&gt;<span class="pl-c1">1</span>); <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1016" class="blob-num js-line-number" data-line-number="1016"></td>
        <td id="LC1016" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">case</span> <span class="pl-c1">6</span>: line_buffer[i] = z[i] - <span class="pl-c1">stbiw__paeth</span>(z[i-n], <span class="pl-c1">0</span>,<span class="pl-c1">0</span>); <span class="pl-k">break</span>;</td>
      </tr>
      <tr>
        <td id="L1017" class="blob-num js-line-number" data-line-number="1017"></td>
        <td id="LC1017" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1018" class="blob-num js-line-number" data-line-number="1018"></td>
        <td id="LC1018" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1019" class="blob-num js-line-number" data-line-number="1019"></td>
        <td id="LC1019" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1020" class="blob-num js-line-number" data-line-number="1020"></td>
        <td id="LC1020" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1021" class="blob-num js-line-number" data-line-number="1021"></td>
        <td id="LC1021" class="blob-code blob-code-inner js-file-line"><span class="pl-k">unsigned</span> <span class="pl-k">char</span> *<span class="pl-en">stbi_write_png_to_mem</span>(<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *pixels, <span class="pl-k">int</span> stride_bytes, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> n, <span class="pl-k">int</span> *out_len)</td>
      </tr>
      <tr>
        <td id="L1022" class="blob-num js-line-number" data-line-number="1022"></td>
        <td id="LC1022" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L1023" class="blob-num js-line-number" data-line-number="1023"></td>
        <td id="LC1023" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> force_filter = stbi_write_force_png_filter;</td>
      </tr>
      <tr>
        <td id="L1024" class="blob-num js-line-number" data-line-number="1024"></td>
        <td id="LC1024" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> ctype[<span class="pl-c1">5</span>] = { -<span class="pl-c1">1</span>, <span class="pl-c1">0</span>, <span class="pl-c1">4</span>, <span class="pl-c1">2</span>, <span class="pl-c1">6</span> };</td>
      </tr>
      <tr>
        <td id="L1025" class="blob-num js-line-number" data-line-number="1025"></td>
        <td id="LC1025" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> sig[<span class="pl-c1">8</span>] = { <span class="pl-c1">137</span>,<span class="pl-c1">80</span>,<span class="pl-c1">78</span>,<span class="pl-c1">71</span>,<span class="pl-c1">13</span>,<span class="pl-c1">10</span>,<span class="pl-c1">26</span>,<span class="pl-c1">10</span> };</td>
      </tr>
      <tr>
        <td id="L1026" class="blob-num js-line-number" data-line-number="1026"></td>
        <td id="LC1026" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *out,*o, *filt, *zlib;</td>
      </tr>
      <tr>
        <td id="L1027" class="blob-num js-line-number" data-line-number="1027"></td>
        <td id="LC1027" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">signed</span> <span class="pl-k">char</span> *line_buffer;</td>
      </tr>
      <tr>
        <td id="L1028" class="blob-num js-line-number" data-line-number="1028"></td>
        <td id="LC1028" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> j,zlen;</td>
      </tr>
      <tr>
        <td id="L1029" class="blob-num js-line-number" data-line-number="1029"></td>
        <td id="LC1029" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1030" class="blob-num js-line-number" data-line-number="1030"></td>
        <td id="LC1030" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (stride_bytes == <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L1031" class="blob-num js-line-number" data-line-number="1031"></td>
        <td id="LC1031" class="blob-code blob-code-inner js-file-line">      stride_bytes = x * n;</td>
      </tr>
      <tr>
        <td id="L1032" class="blob-num js-line-number" data-line-number="1032"></td>
        <td id="LC1032" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1033" class="blob-num js-line-number" data-line-number="1033"></td>
        <td id="LC1033" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (force_filter &gt;= <span class="pl-c1">5</span>) {</td>
      </tr>
      <tr>
        <td id="L1034" class="blob-num js-line-number" data-line-number="1034"></td>
        <td id="LC1034" class="blob-code blob-code-inner js-file-line">      force_filter = -<span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1035" class="blob-num js-line-number" data-line-number="1035"></td>
        <td id="LC1035" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1036" class="blob-num js-line-number" data-line-number="1036"></td>
        <td id="LC1036" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1037" class="blob-num js-line-number" data-line-number="1037"></td>
        <td id="LC1037" class="blob-code blob-code-inner js-file-line">   filt = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *) <span class="pl-c1">STBIW_MALLOC</span>((x*n+<span class="pl-c1">1</span>) * y); <span class="pl-k">if</span> (!filt) <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1038" class="blob-num js-line-number" data-line-number="1038"></td>
        <td id="LC1038" class="blob-code blob-code-inner js-file-line">   line_buffer = (<span class="pl-k">signed</span> <span class="pl-k">char</span> *) <span class="pl-c1">STBIW_MALLOC</span>(x * n); <span class="pl-k">if</span> (!line_buffer) { <span class="pl-c1">STBIW_FREE</span>(filt); <span class="pl-k">return</span> <span class="pl-c1">0</span>; }</td>
      </tr>
      <tr>
        <td id="L1039" class="blob-num js-line-number" data-line-number="1039"></td>
        <td id="LC1039" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span> (j=<span class="pl-c1">0</span>; j &lt; y; ++j) {</td>
      </tr>
      <tr>
        <td id="L1040" class="blob-num js-line-number" data-line-number="1040"></td>
        <td id="LC1040" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> filter_type;</td>
      </tr>
      <tr>
        <td id="L1041" class="blob-num js-line-number" data-line-number="1041"></td>
        <td id="LC1041" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> (force_filter &gt; -<span class="pl-c1">1</span>) {</td>
      </tr>
      <tr>
        <td id="L1042" class="blob-num js-line-number" data-line-number="1042"></td>
        <td id="LC1042" class="blob-code blob-code-inner js-file-line">         filter_type = force_filter;</td>
      </tr>
      <tr>
        <td id="L1043" class="blob-num js-line-number" data-line-number="1043"></td>
        <td id="LC1043" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__encode_png_line</span>(pixels, stride_bytes, x, y, j, n, force_filter, line_buffer);</td>
      </tr>
      <tr>
        <td id="L1044" class="blob-num js-line-number" data-line-number="1044"></td>
        <td id="LC1044" class="blob-code blob-code-inner js-file-line">      } <span class="pl-k">else</span> { <span class="pl-c"><span class="pl-c">//</span> Estimate the best filter by running through all of them:</span></td>
      </tr>
      <tr>
        <td id="L1045" class="blob-num js-line-number" data-line-number="1045"></td>
        <td id="LC1045" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">int</span> best_filter = <span class="pl-c1">0</span>, best_filter_val = <span class="pl-c1">0x7fffffff</span>, est, i;</td>
      </tr>
      <tr>
        <td id="L1046" class="blob-num js-line-number" data-line-number="1046"></td>
        <td id="LC1046" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">for</span> (filter_type = <span class="pl-c1">0</span>; filter_type &lt; <span class="pl-c1">5</span>; filter_type++) {</td>
      </tr>
      <tr>
        <td id="L1047" class="blob-num js-line-number" data-line-number="1047"></td>
        <td id="LC1047" class="blob-code blob-code-inner js-file-line">            <span class="pl-c1">stbiw__encode_png_line</span>(pixels, stride_bytes, x, y, j, n, filter_type, line_buffer);</td>
      </tr>
      <tr>
        <td id="L1048" class="blob-num js-line-number" data-line-number="1048"></td>
        <td id="LC1048" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1049" class="blob-num js-line-number" data-line-number="1049"></td>
        <td id="LC1049" class="blob-code blob-code-inner js-file-line">            <span class="pl-c"><span class="pl-c">//</span> Estimate the entropy of the line using this filter; the less, the better.</span></td>
      </tr>
      <tr>
        <td id="L1050" class="blob-num js-line-number" data-line-number="1050"></td>
        <td id="LC1050" class="blob-code blob-code-inner js-file-line">            est = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1051" class="blob-num js-line-number" data-line-number="1051"></td>
        <td id="LC1051" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">for</span> (i = <span class="pl-c1">0</span>; i &lt; x*n; ++i) {</td>
      </tr>
      <tr>
        <td id="L1052" class="blob-num js-line-number" data-line-number="1052"></td>
        <td id="LC1052" class="blob-code blob-code-inner js-file-line">               est += <span class="pl-c1">abs</span>((<span class="pl-k">signed</span> <span class="pl-k">char</span>) line_buffer[i]);</td>
      </tr>
      <tr>
        <td id="L1053" class="blob-num js-line-number" data-line-number="1053"></td>
        <td id="LC1053" class="blob-code blob-code-inner js-file-line">            }</td>
      </tr>
      <tr>
        <td id="L1054" class="blob-num js-line-number" data-line-number="1054"></td>
        <td id="LC1054" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">if</span> (est &lt; best_filter_val) {</td>
      </tr>
      <tr>
        <td id="L1055" class="blob-num js-line-number" data-line-number="1055"></td>
        <td id="LC1055" class="blob-code blob-code-inner js-file-line">               best_filter_val = est;</td>
      </tr>
      <tr>
        <td id="L1056" class="blob-num js-line-number" data-line-number="1056"></td>
        <td id="LC1056" class="blob-code blob-code-inner js-file-line">               best_filter = filter_type;</td>
      </tr>
      <tr>
        <td id="L1057" class="blob-num js-line-number" data-line-number="1057"></td>
        <td id="LC1057" class="blob-code blob-code-inner js-file-line">            }</td>
      </tr>
      <tr>
        <td id="L1058" class="blob-num js-line-number" data-line-number="1058"></td>
        <td id="LC1058" class="blob-code blob-code-inner js-file-line">         }</td>
      </tr>
      <tr>
        <td id="L1059" class="blob-num js-line-number" data-line-number="1059"></td>
        <td id="LC1059" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">if</span> (filter_type != best_filter) {  <span class="pl-c"><span class="pl-c">//</span> If the last iteration already got us the best filter, don&#39;t redo it</span></td>
      </tr>
      <tr>
        <td id="L1060" class="blob-num js-line-number" data-line-number="1060"></td>
        <td id="LC1060" class="blob-code blob-code-inner js-file-line">            <span class="pl-c1">stbiw__encode_png_line</span>(pixels, stride_bytes, x, y, j, n, best_filter, line_buffer);</td>
      </tr>
      <tr>
        <td id="L1061" class="blob-num js-line-number" data-line-number="1061"></td>
        <td id="LC1061" class="blob-code blob-code-inner js-file-line">            filter_type = best_filter;</td>
      </tr>
      <tr>
        <td id="L1062" class="blob-num js-line-number" data-line-number="1062"></td>
        <td id="LC1062" class="blob-code blob-code-inner js-file-line">         }</td>
      </tr>
      <tr>
        <td id="L1063" class="blob-num js-line-number" data-line-number="1063"></td>
        <td id="LC1063" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1064" class="blob-num js-line-number" data-line-number="1064"></td>
        <td id="LC1064" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> when we get here, filter_type contains the filter type, and line_buffer contains the data</span></td>
      </tr>
      <tr>
        <td id="L1065" class="blob-num js-line-number" data-line-number="1065"></td>
        <td id="LC1065" class="blob-code blob-code-inner js-file-line">      filt[j*(x*n+<span class="pl-c1">1</span>)] = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span>) filter_type;</td>
      </tr>
      <tr>
        <td id="L1066" class="blob-num js-line-number" data-line-number="1066"></td>
        <td id="LC1066" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">STBIW_MEMMOVE</span>(filt+j*(x*n+<span class="pl-c1">1</span>)+<span class="pl-c1">1</span>, line_buffer, x*n);</td>
      </tr>
      <tr>
        <td id="L1067" class="blob-num js-line-number" data-line-number="1067"></td>
        <td id="LC1067" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1068" class="blob-num js-line-number" data-line-number="1068"></td>
        <td id="LC1068" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_FREE</span>(line_buffer);</td>
      </tr>
      <tr>
        <td id="L1069" class="blob-num js-line-number" data-line-number="1069"></td>
        <td id="LC1069" class="blob-code blob-code-inner js-file-line">   zlib = <span class="pl-c1">stbi_zlib_compress</span>(filt, y*( x*n+<span class="pl-c1">1</span>), &amp;zlen, stbi_write_png_compression_level);</td>
      </tr>
      <tr>
        <td id="L1070" class="blob-num js-line-number" data-line-number="1070"></td>
        <td id="LC1070" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_FREE</span>(filt);</td>
      </tr>
      <tr>
        <td id="L1071" class="blob-num js-line-number" data-line-number="1071"></td>
        <td id="LC1071" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (!zlib) <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1072" class="blob-num js-line-number" data-line-number="1072"></td>
        <td id="LC1072" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1073" class="blob-num js-line-number" data-line-number="1073"></td>
        <td id="LC1073" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> each tag requires 12 bytes of overhead</span></td>
      </tr>
      <tr>
        <td id="L1074" class="blob-num js-line-number" data-line-number="1074"></td>
        <td id="LC1074" class="blob-code blob-code-inner js-file-line">   out = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *) <span class="pl-c1">STBIW_MALLOC</span>(<span class="pl-c1">8</span> + <span class="pl-c1">12</span>+<span class="pl-c1">13</span> + <span class="pl-c1">12</span>+zlen + <span class="pl-c1">12</span>);</td>
      </tr>
      <tr>
        <td id="L1075" class="blob-num js-line-number" data-line-number="1075"></td>
        <td id="LC1075" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (!out) <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1076" class="blob-num js-line-number" data-line-number="1076"></td>
        <td id="LC1076" class="blob-code blob-code-inner js-file-line">   *out_len = <span class="pl-c1">8</span> + <span class="pl-c1">12</span>+<span class="pl-c1">13</span> + <span class="pl-c1">12</span>+zlen + <span class="pl-c1">12</span>;</td>
      </tr>
      <tr>
        <td id="L1077" class="blob-num js-line-number" data-line-number="1077"></td>
        <td id="LC1077" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1078" class="blob-num js-line-number" data-line-number="1078"></td>
        <td id="LC1078" class="blob-code blob-code-inner js-file-line">   o=out;</td>
      </tr>
      <tr>
        <td id="L1079" class="blob-num js-line-number" data-line-number="1079"></td>
        <td id="LC1079" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_MEMMOVE</span>(o,sig,<span class="pl-c1">8</span>); o+= <span class="pl-c1">8</span>;</td>
      </tr>
      <tr>
        <td id="L1080" class="blob-num js-line-number" data-line-number="1080"></td>
        <td id="LC1080" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wp32</span>(o, <span class="pl-c1">13</span>); <span class="pl-c"><span class="pl-c">//</span> header length</span></td>
      </tr>
      <tr>
        <td id="L1081" class="blob-num js-line-number" data-line-number="1081"></td>
        <td id="LC1081" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wptag</span>(o, <span class="pl-s"><span class="pl-pds">&quot;</span>IHDR<span class="pl-pds">&quot;</span></span>);</td>
      </tr>
      <tr>
        <td id="L1082" class="blob-num js-line-number" data-line-number="1082"></td>
        <td id="LC1082" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wp32</span>(o, x);</td>
      </tr>
      <tr>
        <td id="L1083" class="blob-num js-line-number" data-line-number="1083"></td>
        <td id="LC1083" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wp32</span>(o, y);</td>
      </tr>
      <tr>
        <td id="L1084" class="blob-num js-line-number" data-line-number="1084"></td>
        <td id="LC1084" class="blob-code blob-code-inner js-file-line">   *o++ = <span class="pl-c1">8</span>;</td>
      </tr>
      <tr>
        <td id="L1085" class="blob-num js-line-number" data-line-number="1085"></td>
        <td id="LC1085" class="blob-code blob-code-inner js-file-line">   *o++ = <span class="pl-c1">STBIW_UCHAR</span>(ctype[n]);</td>
      </tr>
      <tr>
        <td id="L1086" class="blob-num js-line-number" data-line-number="1086"></td>
        <td id="LC1086" class="blob-code blob-code-inner js-file-line">   *o++ = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1087" class="blob-num js-line-number" data-line-number="1087"></td>
        <td id="LC1087" class="blob-code blob-code-inner js-file-line">   *o++ = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1088" class="blob-num js-line-number" data-line-number="1088"></td>
        <td id="LC1088" class="blob-code blob-code-inner js-file-line">   *o++ = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1089" class="blob-num js-line-number" data-line-number="1089"></td>
        <td id="LC1089" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wpcrc</span>(&amp;o,<span class="pl-c1">13</span>);</td>
      </tr>
      <tr>
        <td id="L1090" class="blob-num js-line-number" data-line-number="1090"></td>
        <td id="LC1090" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1091" class="blob-num js-line-number" data-line-number="1091"></td>
        <td id="LC1091" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wp32</span>(o, zlen);</td>
      </tr>
      <tr>
        <td id="L1092" class="blob-num js-line-number" data-line-number="1092"></td>
        <td id="LC1092" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wptag</span>(o, <span class="pl-s"><span class="pl-pds">&quot;</span>IDAT<span class="pl-pds">&quot;</span></span>);</td>
      </tr>
      <tr>
        <td id="L1093" class="blob-num js-line-number" data-line-number="1093"></td>
        <td id="LC1093" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_MEMMOVE</span>(o, zlib, zlen);</td>
      </tr>
      <tr>
        <td id="L1094" class="blob-num js-line-number" data-line-number="1094"></td>
        <td id="LC1094" class="blob-code blob-code-inner js-file-line">   o += zlen;</td>
      </tr>
      <tr>
        <td id="L1095" class="blob-num js-line-number" data-line-number="1095"></td>
        <td id="LC1095" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_FREE</span>(zlib);</td>
      </tr>
      <tr>
        <td id="L1096" class="blob-num js-line-number" data-line-number="1096"></td>
        <td id="LC1096" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wpcrc</span>(&amp;o, zlen);</td>
      </tr>
      <tr>
        <td id="L1097" class="blob-num js-line-number" data-line-number="1097"></td>
        <td id="LC1097" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1098" class="blob-num js-line-number" data-line-number="1098"></td>
        <td id="LC1098" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wp32</span>(o,<span class="pl-c1">0</span>);</td>
      </tr>
      <tr>
        <td id="L1099" class="blob-num js-line-number" data-line-number="1099"></td>
        <td id="LC1099" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wptag</span>(o, <span class="pl-s"><span class="pl-pds">&quot;</span>IEND<span class="pl-pds">&quot;</span></span>);</td>
      </tr>
      <tr>
        <td id="L1100" class="blob-num js-line-number" data-line-number="1100"></td>
        <td id="LC1100" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__wpcrc</span>(&amp;o,<span class="pl-c1">0</span>);</td>
      </tr>
      <tr>
        <td id="L1101" class="blob-num js-line-number" data-line-number="1101"></td>
        <td id="LC1101" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1102" class="blob-num js-line-number" data-line-number="1102"></td>
        <td id="LC1102" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_ASSERT</span>(o == out + *out_len);</td>
      </tr>
      <tr>
        <td id="L1103" class="blob-num js-line-number" data-line-number="1103"></td>
        <td id="LC1103" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1104" class="blob-num js-line-number" data-line-number="1104"></td>
        <td id="LC1104" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> out;</td>
      </tr>
      <tr>
        <td id="L1105" class="blob-num js-line-number" data-line-number="1105"></td>
        <td id="LC1105" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1106" class="blob-num js-line-number" data-line-number="1106"></td>
        <td id="LC1106" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1107" class="blob-num js-line-number" data-line-number="1107"></td>
        <td id="LC1107" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBI_WRITE_NO_STDIO</td>
      </tr>
      <tr>
        <td id="L1108" class="blob-num js-line-number" data-line-number="1108"></td>
        <td id="LC1108" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_png</span>(<span class="pl-k">char</span> <span class="pl-k">const</span> *filename, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span> *data, <span class="pl-k">int</span> stride_bytes)</td>
      </tr>
      <tr>
        <td id="L1109" class="blob-num js-line-number" data-line-number="1109"></td>
        <td id="LC1109" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L1110" class="blob-num js-line-number" data-line-number="1110"></td>
        <td id="LC1110" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">FILE</span> *f;</td>
      </tr>
      <tr>
        <td id="L1111" class="blob-num js-line-number" data-line-number="1111"></td>
        <td id="LC1111" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> len;</td>
      </tr>
      <tr>
        <td id="L1112" class="blob-num js-line-number" data-line-number="1112"></td>
        <td id="LC1112" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *png = <span class="pl-c1">stbi_write_png_to_mem</span>((<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *) data, stride_bytes, x, y, comp, &amp;len);</td>
      </tr>
      <tr>
        <td id="L1113" class="blob-num js-line-number" data-line-number="1113"></td>
        <td id="LC1113" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (png == <span class="pl-c1">NULL</span>) <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1114" class="blob-num js-line-number" data-line-number="1114"></td>
        <td id="LC1114" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifdef</span> STBI_MSC_SECURE_CRT</td>
      </tr>
      <tr>
        <td id="L1115" class="blob-num js-line-number" data-line-number="1115"></td>
        <td id="LC1115" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (<span class="pl-c1">fopen_s</span>(&amp;f, filename, <span class="pl-s"><span class="pl-pds">&quot;</span>wb<span class="pl-pds">&quot;</span></span>))</td>
      </tr>
      <tr>
        <td id="L1116" class="blob-num js-line-number" data-line-number="1116"></td>
        <td id="LC1116" class="blob-code blob-code-inner js-file-line">      f = <span class="pl-c1">NULL</span>;</td>
      </tr>
      <tr>
        <td id="L1117" class="blob-num js-line-number" data-line-number="1117"></td>
        <td id="LC1117" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L1118" class="blob-num js-line-number" data-line-number="1118"></td>
        <td id="LC1118" class="blob-code blob-code-inner js-file-line">   f = <span class="pl-c1">fopen</span>(filename, <span class="pl-s"><span class="pl-pds">&quot;</span>wb<span class="pl-pds">&quot;</span></span>);</td>
      </tr>
      <tr>
        <td id="L1119" class="blob-num js-line-number" data-line-number="1119"></td>
        <td id="LC1119" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L1120" class="blob-num js-line-number" data-line-number="1120"></td>
        <td id="LC1120" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (!f) { <span class="pl-c1">STBIW_FREE</span>(png); <span class="pl-k">return</span> <span class="pl-c1">0</span>; }</td>
      </tr>
      <tr>
        <td id="L1121" class="blob-num js-line-number" data-line-number="1121"></td>
        <td id="LC1121" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">fwrite</span>(png, <span class="pl-c1">1</span>, len, f);</td>
      </tr>
      <tr>
        <td id="L1122" class="blob-num js-line-number" data-line-number="1122"></td>
        <td id="LC1122" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">fclose</span>(f);</td>
      </tr>
      <tr>
        <td id="L1123" class="blob-num js-line-number" data-line-number="1123"></td>
        <td id="LC1123" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_FREE</span>(png);</td>
      </tr>
      <tr>
        <td id="L1124" class="blob-num js-line-number" data-line-number="1124"></td>
        <td id="LC1124" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1125" class="blob-num js-line-number" data-line-number="1125"></td>
        <td id="LC1125" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1126" class="blob-num js-line-number" data-line-number="1126"></td>
        <td id="LC1126" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L1127" class="blob-num js-line-number" data-line-number="1127"></td>
        <td id="LC1127" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1128" class="blob-num js-line-number" data-line-number="1128"></td>
        <td id="LC1128" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_png_to_func</span>(stbi_write_func *func, <span class="pl-k">void</span> *context, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span> *data, <span class="pl-k">int</span> stride_bytes)</td>
      </tr>
      <tr>
        <td id="L1129" class="blob-num js-line-number" data-line-number="1129"></td>
        <td id="LC1129" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L1130" class="blob-num js-line-number" data-line-number="1130"></td>
        <td id="LC1130" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> len;</td>
      </tr>
      <tr>
        <td id="L1131" class="blob-num js-line-number" data-line-number="1131"></td>
        <td id="LC1131" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *png = <span class="pl-c1">stbi_write_png_to_mem</span>((<span class="pl-k">unsigned</span> <span class="pl-k">char</span> *) data, stride_bytes, x, y, comp, &amp;len);</td>
      </tr>
      <tr>
        <td id="L1132" class="blob-num js-line-number" data-line-number="1132"></td>
        <td id="LC1132" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (png == <span class="pl-c1">NULL</span>) <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1133" class="blob-num js-line-number" data-line-number="1133"></td>
        <td id="LC1133" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">func</span>(context, png, len);</td>
      </tr>
      <tr>
        <td id="L1134" class="blob-num js-line-number" data-line-number="1134"></td>
        <td id="LC1134" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">STBIW_FREE</span>(png);</td>
      </tr>
      <tr>
        <td id="L1135" class="blob-num js-line-number" data-line-number="1135"></td>
        <td id="LC1135" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1136" class="blob-num js-line-number" data-line-number="1136"></td>
        <td id="LC1136" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1137" class="blob-num js-line-number" data-line-number="1137"></td>
        <td id="LC1137" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1138" class="blob-num js-line-number" data-line-number="1138"></td>
        <td id="LC1138" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1139" class="blob-num js-line-number" data-line-number="1139"></td>
        <td id="LC1139" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">/*</span> ***************************************************************************</span></td>
      </tr>
      <tr>
        <td id="L1140" class="blob-num js-line-number" data-line-number="1140"></td>
        <td id="LC1140" class="blob-code blob-code-inner js-file-line"><span class="pl-c"> *</span></td>
      </tr>
      <tr>
        <td id="L1141" class="blob-num js-line-number" data-line-number="1141"></td>
        <td id="LC1141" class="blob-code blob-code-inner js-file-line"><span class="pl-c"> * JPEG writer</span></td>
      </tr>
      <tr>
        <td id="L1142" class="blob-num js-line-number" data-line-number="1142"></td>
        <td id="LC1142" class="blob-code blob-code-inner js-file-line"><span class="pl-c"> *</span></td>
      </tr>
      <tr>
        <td id="L1143" class="blob-num js-line-number" data-line-number="1143"></td>
        <td id="LC1143" class="blob-code blob-code-inner js-file-line"><span class="pl-c"> * This is based on Jon Olick&#39;s jo_jpeg.cpp:</span></td>
      </tr>
      <tr>
        <td id="L1144" class="blob-num js-line-number" data-line-number="1144"></td>
        <td id="LC1144" class="blob-code blob-code-inner js-file-line"><span class="pl-c"> * public domain Simple, Minimalistic JPEG writer - http://www.jonolick.com/code.html</span></td>
      </tr>
      <tr>
        <td id="L1145" class="blob-num js-line-number" data-line-number="1145"></td>
        <td id="LC1145" class="blob-code blob-code-inner js-file-line"><span class="pl-c"> <span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L1146" class="blob-num js-line-number" data-line-number="1146"></td>
        <td id="LC1146" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1147" class="blob-num js-line-number" data-line-number="1147"></td>
        <td id="LC1147" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> stbiw__jpg_ZigZag[] = { <span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">5</span>,<span class="pl-c1">6</span>,<span class="pl-c1">14</span>,<span class="pl-c1">15</span>,<span class="pl-c1">27</span>,<span class="pl-c1">28</span>,<span class="pl-c1">2</span>,<span class="pl-c1">4</span>,<span class="pl-c1">7</span>,<span class="pl-c1">13</span>,<span class="pl-c1">16</span>,<span class="pl-c1">26</span>,<span class="pl-c1">29</span>,<span class="pl-c1">42</span>,<span class="pl-c1">3</span>,<span class="pl-c1">8</span>,<span class="pl-c1">12</span>,<span class="pl-c1">17</span>,<span class="pl-c1">25</span>,<span class="pl-c1">30</span>,<span class="pl-c1">41</span>,<span class="pl-c1">43</span>,<span class="pl-c1">9</span>,<span class="pl-c1">11</span>,<span class="pl-c1">18</span>,</td>
      </tr>
      <tr>
        <td id="L1148" class="blob-num js-line-number" data-line-number="1148"></td>
        <td id="LC1148" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">24</span>,<span class="pl-c1">31</span>,<span class="pl-c1">40</span>,<span class="pl-c1">44</span>,<span class="pl-c1">53</span>,<span class="pl-c1">10</span>,<span class="pl-c1">19</span>,<span class="pl-c1">23</span>,<span class="pl-c1">32</span>,<span class="pl-c1">39</span>,<span class="pl-c1">45</span>,<span class="pl-c1">52</span>,<span class="pl-c1">54</span>,<span class="pl-c1">20</span>,<span class="pl-c1">22</span>,<span class="pl-c1">33</span>,<span class="pl-c1">38</span>,<span class="pl-c1">46</span>,<span class="pl-c1">51</span>,<span class="pl-c1">55</span>,<span class="pl-c1">60</span>,<span class="pl-c1">21</span>,<span class="pl-c1">34</span>,<span class="pl-c1">37</span>,<span class="pl-c1">47</span>,<span class="pl-c1">50</span>,<span class="pl-c1">56</span>,<span class="pl-c1">59</span>,<span class="pl-c1">61</span>,<span class="pl-c1">35</span>,<span class="pl-c1">36</span>,<span class="pl-c1">48</span>,<span class="pl-c1">49</span>,<span class="pl-c1">57</span>,<span class="pl-c1">58</span>,<span class="pl-c1">62</span>,<span class="pl-c1">63</span> };</td>
      </tr>
      <tr>
        <td id="L1149" class="blob-num js-line-number" data-line-number="1149"></td>
        <td id="LC1149" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1150" class="blob-num js-line-number" data-line-number="1150"></td>
        <td id="LC1150" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__jpg_writeBits</span>(stbi__write_context *s, <span class="pl-k">int</span> *bitBufP, <span class="pl-k">int</span> *bitCntP, <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> *bs) {</td>
      </tr>
      <tr>
        <td id="L1151" class="blob-num js-line-number" data-line-number="1151"></td>
        <td id="LC1151" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> bitBuf = *bitBufP, bitCnt = *bitCntP;</td>
      </tr>
      <tr>
        <td id="L1152" class="blob-num js-line-number" data-line-number="1152"></td>
        <td id="LC1152" class="blob-code blob-code-inner js-file-line">   bitCnt += bs[<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L1153" class="blob-num js-line-number" data-line-number="1153"></td>
        <td id="LC1153" class="blob-code blob-code-inner js-file-line">   bitBuf |= bs[<span class="pl-c1">0</span>] &lt;&lt; (<span class="pl-c1">24</span> - bitCnt);</td>
      </tr>
      <tr>
        <td id="L1154" class="blob-num js-line-number" data-line-number="1154"></td>
        <td id="LC1154" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">while</span>(bitCnt &gt;= <span class="pl-c1">8</span>) {</td>
      </tr>
      <tr>
        <td id="L1155" class="blob-num js-line-number" data-line-number="1155"></td>
        <td id="LC1155" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">unsigned</span> <span class="pl-k">char</span> c = (bitBuf &gt;&gt; <span class="pl-c1">16</span>) &amp; <span class="pl-c1">255</span>;</td>
      </tr>
      <tr>
        <td id="L1156" class="blob-num js-line-number" data-line-number="1156"></td>
        <td id="LC1156" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__putc</span>(s, c);</td>
      </tr>
      <tr>
        <td id="L1157" class="blob-num js-line-number" data-line-number="1157"></td>
        <td id="LC1157" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span>(c == <span class="pl-c1">255</span>) {</td>
      </tr>
      <tr>
        <td id="L1158" class="blob-num js-line-number" data-line-number="1158"></td>
        <td id="LC1158" class="blob-code blob-code-inner js-file-line">         <span class="pl-c1">stbiw__putc</span>(s, <span class="pl-c1">0</span>);</td>
      </tr>
      <tr>
        <td id="L1159" class="blob-num js-line-number" data-line-number="1159"></td>
        <td id="LC1159" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1160" class="blob-num js-line-number" data-line-number="1160"></td>
        <td id="LC1160" class="blob-code blob-code-inner js-file-line">      bitBuf &lt;&lt;= <span class="pl-c1">8</span>;</td>
      </tr>
      <tr>
        <td id="L1161" class="blob-num js-line-number" data-line-number="1161"></td>
        <td id="LC1161" class="blob-code blob-code-inner js-file-line">      bitCnt -= <span class="pl-c1">8</span>;</td>
      </tr>
      <tr>
        <td id="L1162" class="blob-num js-line-number" data-line-number="1162"></td>
        <td id="LC1162" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1163" class="blob-num js-line-number" data-line-number="1163"></td>
        <td id="LC1163" class="blob-code blob-code-inner js-file-line">   *bitBufP = bitBuf;</td>
      </tr>
      <tr>
        <td id="L1164" class="blob-num js-line-number" data-line-number="1164"></td>
        <td id="LC1164" class="blob-code blob-code-inner js-file-line">   *bitCntP = bitCnt;</td>
      </tr>
      <tr>
        <td id="L1165" class="blob-num js-line-number" data-line-number="1165"></td>
        <td id="LC1165" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1166" class="blob-num js-line-number" data-line-number="1166"></td>
        <td id="LC1166" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1167" class="blob-num js-line-number" data-line-number="1167"></td>
        <td id="LC1167" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__jpg_DCT</span>(<span class="pl-k">float</span> *d0p, <span class="pl-k">float</span> *d1p, <span class="pl-k">float</span> *d2p, <span class="pl-k">float</span> *d3p, <span class="pl-k">float</span> *d4p, <span class="pl-k">float</span> *d5p, <span class="pl-k">float</span> *d6p, <span class="pl-k">float</span> *d7p) {</td>
      </tr>
      <tr>
        <td id="L1168" class="blob-num js-line-number" data-line-number="1168"></td>
        <td id="LC1168" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> d0 = *d0p, d1 = *d1p, d2 = *d2p, d3 = *d3p, d4 = *d4p, d5 = *d5p, d6 = *d6p, d7 = *d7p;</td>
      </tr>
      <tr>
        <td id="L1169" class="blob-num js-line-number" data-line-number="1169"></td>
        <td id="LC1169" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> z1, z2, z3, z4, z5, z11, z13;</td>
      </tr>
      <tr>
        <td id="L1170" class="blob-num js-line-number" data-line-number="1170"></td>
        <td id="LC1170" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1171" class="blob-num js-line-number" data-line-number="1171"></td>
        <td id="LC1171" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp0 = d0 + d7;</td>
      </tr>
      <tr>
        <td id="L1172" class="blob-num js-line-number" data-line-number="1172"></td>
        <td id="LC1172" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp7 = d0 - d7;</td>
      </tr>
      <tr>
        <td id="L1173" class="blob-num js-line-number" data-line-number="1173"></td>
        <td id="LC1173" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp1 = d1 + d6;</td>
      </tr>
      <tr>
        <td id="L1174" class="blob-num js-line-number" data-line-number="1174"></td>
        <td id="LC1174" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp6 = d1 - d6;</td>
      </tr>
      <tr>
        <td id="L1175" class="blob-num js-line-number" data-line-number="1175"></td>
        <td id="LC1175" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp2 = d2 + d5;</td>
      </tr>
      <tr>
        <td id="L1176" class="blob-num js-line-number" data-line-number="1176"></td>
        <td id="LC1176" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp5 = d2 - d5;</td>
      </tr>
      <tr>
        <td id="L1177" class="blob-num js-line-number" data-line-number="1177"></td>
        <td id="LC1177" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp3 = d3 + d4;</td>
      </tr>
      <tr>
        <td id="L1178" class="blob-num js-line-number" data-line-number="1178"></td>
        <td id="LC1178" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp4 = d3 - d4;</td>
      </tr>
      <tr>
        <td id="L1179" class="blob-num js-line-number" data-line-number="1179"></td>
        <td id="LC1179" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1180" class="blob-num js-line-number" data-line-number="1180"></td>
        <td id="LC1180" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> Even part</span></td>
      </tr>
      <tr>
        <td id="L1181" class="blob-num js-line-number" data-line-number="1181"></td>
        <td id="LC1181" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp10 = tmp0 + tmp3;   <span class="pl-c"><span class="pl-c">//</span> phase 2</span></td>
      </tr>
      <tr>
        <td id="L1182" class="blob-num js-line-number" data-line-number="1182"></td>
        <td id="LC1182" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp13 = tmp0 - tmp3;</td>
      </tr>
      <tr>
        <td id="L1183" class="blob-num js-line-number" data-line-number="1183"></td>
        <td id="LC1183" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp11 = tmp1 + tmp2;</td>
      </tr>
      <tr>
        <td id="L1184" class="blob-num js-line-number" data-line-number="1184"></td>
        <td id="LC1184" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> tmp12 = tmp1 - tmp2;</td>
      </tr>
      <tr>
        <td id="L1185" class="blob-num js-line-number" data-line-number="1185"></td>
        <td id="LC1185" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1186" class="blob-num js-line-number" data-line-number="1186"></td>
        <td id="LC1186" class="blob-code blob-code-inner js-file-line">   d0 = tmp10 + tmp11;       <span class="pl-c"><span class="pl-c">//</span> phase 3</span></td>
      </tr>
      <tr>
        <td id="L1187" class="blob-num js-line-number" data-line-number="1187"></td>
        <td id="LC1187" class="blob-code blob-code-inner js-file-line">   d4 = tmp10 - tmp11;</td>
      </tr>
      <tr>
        <td id="L1188" class="blob-num js-line-number" data-line-number="1188"></td>
        <td id="LC1188" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1189" class="blob-num js-line-number" data-line-number="1189"></td>
        <td id="LC1189" class="blob-code blob-code-inner js-file-line">   z1 = (tmp12 + tmp13) * <span class="pl-c1">0</span>.<span class="pl-c1">707106781f</span>; <span class="pl-c"><span class="pl-c">//</span> c4</span></td>
      </tr>
      <tr>
        <td id="L1190" class="blob-num js-line-number" data-line-number="1190"></td>
        <td id="LC1190" class="blob-code blob-code-inner js-file-line">   d2 = tmp13 + z1;       <span class="pl-c"><span class="pl-c">//</span> phase 5</span></td>
      </tr>
      <tr>
        <td id="L1191" class="blob-num js-line-number" data-line-number="1191"></td>
        <td id="LC1191" class="blob-code blob-code-inner js-file-line">   d6 = tmp13 - z1;</td>
      </tr>
      <tr>
        <td id="L1192" class="blob-num js-line-number" data-line-number="1192"></td>
        <td id="LC1192" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1193" class="blob-num js-line-number" data-line-number="1193"></td>
        <td id="LC1193" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> Odd part</span></td>
      </tr>
      <tr>
        <td id="L1194" class="blob-num js-line-number" data-line-number="1194"></td>
        <td id="LC1194" class="blob-code blob-code-inner js-file-line">   tmp10 = tmp4 + tmp5;       <span class="pl-c"><span class="pl-c">//</span> phase 2</span></td>
      </tr>
      <tr>
        <td id="L1195" class="blob-num js-line-number" data-line-number="1195"></td>
        <td id="LC1195" class="blob-code blob-code-inner js-file-line">   tmp11 = tmp5 + tmp6;</td>
      </tr>
      <tr>
        <td id="L1196" class="blob-num js-line-number" data-line-number="1196"></td>
        <td id="LC1196" class="blob-code blob-code-inner js-file-line">   tmp12 = tmp6 + tmp7;</td>
      </tr>
      <tr>
        <td id="L1197" class="blob-num js-line-number" data-line-number="1197"></td>
        <td id="LC1197" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1198" class="blob-num js-line-number" data-line-number="1198"></td>
        <td id="LC1198" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> The rotator is modified from fig 4-8 to avoid extra negations.</span></td>
      </tr>
      <tr>
        <td id="L1199" class="blob-num js-line-number" data-line-number="1199"></td>
        <td id="LC1199" class="blob-code blob-code-inner js-file-line">   z5 = (tmp10 - tmp12) * <span class="pl-c1">0</span>.<span class="pl-c1">382683433f</span>; <span class="pl-c"><span class="pl-c">//</span> c6</span></td>
      </tr>
      <tr>
        <td id="L1200" class="blob-num js-line-number" data-line-number="1200"></td>
        <td id="LC1200" class="blob-code blob-code-inner js-file-line">   z2 = tmp10 * <span class="pl-c1">0</span>.<span class="pl-c1">541196100f</span> + z5; <span class="pl-c"><span class="pl-c">//</span> c2-c6</span></td>
      </tr>
      <tr>
        <td id="L1201" class="blob-num js-line-number" data-line-number="1201"></td>
        <td id="LC1201" class="blob-code blob-code-inner js-file-line">   z4 = tmp12 * <span class="pl-c1">1</span>.<span class="pl-c1">306562965f</span> + z5; <span class="pl-c"><span class="pl-c">//</span> c2+c6</span></td>
      </tr>
      <tr>
        <td id="L1202" class="blob-num js-line-number" data-line-number="1202"></td>
        <td id="LC1202" class="blob-code blob-code-inner js-file-line">   z3 = tmp11 * <span class="pl-c1">0</span>.<span class="pl-c1">707106781f</span>; <span class="pl-c"><span class="pl-c">//</span> c4</span></td>
      </tr>
      <tr>
        <td id="L1203" class="blob-num js-line-number" data-line-number="1203"></td>
        <td id="LC1203" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1204" class="blob-num js-line-number" data-line-number="1204"></td>
        <td id="LC1204" class="blob-code blob-code-inner js-file-line">   z11 = tmp7 + z3;      <span class="pl-c"><span class="pl-c">//</span> phase 5</span></td>
      </tr>
      <tr>
        <td id="L1205" class="blob-num js-line-number" data-line-number="1205"></td>
        <td id="LC1205" class="blob-code blob-code-inner js-file-line">   z13 = tmp7 - z3;</td>
      </tr>
      <tr>
        <td id="L1206" class="blob-num js-line-number" data-line-number="1206"></td>
        <td id="LC1206" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1207" class="blob-num js-line-number" data-line-number="1207"></td>
        <td id="LC1207" class="blob-code blob-code-inner js-file-line">   *d5p = z13 + z2;         <span class="pl-c"><span class="pl-c">//</span> phase 6</span></td>
      </tr>
      <tr>
        <td id="L1208" class="blob-num js-line-number" data-line-number="1208"></td>
        <td id="LC1208" class="blob-code blob-code-inner js-file-line">   *d3p = z13 - z2;</td>
      </tr>
      <tr>
        <td id="L1209" class="blob-num js-line-number" data-line-number="1209"></td>
        <td id="LC1209" class="blob-code blob-code-inner js-file-line">   *d1p = z11 + z4;</td>
      </tr>
      <tr>
        <td id="L1210" class="blob-num js-line-number" data-line-number="1210"></td>
        <td id="LC1210" class="blob-code blob-code-inner js-file-line">   *d7p = z11 - z4;</td>
      </tr>
      <tr>
        <td id="L1211" class="blob-num js-line-number" data-line-number="1211"></td>
        <td id="LC1211" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1212" class="blob-num js-line-number" data-line-number="1212"></td>
        <td id="LC1212" class="blob-code blob-code-inner js-file-line">   *d0p = d0;  *d2p = d2;  *d4p = d4;  *d6p = d6;</td>
      </tr>
      <tr>
        <td id="L1213" class="blob-num js-line-number" data-line-number="1213"></td>
        <td id="LC1213" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1214" class="blob-num js-line-number" data-line-number="1214"></td>
        <td id="LC1214" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1215" class="blob-num js-line-number" data-line-number="1215"></td>
        <td id="LC1215" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">void</span> <span class="pl-en">stbiw__jpg_calcBits</span>(<span class="pl-k">int</span> val, <span class="pl-k">unsigned</span> <span class="pl-k">short</span> bits[<span class="pl-c1">2</span>]) {</td>
      </tr>
      <tr>
        <td id="L1216" class="blob-num js-line-number" data-line-number="1216"></td>
        <td id="LC1216" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> tmp1 = val &lt; <span class="pl-c1">0</span> ? -val : val;</td>
      </tr>
      <tr>
        <td id="L1217" class="blob-num js-line-number" data-line-number="1217"></td>
        <td id="LC1217" class="blob-code blob-code-inner js-file-line">   val = val &lt; <span class="pl-c1">0</span> ? val-<span class="pl-c1">1</span> : val;</td>
      </tr>
      <tr>
        <td id="L1218" class="blob-num js-line-number" data-line-number="1218"></td>
        <td id="LC1218" class="blob-code blob-code-inner js-file-line">   bits[<span class="pl-c1">1</span>] = <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1219" class="blob-num js-line-number" data-line-number="1219"></td>
        <td id="LC1219" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">while</span>(tmp1 &gt;&gt;= <span class="pl-c1">1</span>) {</td>
      </tr>
      <tr>
        <td id="L1220" class="blob-num js-line-number" data-line-number="1220"></td>
        <td id="LC1220" class="blob-code blob-code-inner js-file-line">      ++bits[<span class="pl-c1">1</span>];</td>
      </tr>
      <tr>
        <td id="L1221" class="blob-num js-line-number" data-line-number="1221"></td>
        <td id="LC1221" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1222" class="blob-num js-line-number" data-line-number="1222"></td>
        <td id="LC1222" class="blob-code blob-code-inner js-file-line">   bits[<span class="pl-c1">0</span>] = val &amp; ((<span class="pl-c1">1</span>&lt;&lt;bits[<span class="pl-c1">1</span>])-<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L1223" class="blob-num js-line-number" data-line-number="1223"></td>
        <td id="LC1223" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1224" class="blob-num js-line-number" data-line-number="1224"></td>
        <td id="LC1224" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1225" class="blob-num js-line-number" data-line-number="1225"></td>
        <td id="LC1225" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> <span class="pl-en">stbiw__jpg_processDU</span>(stbi__write_context *s, <span class="pl-k">int</span> *bitBuf, <span class="pl-k">int</span> *bitCnt, <span class="pl-k">float</span> *CDU, <span class="pl-k">float</span> *fdtbl, <span class="pl-k">int</span> DC, <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> HTDC[<span class="pl-c1">256</span>][<span class="pl-c1">2</span>], <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> HTAC[<span class="pl-c1">256</span>][<span class="pl-c1">2</span>]) {</td>
      </tr>
      <tr>
        <td id="L1226" class="blob-num js-line-number" data-line-number="1226"></td>
        <td id="LC1226" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> EOB[<span class="pl-c1">2</span>] = { HTAC[<span class="pl-c1">0x00</span>][<span class="pl-c1">0</span>], HTAC[<span class="pl-c1">0x00</span>][<span class="pl-c1">1</span>] };</td>
      </tr>
      <tr>
        <td id="L1227" class="blob-num js-line-number" data-line-number="1227"></td>
        <td id="LC1227" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> M16zeroes[<span class="pl-c1">2</span>] = { HTAC[<span class="pl-c1">0xF0</span>][<span class="pl-c1">0</span>], HTAC[<span class="pl-c1">0xF0</span>][<span class="pl-c1">1</span>] };</td>
      </tr>
      <tr>
        <td id="L1228" class="blob-num js-line-number" data-line-number="1228"></td>
        <td id="LC1228" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> dataOff, i, diff, end0pos;</td>
      </tr>
      <tr>
        <td id="L1229" class="blob-num js-line-number" data-line-number="1229"></td>
        <td id="LC1229" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> DU[<span class="pl-c1">64</span>];</td>
      </tr>
      <tr>
        <td id="L1230" class="blob-num js-line-number" data-line-number="1230"></td>
        <td id="LC1230" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1231" class="blob-num js-line-number" data-line-number="1231"></td>
        <td id="LC1231" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> DCT rows</span></td>
      </tr>
      <tr>
        <td id="L1232" class="blob-num js-line-number" data-line-number="1232"></td>
        <td id="LC1232" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span>(dataOff=<span class="pl-c1">0</span>; dataOff&lt;<span class="pl-c1">64</span>; dataOff+=<span class="pl-c1">8</span>) {</td>
      </tr>
      <tr>
        <td id="L1233" class="blob-num js-line-number" data-line-number="1233"></td>
        <td id="LC1233" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_DCT</span>(&amp;CDU[dataOff], &amp;CDU[dataOff+<span class="pl-c1">1</span>], &amp;CDU[dataOff+<span class="pl-c1">2</span>], &amp;CDU[dataOff+<span class="pl-c1">3</span>], &amp;CDU[dataOff+<span class="pl-c1">4</span>], &amp;CDU[dataOff+<span class="pl-c1">5</span>], &amp;CDU[dataOff+<span class="pl-c1">6</span>], &amp;CDU[dataOff+<span class="pl-c1">7</span>]);</td>
      </tr>
      <tr>
        <td id="L1234" class="blob-num js-line-number" data-line-number="1234"></td>
        <td id="LC1234" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1235" class="blob-num js-line-number" data-line-number="1235"></td>
        <td id="LC1235" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> DCT columns</span></td>
      </tr>
      <tr>
        <td id="L1236" class="blob-num js-line-number" data-line-number="1236"></td>
        <td id="LC1236" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span>(dataOff=<span class="pl-c1">0</span>; dataOff&lt;<span class="pl-c1">8</span>; ++dataOff) {</td>
      </tr>
      <tr>
        <td id="L1237" class="blob-num js-line-number" data-line-number="1237"></td>
        <td id="LC1237" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_DCT</span>(&amp;CDU[dataOff], &amp;CDU[dataOff+<span class="pl-c1">8</span>], &amp;CDU[dataOff+<span class="pl-c1">16</span>], &amp;CDU[dataOff+<span class="pl-c1">24</span>], &amp;CDU[dataOff+<span class="pl-c1">32</span>], &amp;CDU[dataOff+<span class="pl-c1">40</span>], &amp;CDU[dataOff+<span class="pl-c1">48</span>], &amp;CDU[dataOff+<span class="pl-c1">56</span>]);</td>
      </tr>
      <tr>
        <td id="L1238" class="blob-num js-line-number" data-line-number="1238"></td>
        <td id="LC1238" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1239" class="blob-num js-line-number" data-line-number="1239"></td>
        <td id="LC1239" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> Quantize/descale/zigzag the coefficients</span></td>
      </tr>
      <tr>
        <td id="L1240" class="blob-num js-line-number" data-line-number="1240"></td>
        <td id="LC1240" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span>(i=<span class="pl-c1">0</span>; i&lt;<span class="pl-c1">64</span>; ++i) {</td>
      </tr>
      <tr>
        <td id="L1241" class="blob-num js-line-number" data-line-number="1241"></td>
        <td id="LC1241" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">float</span> v = CDU[i]*fdtbl[i];</td>
      </tr>
      <tr>
        <td id="L1242" class="blob-num js-line-number" data-line-number="1242"></td>
        <td id="LC1242" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> DU[stbiw__jpg_ZigZag[i]] = (int)(v &lt; 0 ? ceilf(v - 0.5f) : floorf(v + 0.5f));</span></td>
      </tr>
      <tr>
        <td id="L1243" class="blob-num js-line-number" data-line-number="1243"></td>
        <td id="LC1243" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> ceilf() and floorf() are C99, not C89, but I /think/ they&#39;re not needed here anyway?</span></td>
      </tr>
      <tr>
        <td id="L1244" class="blob-num js-line-number" data-line-number="1244"></td>
        <td id="LC1244" class="blob-code blob-code-inner js-file-line">      DU[stbiw__jpg_ZigZag[i]] = (<span class="pl-k">int</span>)(v &lt; <span class="pl-c1">0</span> ? v - <span class="pl-c1">0</span>.<span class="pl-c1">5f</span> : v + <span class="pl-c1">0</span>.<span class="pl-c1">5f</span>);</td>
      </tr>
      <tr>
        <td id="L1245" class="blob-num js-line-number" data-line-number="1245"></td>
        <td id="LC1245" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1246" class="blob-num js-line-number" data-line-number="1246"></td>
        <td id="LC1246" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1247" class="blob-num js-line-number" data-line-number="1247"></td>
        <td id="LC1247" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> Encode DC</span></td>
      </tr>
      <tr>
        <td id="L1248" class="blob-num js-line-number" data-line-number="1248"></td>
        <td id="LC1248" class="blob-code blob-code-inner js-file-line">   diff = DU[<span class="pl-c1">0</span>] - DC;</td>
      </tr>
      <tr>
        <td id="L1249" class="blob-num js-line-number" data-line-number="1249"></td>
        <td id="LC1249" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (diff == <span class="pl-c1">0</span>) {</td>
      </tr>
      <tr>
        <td id="L1250" class="blob-num js-line-number" data-line-number="1250"></td>
        <td id="LC1250" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_writeBits</span>(s, bitBuf, bitCnt, HTDC[<span class="pl-c1">0</span>]);</td>
      </tr>
      <tr>
        <td id="L1251" class="blob-num js-line-number" data-line-number="1251"></td>
        <td id="LC1251" class="blob-code blob-code-inner js-file-line">   } <span class="pl-k">else</span> {</td>
      </tr>
      <tr>
        <td id="L1252" class="blob-num js-line-number" data-line-number="1252"></td>
        <td id="LC1252" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">unsigned</span> <span class="pl-k">short</span> bits[<span class="pl-c1">2</span>];</td>
      </tr>
      <tr>
        <td id="L1253" class="blob-num js-line-number" data-line-number="1253"></td>
        <td id="LC1253" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_calcBits</span>(diff, bits);</td>
      </tr>
      <tr>
        <td id="L1254" class="blob-num js-line-number" data-line-number="1254"></td>
        <td id="LC1254" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_writeBits</span>(s, bitBuf, bitCnt, HTDC[bits[<span class="pl-c1">1</span>]]);</td>
      </tr>
      <tr>
        <td id="L1255" class="blob-num js-line-number" data-line-number="1255"></td>
        <td id="LC1255" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_writeBits</span>(s, bitBuf, bitCnt, bits);</td>
      </tr>
      <tr>
        <td id="L1256" class="blob-num js-line-number" data-line-number="1256"></td>
        <td id="LC1256" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1257" class="blob-num js-line-number" data-line-number="1257"></td>
        <td id="LC1257" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> Encode ACs</span></td>
      </tr>
      <tr>
        <td id="L1258" class="blob-num js-line-number" data-line-number="1258"></td>
        <td id="LC1258" class="blob-code blob-code-inner js-file-line">   end0pos = <span class="pl-c1">63</span>;</td>
      </tr>
      <tr>
        <td id="L1259" class="blob-num js-line-number" data-line-number="1259"></td>
        <td id="LC1259" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span>(; (end0pos&gt;<span class="pl-c1">0</span>)&amp;&amp;(DU[end0pos]==<span class="pl-c1">0</span>); --end0pos) {</td>
      </tr>
      <tr>
        <td id="L1260" class="blob-num js-line-number" data-line-number="1260"></td>
        <td id="LC1260" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1261" class="blob-num js-line-number" data-line-number="1261"></td>
        <td id="LC1261" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> end0pos = first element in reverse order !=0</span></td>
      </tr>
      <tr>
        <td id="L1262" class="blob-num js-line-number" data-line-number="1262"></td>
        <td id="LC1262" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span>(end0pos == <span class="pl-c1">0</span>) {</td>
      </tr>
      <tr>
        <td id="L1263" class="blob-num js-line-number" data-line-number="1263"></td>
        <td id="LC1263" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_writeBits</span>(s, bitBuf, bitCnt, EOB);</td>
      </tr>
      <tr>
        <td id="L1264" class="blob-num js-line-number" data-line-number="1264"></td>
        <td id="LC1264" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> DU[<span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L1265" class="blob-num js-line-number" data-line-number="1265"></td>
        <td id="LC1265" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1266" class="blob-num js-line-number" data-line-number="1266"></td>
        <td id="LC1266" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span>(i = <span class="pl-c1">1</span>; i &lt;= end0pos; ++i) {</td>
      </tr>
      <tr>
        <td id="L1267" class="blob-num js-line-number" data-line-number="1267"></td>
        <td id="LC1267" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> startpos = i;</td>
      </tr>
      <tr>
        <td id="L1268" class="blob-num js-line-number" data-line-number="1268"></td>
        <td id="LC1268" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> nrzeroes;</td>
      </tr>
      <tr>
        <td id="L1269" class="blob-num js-line-number" data-line-number="1269"></td>
        <td id="LC1269" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">unsigned</span> <span class="pl-k">short</span> bits[<span class="pl-c1">2</span>];</td>
      </tr>
      <tr>
        <td id="L1270" class="blob-num js-line-number" data-line-number="1270"></td>
        <td id="LC1270" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span> (; DU[i]==<span class="pl-c1">0</span> &amp;&amp; i&lt;=end0pos; ++i) {</td>
      </tr>
      <tr>
        <td id="L1271" class="blob-num js-line-number" data-line-number="1271"></td>
        <td id="LC1271" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1272" class="blob-num js-line-number" data-line-number="1272"></td>
        <td id="LC1272" class="blob-code blob-code-inner js-file-line">      nrzeroes = i-startpos;</td>
      </tr>
      <tr>
        <td id="L1273" class="blob-num js-line-number" data-line-number="1273"></td>
        <td id="LC1273" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">if</span> ( nrzeroes &gt;= <span class="pl-c1">16</span> ) {</td>
      </tr>
      <tr>
        <td id="L1274" class="blob-num js-line-number" data-line-number="1274"></td>
        <td id="LC1274" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">int</span> lng = nrzeroes&gt;&gt;<span class="pl-c1">4</span>;</td>
      </tr>
      <tr>
        <td id="L1275" class="blob-num js-line-number" data-line-number="1275"></td>
        <td id="LC1275" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">int</span> nrmarker;</td>
      </tr>
      <tr>
        <td id="L1276" class="blob-num js-line-number" data-line-number="1276"></td>
        <td id="LC1276" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">for</span> (nrmarker=<span class="pl-c1">1</span>; nrmarker &lt;= lng; ++nrmarker)</td>
      </tr>
      <tr>
        <td id="L1277" class="blob-num js-line-number" data-line-number="1277"></td>
        <td id="LC1277" class="blob-code blob-code-inner js-file-line">            <span class="pl-c1">stbiw__jpg_writeBits</span>(s, bitBuf, bitCnt, M16zeroes);</td>
      </tr>
      <tr>
        <td id="L1278" class="blob-num js-line-number" data-line-number="1278"></td>
        <td id="LC1278" class="blob-code blob-code-inner js-file-line">         nrzeroes &amp;= <span class="pl-c1">15</span>;</td>
      </tr>
      <tr>
        <td id="L1279" class="blob-num js-line-number" data-line-number="1279"></td>
        <td id="LC1279" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1280" class="blob-num js-line-number" data-line-number="1280"></td>
        <td id="LC1280" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_calcBits</span>(DU[i], bits);</td>
      </tr>
      <tr>
        <td id="L1281" class="blob-num js-line-number" data-line-number="1281"></td>
        <td id="LC1281" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_writeBits</span>(s, bitBuf, bitCnt, HTAC[(nrzeroes&lt;&lt;<span class="pl-c1">4</span>)+bits[<span class="pl-c1">1</span>]]);</td>
      </tr>
      <tr>
        <td id="L1282" class="blob-num js-line-number" data-line-number="1282"></td>
        <td id="LC1282" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_writeBits</span>(s, bitBuf, bitCnt, bits);</td>
      </tr>
      <tr>
        <td id="L1283" class="blob-num js-line-number" data-line-number="1283"></td>
        <td id="LC1283" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1284" class="blob-num js-line-number" data-line-number="1284"></td>
        <td id="LC1284" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span>(end0pos != <span class="pl-c1">63</span>) {</td>
      </tr>
      <tr>
        <td id="L1285" class="blob-num js-line-number" data-line-number="1285"></td>
        <td id="LC1285" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_writeBits</span>(s, bitBuf, bitCnt, EOB);</td>
      </tr>
      <tr>
        <td id="L1286" class="blob-num js-line-number" data-line-number="1286"></td>
        <td id="LC1286" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1287" class="blob-num js-line-number" data-line-number="1287"></td>
        <td id="LC1287" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> DU[<span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L1288" class="blob-num js-line-number" data-line-number="1288"></td>
        <td id="LC1288" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1289" class="blob-num js-line-number" data-line-number="1289"></td>
        <td id="LC1289" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1290" class="blob-num js-line-number" data-line-number="1290"></td>
        <td id="LC1290" class="blob-code blob-code-inner js-file-line"><span class="pl-k">static</span> <span class="pl-k">int</span> <span class="pl-en">stbi_write_jpg_core</span>(stbi__write_context *s, <span class="pl-k">int</span> width, <span class="pl-k">int</span> height, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span>* data, <span class="pl-k">int</span> quality) {</td>
      </tr>
      <tr>
        <td id="L1291" class="blob-num js-line-number" data-line-number="1291"></td>
        <td id="LC1291" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> Constants that don&#39;t pollute global namespace</span></td>
      </tr>
      <tr>
        <td id="L1292" class="blob-num js-line-number" data-line-number="1292"></td>
        <td id="LC1292" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> std_dc_luminance_nrcodes[] = {<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">5</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>};</td>
      </tr>
      <tr>
        <td id="L1293" class="blob-num js-line-number" data-line-number="1293"></td>
        <td id="LC1293" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> std_dc_luminance_values[] = {<span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">2</span>,<span class="pl-c1">3</span>,<span class="pl-c1">4</span>,<span class="pl-c1">5</span>,<span class="pl-c1">6</span>,<span class="pl-c1">7</span>,<span class="pl-c1">8</span>,<span class="pl-c1">9</span>,<span class="pl-c1">10</span>,<span class="pl-c1">11</span>};</td>
      </tr>
      <tr>
        <td id="L1294" class="blob-num js-line-number" data-line-number="1294"></td>
        <td id="LC1294" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> std_ac_luminance_nrcodes[] = {<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">2</span>,<span class="pl-c1">1</span>,<span class="pl-c1">3</span>,<span class="pl-c1">3</span>,<span class="pl-c1">2</span>,<span class="pl-c1">4</span>,<span class="pl-c1">3</span>,<span class="pl-c1">5</span>,<span class="pl-c1">5</span>,<span class="pl-c1">4</span>,<span class="pl-c1">4</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">0x7d</span>};</td>
      </tr>
      <tr>
        <td id="L1295" class="blob-num js-line-number" data-line-number="1295"></td>
        <td id="LC1295" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> std_ac_luminance_values[] = {</td>
      </tr>
      <tr>
        <td id="L1296" class="blob-num js-line-number" data-line-number="1296"></td>
        <td id="LC1296" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x01</span>,<span class="pl-c1">0x02</span>,<span class="pl-c1">0x03</span>,<span class="pl-c1">0x00</span>,<span class="pl-c1">0x04</span>,<span class="pl-c1">0x11</span>,<span class="pl-c1">0x05</span>,<span class="pl-c1">0x12</span>,<span class="pl-c1">0x21</span>,<span class="pl-c1">0x31</span>,<span class="pl-c1">0x41</span>,<span class="pl-c1">0x06</span>,<span class="pl-c1">0x13</span>,<span class="pl-c1">0x51</span>,<span class="pl-c1">0x61</span>,<span class="pl-c1">0x07</span>,<span class="pl-c1">0x22</span>,<span class="pl-c1">0x71</span>,<span class="pl-c1">0x14</span>,<span class="pl-c1">0x32</span>,<span class="pl-c1">0x81</span>,<span class="pl-c1">0x91</span>,<span class="pl-c1">0xa1</span>,<span class="pl-c1">0x08</span>,</td>
      </tr>
      <tr>
        <td id="L1297" class="blob-num js-line-number" data-line-number="1297"></td>
        <td id="LC1297" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x23</span>,<span class="pl-c1">0x42</span>,<span class="pl-c1">0xb1</span>,<span class="pl-c1">0xc1</span>,<span class="pl-c1">0x15</span>,<span class="pl-c1">0x52</span>,<span class="pl-c1">0xd1</span>,<span class="pl-c1">0xf0</span>,<span class="pl-c1">0x24</span>,<span class="pl-c1">0x33</span>,<span class="pl-c1">0x62</span>,<span class="pl-c1">0x72</span>,<span class="pl-c1">0x82</span>,<span class="pl-c1">0x09</span>,<span class="pl-c1">0x0a</span>,<span class="pl-c1">0x16</span>,<span class="pl-c1">0x17</span>,<span class="pl-c1">0x18</span>,<span class="pl-c1">0x19</span>,<span class="pl-c1">0x1a</span>,<span class="pl-c1">0x25</span>,<span class="pl-c1">0x26</span>,<span class="pl-c1">0x27</span>,<span class="pl-c1">0x28</span>,</td>
      </tr>
      <tr>
        <td id="L1298" class="blob-num js-line-number" data-line-number="1298"></td>
        <td id="LC1298" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x29</span>,<span class="pl-c1">0x2a</span>,<span class="pl-c1">0x34</span>,<span class="pl-c1">0x35</span>,<span class="pl-c1">0x36</span>,<span class="pl-c1">0x37</span>,<span class="pl-c1">0x38</span>,<span class="pl-c1">0x39</span>,<span class="pl-c1">0x3a</span>,<span class="pl-c1">0x43</span>,<span class="pl-c1">0x44</span>,<span class="pl-c1">0x45</span>,<span class="pl-c1">0x46</span>,<span class="pl-c1">0x47</span>,<span class="pl-c1">0x48</span>,<span class="pl-c1">0x49</span>,<span class="pl-c1">0x4a</span>,<span class="pl-c1">0x53</span>,<span class="pl-c1">0x54</span>,<span class="pl-c1">0x55</span>,<span class="pl-c1">0x56</span>,<span class="pl-c1">0x57</span>,<span class="pl-c1">0x58</span>,<span class="pl-c1">0x59</span>,</td>
      </tr>
      <tr>
        <td id="L1299" class="blob-num js-line-number" data-line-number="1299"></td>
        <td id="LC1299" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x5a</span>,<span class="pl-c1">0x63</span>,<span class="pl-c1">0x64</span>,<span class="pl-c1">0x65</span>,<span class="pl-c1">0x66</span>,<span class="pl-c1">0x67</span>,<span class="pl-c1">0x68</span>,<span class="pl-c1">0x69</span>,<span class="pl-c1">0x6a</span>,<span class="pl-c1">0x73</span>,<span class="pl-c1">0x74</span>,<span class="pl-c1">0x75</span>,<span class="pl-c1">0x76</span>,<span class="pl-c1">0x77</span>,<span class="pl-c1">0x78</span>,<span class="pl-c1">0x79</span>,<span class="pl-c1">0x7a</span>,<span class="pl-c1">0x83</span>,<span class="pl-c1">0x84</span>,<span class="pl-c1">0x85</span>,<span class="pl-c1">0x86</span>,<span class="pl-c1">0x87</span>,<span class="pl-c1">0x88</span>,<span class="pl-c1">0x89</span>,</td>
      </tr>
      <tr>
        <td id="L1300" class="blob-num js-line-number" data-line-number="1300"></td>
        <td id="LC1300" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x8a</span>,<span class="pl-c1">0x92</span>,<span class="pl-c1">0x93</span>,<span class="pl-c1">0x94</span>,<span class="pl-c1">0x95</span>,<span class="pl-c1">0x96</span>,<span class="pl-c1">0x97</span>,<span class="pl-c1">0x98</span>,<span class="pl-c1">0x99</span>,<span class="pl-c1">0x9a</span>,<span class="pl-c1">0xa2</span>,<span class="pl-c1">0xa3</span>,<span class="pl-c1">0xa4</span>,<span class="pl-c1">0xa5</span>,<span class="pl-c1">0xa6</span>,<span class="pl-c1">0xa7</span>,<span class="pl-c1">0xa8</span>,<span class="pl-c1">0xa9</span>,<span class="pl-c1">0xaa</span>,<span class="pl-c1">0xb2</span>,<span class="pl-c1">0xb3</span>,<span class="pl-c1">0xb4</span>,<span class="pl-c1">0xb5</span>,<span class="pl-c1">0xb6</span>,</td>
      </tr>
      <tr>
        <td id="L1301" class="blob-num js-line-number" data-line-number="1301"></td>
        <td id="LC1301" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xb7</span>,<span class="pl-c1">0xb8</span>,<span class="pl-c1">0xb9</span>,<span class="pl-c1">0xba</span>,<span class="pl-c1">0xc2</span>,<span class="pl-c1">0xc3</span>,<span class="pl-c1">0xc4</span>,<span class="pl-c1">0xc5</span>,<span class="pl-c1">0xc6</span>,<span class="pl-c1">0xc7</span>,<span class="pl-c1">0xc8</span>,<span class="pl-c1">0xc9</span>,<span class="pl-c1">0xca</span>,<span class="pl-c1">0xd2</span>,<span class="pl-c1">0xd3</span>,<span class="pl-c1">0xd4</span>,<span class="pl-c1">0xd5</span>,<span class="pl-c1">0xd6</span>,<span class="pl-c1">0xd7</span>,<span class="pl-c1">0xd8</span>,<span class="pl-c1">0xd9</span>,<span class="pl-c1">0xda</span>,<span class="pl-c1">0xe1</span>,<span class="pl-c1">0xe2</span>,</td>
      </tr>
      <tr>
        <td id="L1302" class="blob-num js-line-number" data-line-number="1302"></td>
        <td id="LC1302" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xe3</span>,<span class="pl-c1">0xe4</span>,<span class="pl-c1">0xe5</span>,<span class="pl-c1">0xe6</span>,<span class="pl-c1">0xe7</span>,<span class="pl-c1">0xe8</span>,<span class="pl-c1">0xe9</span>,<span class="pl-c1">0xea</span>,<span class="pl-c1">0xf1</span>,<span class="pl-c1">0xf2</span>,<span class="pl-c1">0xf3</span>,<span class="pl-c1">0xf4</span>,<span class="pl-c1">0xf5</span>,<span class="pl-c1">0xf6</span>,<span class="pl-c1">0xf7</span>,<span class="pl-c1">0xf8</span>,<span class="pl-c1">0xf9</span>,<span class="pl-c1">0xfa</span></td>
      </tr>
      <tr>
        <td id="L1303" class="blob-num js-line-number" data-line-number="1303"></td>
        <td id="LC1303" class="blob-code blob-code-inner js-file-line">   };</td>
      </tr>
      <tr>
        <td id="L1304" class="blob-num js-line-number" data-line-number="1304"></td>
        <td id="LC1304" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> std_dc_chrominance_nrcodes[] = {<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">3</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>};</td>
      </tr>
      <tr>
        <td id="L1305" class="blob-num js-line-number" data-line-number="1305"></td>
        <td id="LC1305" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> std_dc_chrominance_values[] = {<span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">2</span>,<span class="pl-c1">3</span>,<span class="pl-c1">4</span>,<span class="pl-c1">5</span>,<span class="pl-c1">6</span>,<span class="pl-c1">7</span>,<span class="pl-c1">8</span>,<span class="pl-c1">9</span>,<span class="pl-c1">10</span>,<span class="pl-c1">11</span>};</td>
      </tr>
      <tr>
        <td id="L1306" class="blob-num js-line-number" data-line-number="1306"></td>
        <td id="LC1306" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> std_ac_chrominance_nrcodes[] = {<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">2</span>,<span class="pl-c1">1</span>,<span class="pl-c1">2</span>,<span class="pl-c1">4</span>,<span class="pl-c1">4</span>,<span class="pl-c1">3</span>,<span class="pl-c1">4</span>,<span class="pl-c1">7</span>,<span class="pl-c1">5</span>,<span class="pl-c1">4</span>,<span class="pl-c1">4</span>,<span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">2</span>,<span class="pl-c1">0x77</span>};</td>
      </tr>
      <tr>
        <td id="L1307" class="blob-num js-line-number" data-line-number="1307"></td>
        <td id="LC1307" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> std_ac_chrominance_values[] = {</td>
      </tr>
      <tr>
        <td id="L1308" class="blob-num js-line-number" data-line-number="1308"></td>
        <td id="LC1308" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x00</span>,<span class="pl-c1">0x01</span>,<span class="pl-c1">0x02</span>,<span class="pl-c1">0x03</span>,<span class="pl-c1">0x11</span>,<span class="pl-c1">0x04</span>,<span class="pl-c1">0x05</span>,<span class="pl-c1">0x21</span>,<span class="pl-c1">0x31</span>,<span class="pl-c1">0x06</span>,<span class="pl-c1">0x12</span>,<span class="pl-c1">0x41</span>,<span class="pl-c1">0x51</span>,<span class="pl-c1">0x07</span>,<span class="pl-c1">0x61</span>,<span class="pl-c1">0x71</span>,<span class="pl-c1">0x13</span>,<span class="pl-c1">0x22</span>,<span class="pl-c1">0x32</span>,<span class="pl-c1">0x81</span>,<span class="pl-c1">0x08</span>,<span class="pl-c1">0x14</span>,<span class="pl-c1">0x42</span>,<span class="pl-c1">0x91</span>,</td>
      </tr>
      <tr>
        <td id="L1309" class="blob-num js-line-number" data-line-number="1309"></td>
        <td id="LC1309" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xa1</span>,<span class="pl-c1">0xb1</span>,<span class="pl-c1">0xc1</span>,<span class="pl-c1">0x09</span>,<span class="pl-c1">0x23</span>,<span class="pl-c1">0x33</span>,<span class="pl-c1">0x52</span>,<span class="pl-c1">0xf0</span>,<span class="pl-c1">0x15</span>,<span class="pl-c1">0x62</span>,<span class="pl-c1">0x72</span>,<span class="pl-c1">0xd1</span>,<span class="pl-c1">0x0a</span>,<span class="pl-c1">0x16</span>,<span class="pl-c1">0x24</span>,<span class="pl-c1">0x34</span>,<span class="pl-c1">0xe1</span>,<span class="pl-c1">0x25</span>,<span class="pl-c1">0xf1</span>,<span class="pl-c1">0x17</span>,<span class="pl-c1">0x18</span>,<span class="pl-c1">0x19</span>,<span class="pl-c1">0x1a</span>,<span class="pl-c1">0x26</span>,</td>
      </tr>
      <tr>
        <td id="L1310" class="blob-num js-line-number" data-line-number="1310"></td>
        <td id="LC1310" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x27</span>,<span class="pl-c1">0x28</span>,<span class="pl-c1">0x29</span>,<span class="pl-c1">0x2a</span>,<span class="pl-c1">0x35</span>,<span class="pl-c1">0x36</span>,<span class="pl-c1">0x37</span>,<span class="pl-c1">0x38</span>,<span class="pl-c1">0x39</span>,<span class="pl-c1">0x3a</span>,<span class="pl-c1">0x43</span>,<span class="pl-c1">0x44</span>,<span class="pl-c1">0x45</span>,<span class="pl-c1">0x46</span>,<span class="pl-c1">0x47</span>,<span class="pl-c1">0x48</span>,<span class="pl-c1">0x49</span>,<span class="pl-c1">0x4a</span>,<span class="pl-c1">0x53</span>,<span class="pl-c1">0x54</span>,<span class="pl-c1">0x55</span>,<span class="pl-c1">0x56</span>,<span class="pl-c1">0x57</span>,<span class="pl-c1">0x58</span>,</td>
      </tr>
      <tr>
        <td id="L1311" class="blob-num js-line-number" data-line-number="1311"></td>
        <td id="LC1311" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x59</span>,<span class="pl-c1">0x5a</span>,<span class="pl-c1">0x63</span>,<span class="pl-c1">0x64</span>,<span class="pl-c1">0x65</span>,<span class="pl-c1">0x66</span>,<span class="pl-c1">0x67</span>,<span class="pl-c1">0x68</span>,<span class="pl-c1">0x69</span>,<span class="pl-c1">0x6a</span>,<span class="pl-c1">0x73</span>,<span class="pl-c1">0x74</span>,<span class="pl-c1">0x75</span>,<span class="pl-c1">0x76</span>,<span class="pl-c1">0x77</span>,<span class="pl-c1">0x78</span>,<span class="pl-c1">0x79</span>,<span class="pl-c1">0x7a</span>,<span class="pl-c1">0x82</span>,<span class="pl-c1">0x83</span>,<span class="pl-c1">0x84</span>,<span class="pl-c1">0x85</span>,<span class="pl-c1">0x86</span>,<span class="pl-c1">0x87</span>,</td>
      </tr>
      <tr>
        <td id="L1312" class="blob-num js-line-number" data-line-number="1312"></td>
        <td id="LC1312" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0x88</span>,<span class="pl-c1">0x89</span>,<span class="pl-c1">0x8a</span>,<span class="pl-c1">0x92</span>,<span class="pl-c1">0x93</span>,<span class="pl-c1">0x94</span>,<span class="pl-c1">0x95</span>,<span class="pl-c1">0x96</span>,<span class="pl-c1">0x97</span>,<span class="pl-c1">0x98</span>,<span class="pl-c1">0x99</span>,<span class="pl-c1">0x9a</span>,<span class="pl-c1">0xa2</span>,<span class="pl-c1">0xa3</span>,<span class="pl-c1">0xa4</span>,<span class="pl-c1">0xa5</span>,<span class="pl-c1">0xa6</span>,<span class="pl-c1">0xa7</span>,<span class="pl-c1">0xa8</span>,<span class="pl-c1">0xa9</span>,<span class="pl-c1">0xaa</span>,<span class="pl-c1">0xb2</span>,<span class="pl-c1">0xb3</span>,<span class="pl-c1">0xb4</span>,</td>
      </tr>
      <tr>
        <td id="L1313" class="blob-num js-line-number" data-line-number="1313"></td>
        <td id="LC1313" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xb5</span>,<span class="pl-c1">0xb6</span>,<span class="pl-c1">0xb7</span>,<span class="pl-c1">0xb8</span>,<span class="pl-c1">0xb9</span>,<span class="pl-c1">0xba</span>,<span class="pl-c1">0xc2</span>,<span class="pl-c1">0xc3</span>,<span class="pl-c1">0xc4</span>,<span class="pl-c1">0xc5</span>,<span class="pl-c1">0xc6</span>,<span class="pl-c1">0xc7</span>,<span class="pl-c1">0xc8</span>,<span class="pl-c1">0xc9</span>,<span class="pl-c1">0xca</span>,<span class="pl-c1">0xd2</span>,<span class="pl-c1">0xd3</span>,<span class="pl-c1">0xd4</span>,<span class="pl-c1">0xd5</span>,<span class="pl-c1">0xd6</span>,<span class="pl-c1">0xd7</span>,<span class="pl-c1">0xd8</span>,<span class="pl-c1">0xd9</span>,<span class="pl-c1">0xda</span>,</td>
      </tr>
      <tr>
        <td id="L1314" class="blob-num js-line-number" data-line-number="1314"></td>
        <td id="LC1314" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">0xe2</span>,<span class="pl-c1">0xe3</span>,<span class="pl-c1">0xe4</span>,<span class="pl-c1">0xe5</span>,<span class="pl-c1">0xe6</span>,<span class="pl-c1">0xe7</span>,<span class="pl-c1">0xe8</span>,<span class="pl-c1">0xe9</span>,<span class="pl-c1">0xea</span>,<span class="pl-c1">0xf2</span>,<span class="pl-c1">0xf3</span>,<span class="pl-c1">0xf4</span>,<span class="pl-c1">0xf5</span>,<span class="pl-c1">0xf6</span>,<span class="pl-c1">0xf7</span>,<span class="pl-c1">0xf8</span>,<span class="pl-c1">0xf9</span>,<span class="pl-c1">0xfa</span></td>
      </tr>
      <tr>
        <td id="L1315" class="blob-num js-line-number" data-line-number="1315"></td>
        <td id="LC1315" class="blob-code blob-code-inner js-file-line">   };</td>
      </tr>
      <tr>
        <td id="L1316" class="blob-num js-line-number" data-line-number="1316"></td>
        <td id="LC1316" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> Huffman tables</span></td>
      </tr>
      <tr>
        <td id="L1317" class="blob-num js-line-number" data-line-number="1317"></td>
        <td id="LC1317" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> YDC_HT[<span class="pl-c1">256</span>][<span class="pl-c1">2</span>] = { {<span class="pl-c1">0</span>,<span class="pl-c1">2</span>},{<span class="pl-c1">2</span>,<span class="pl-c1">3</span>},{<span class="pl-c1">3</span>,<span class="pl-c1">3</span>},{<span class="pl-c1">4</span>,<span class="pl-c1">3</span>},{<span class="pl-c1">5</span>,<span class="pl-c1">3</span>},{<span class="pl-c1">6</span>,<span class="pl-c1">3</span>},{<span class="pl-c1">14</span>,<span class="pl-c1">4</span>},{<span class="pl-c1">30</span>,<span class="pl-c1">5</span>},{<span class="pl-c1">62</span>,<span class="pl-c1">6</span>},{<span class="pl-c1">126</span>,<span class="pl-c1">7</span>},{<span class="pl-c1">254</span>,<span class="pl-c1">8</span>},{<span class="pl-c1">510</span>,<span class="pl-c1">9</span>}};</td>
      </tr>
      <tr>
        <td id="L1318" class="blob-num js-line-number" data-line-number="1318"></td>
        <td id="LC1318" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> UVDC_HT[<span class="pl-c1">256</span>][<span class="pl-c1">2</span>] = { {<span class="pl-c1">0</span>,<span class="pl-c1">2</span>},{<span class="pl-c1">1</span>,<span class="pl-c1">2</span>},{<span class="pl-c1">2</span>,<span class="pl-c1">2</span>},{<span class="pl-c1">6</span>,<span class="pl-c1">3</span>},{<span class="pl-c1">14</span>,<span class="pl-c1">4</span>},{<span class="pl-c1">30</span>,<span class="pl-c1">5</span>},{<span class="pl-c1">62</span>,<span class="pl-c1">6</span>},{<span class="pl-c1">126</span>,<span class="pl-c1">7</span>},{<span class="pl-c1">254</span>,<span class="pl-c1">8</span>},{<span class="pl-c1">510</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">1022</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">2046</span>,<span class="pl-c1">11</span>}};</td>
      </tr>
      <tr>
        <td id="L1319" class="blob-num js-line-number" data-line-number="1319"></td>
        <td id="LC1319" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> YAC_HT[<span class="pl-c1">256</span>][<span class="pl-c1">2</span>] = {</td>
      </tr>
      <tr>
        <td id="L1320" class="blob-num js-line-number" data-line-number="1320"></td>
        <td id="LC1320" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">10</span>,<span class="pl-c1">4</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">2</span>},{<span class="pl-c1">1</span>,<span class="pl-c1">2</span>},{<span class="pl-c1">4</span>,<span class="pl-c1">3</span>},{<span class="pl-c1">11</span>,<span class="pl-c1">4</span>},{<span class="pl-c1">26</span>,<span class="pl-c1">5</span>},{<span class="pl-c1">120</span>,<span class="pl-c1">7</span>},{<span class="pl-c1">248</span>,<span class="pl-c1">8</span>},{<span class="pl-c1">1014</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">65410</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65411</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1321" class="blob-num js-line-number" data-line-number="1321"></td>
        <td id="LC1321" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">12</span>,<span class="pl-c1">4</span>},{<span class="pl-c1">27</span>,<span class="pl-c1">5</span>},{<span class="pl-c1">121</span>,<span class="pl-c1">7</span>},{<span class="pl-c1">502</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">2038</span>,<span class="pl-c1">11</span>},{<span class="pl-c1">65412</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65413</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65414</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65415</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65416</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1322" class="blob-num js-line-number" data-line-number="1322"></td>
        <td id="LC1322" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">28</span>,<span class="pl-c1">5</span>},{<span class="pl-c1">249</span>,<span class="pl-c1">8</span>},{<span class="pl-c1">1015</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">4084</span>,<span class="pl-c1">12</span>},{<span class="pl-c1">65417</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65418</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65419</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65420</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65421</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65422</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1323" class="blob-num js-line-number" data-line-number="1323"></td>
        <td id="LC1323" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">58</span>,<span class="pl-c1">6</span>},{<span class="pl-c1">503</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">4085</span>,<span class="pl-c1">12</span>},{<span class="pl-c1">65423</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65424</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65425</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65426</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65427</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65428</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65429</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1324" class="blob-num js-line-number" data-line-number="1324"></td>
        <td id="LC1324" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">59</span>,<span class="pl-c1">6</span>},{<span class="pl-c1">1016</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">65430</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65431</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65432</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65433</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65434</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65435</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65436</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65437</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1325" class="blob-num js-line-number" data-line-number="1325"></td>
        <td id="LC1325" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">122</span>,<span class="pl-c1">7</span>},{<span class="pl-c1">2039</span>,<span class="pl-c1">11</span>},{<span class="pl-c1">65438</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65439</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65440</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65441</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65442</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65443</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65444</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65445</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1326" class="blob-num js-line-number" data-line-number="1326"></td>
        <td id="LC1326" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">123</span>,<span class="pl-c1">7</span>},{<span class="pl-c1">4086</span>,<span class="pl-c1">12</span>},{<span class="pl-c1">65446</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65447</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65448</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65449</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65450</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65451</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65452</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65453</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1327" class="blob-num js-line-number" data-line-number="1327"></td>
        <td id="LC1327" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">250</span>,<span class="pl-c1">8</span>},{<span class="pl-c1">4087</span>,<span class="pl-c1">12</span>},{<span class="pl-c1">65454</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65455</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65456</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65457</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65458</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65459</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65460</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65461</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1328" class="blob-num js-line-number" data-line-number="1328"></td>
        <td id="LC1328" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">504</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">32704</span>,<span class="pl-c1">15</span>},{<span class="pl-c1">65462</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65463</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65464</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65465</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65466</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65467</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65468</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65469</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1329" class="blob-num js-line-number" data-line-number="1329"></td>
        <td id="LC1329" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">505</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">65470</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65471</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65472</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65473</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65474</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65475</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65476</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65477</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65478</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1330" class="blob-num js-line-number" data-line-number="1330"></td>
        <td id="LC1330" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">506</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">65479</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65480</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65481</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65482</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65483</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65484</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65485</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65486</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65487</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1331" class="blob-num js-line-number" data-line-number="1331"></td>
        <td id="LC1331" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">1017</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">65488</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65489</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65490</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65491</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65492</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65493</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65494</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65495</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65496</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1332" class="blob-num js-line-number" data-line-number="1332"></td>
        <td id="LC1332" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">1018</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">65497</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65498</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65499</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65500</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65501</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65502</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65503</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65504</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65505</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1333" class="blob-num js-line-number" data-line-number="1333"></td>
        <td id="LC1333" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">2040</span>,<span class="pl-c1">11</span>},{<span class="pl-c1">65506</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65507</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65508</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65509</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65510</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65511</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65512</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65513</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65514</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1334" class="blob-num js-line-number" data-line-number="1334"></td>
        <td id="LC1334" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">65515</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65516</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65517</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65518</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65519</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65520</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65521</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65522</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65523</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65524</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1335" class="blob-num js-line-number" data-line-number="1335"></td>
        <td id="LC1335" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">2041</span>,<span class="pl-c1">11</span>},{<span class="pl-c1">65525</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65526</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65527</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65528</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65529</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65530</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65531</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65532</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65533</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65534</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>}</td>
      </tr>
      <tr>
        <td id="L1336" class="blob-num js-line-number" data-line-number="1336"></td>
        <td id="LC1336" class="blob-code blob-code-inner js-file-line">   };</td>
      </tr>
      <tr>
        <td id="L1337" class="blob-num js-line-number" data-line-number="1337"></td>
        <td id="LC1337" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> UVAC_HT[<span class="pl-c1">256</span>][<span class="pl-c1">2</span>] = {</td>
      </tr>
      <tr>
        <td id="L1338" class="blob-num js-line-number" data-line-number="1338"></td>
        <td id="LC1338" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">0</span>,<span class="pl-c1">2</span>},{<span class="pl-c1">1</span>,<span class="pl-c1">2</span>},{<span class="pl-c1">4</span>,<span class="pl-c1">3</span>},{<span class="pl-c1">10</span>,<span class="pl-c1">4</span>},{<span class="pl-c1">24</span>,<span class="pl-c1">5</span>},{<span class="pl-c1">25</span>,<span class="pl-c1">5</span>},{<span class="pl-c1">56</span>,<span class="pl-c1">6</span>},{<span class="pl-c1">120</span>,<span class="pl-c1">7</span>},{<span class="pl-c1">500</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">1014</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">4084</span>,<span class="pl-c1">12</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1339" class="blob-num js-line-number" data-line-number="1339"></td>
        <td id="LC1339" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">11</span>,<span class="pl-c1">4</span>},{<span class="pl-c1">57</span>,<span class="pl-c1">6</span>},{<span class="pl-c1">246</span>,<span class="pl-c1">8</span>},{<span class="pl-c1">501</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">2038</span>,<span class="pl-c1">11</span>},{<span class="pl-c1">4085</span>,<span class="pl-c1">12</span>},{<span class="pl-c1">65416</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65417</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65418</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65419</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1340" class="blob-num js-line-number" data-line-number="1340"></td>
        <td id="LC1340" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">26</span>,<span class="pl-c1">5</span>},{<span class="pl-c1">247</span>,<span class="pl-c1">8</span>},{<span class="pl-c1">1015</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">4086</span>,<span class="pl-c1">12</span>},{<span class="pl-c1">32706</span>,<span class="pl-c1">15</span>},{<span class="pl-c1">65420</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65421</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65422</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65423</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65424</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1341" class="blob-num js-line-number" data-line-number="1341"></td>
        <td id="LC1341" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">27</span>,<span class="pl-c1">5</span>},{<span class="pl-c1">248</span>,<span class="pl-c1">8</span>},{<span class="pl-c1">1016</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">4087</span>,<span class="pl-c1">12</span>},{<span class="pl-c1">65425</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65426</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65427</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65428</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65429</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65430</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1342" class="blob-num js-line-number" data-line-number="1342"></td>
        <td id="LC1342" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">58</span>,<span class="pl-c1">6</span>},{<span class="pl-c1">502</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">65431</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65432</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65433</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65434</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65435</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65436</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65437</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65438</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1343" class="blob-num js-line-number" data-line-number="1343"></td>
        <td id="LC1343" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">59</span>,<span class="pl-c1">6</span>},{<span class="pl-c1">1017</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">65439</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65440</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65441</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65442</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65443</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65444</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65445</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65446</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1344" class="blob-num js-line-number" data-line-number="1344"></td>
        <td id="LC1344" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">121</span>,<span class="pl-c1">7</span>},{<span class="pl-c1">2039</span>,<span class="pl-c1">11</span>},{<span class="pl-c1">65447</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65448</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65449</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65450</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65451</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65452</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65453</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65454</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1345" class="blob-num js-line-number" data-line-number="1345"></td>
        <td id="LC1345" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">122</span>,<span class="pl-c1">7</span>},{<span class="pl-c1">2040</span>,<span class="pl-c1">11</span>},{<span class="pl-c1">65455</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65456</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65457</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65458</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65459</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65460</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65461</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65462</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1346" class="blob-num js-line-number" data-line-number="1346"></td>
        <td id="LC1346" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">249</span>,<span class="pl-c1">8</span>},{<span class="pl-c1">65463</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65464</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65465</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65466</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65467</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65468</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65469</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65470</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65471</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1347" class="blob-num js-line-number" data-line-number="1347"></td>
        <td id="LC1347" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">503</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">65472</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65473</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65474</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65475</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65476</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65477</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65478</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65479</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65480</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1348" class="blob-num js-line-number" data-line-number="1348"></td>
        <td id="LC1348" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">504</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">65481</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65482</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65483</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65484</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65485</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65486</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65487</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65488</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65489</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1349" class="blob-num js-line-number" data-line-number="1349"></td>
        <td id="LC1349" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">505</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">65490</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65491</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65492</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65493</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65494</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65495</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65496</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65497</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65498</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1350" class="blob-num js-line-number" data-line-number="1350"></td>
        <td id="LC1350" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">506</span>,<span class="pl-c1">9</span>},{<span class="pl-c1">65499</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65500</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65501</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65502</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65503</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65504</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65505</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65506</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65507</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1351" class="blob-num js-line-number" data-line-number="1351"></td>
        <td id="LC1351" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">2041</span>,<span class="pl-c1">11</span>},{<span class="pl-c1">65508</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65509</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65510</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65511</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65512</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65513</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65514</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65515</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65516</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1352" class="blob-num js-line-number" data-line-number="1352"></td>
        <td id="LC1352" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">16352</span>,<span class="pl-c1">14</span>},{<span class="pl-c1">65517</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65518</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65519</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65520</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65521</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65522</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65523</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65524</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65525</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},</td>
      </tr>
      <tr>
        <td id="L1353" class="blob-num js-line-number" data-line-number="1353"></td>
        <td id="LC1353" class="blob-code blob-code-inner js-file-line">      {<span class="pl-c1">1018</span>,<span class="pl-c1">10</span>},{<span class="pl-c1">32707</span>,<span class="pl-c1">15</span>},{<span class="pl-c1">65526</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65527</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65528</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65529</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65530</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65531</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65532</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65533</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">65534</span>,<span class="pl-c1">16</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>},{<span class="pl-c1">0</span>,<span class="pl-c1">0</span>}</td>
      </tr>
      <tr>
        <td id="L1354" class="blob-num js-line-number" data-line-number="1354"></td>
        <td id="LC1354" class="blob-code blob-code-inner js-file-line">   };</td>
      </tr>
      <tr>
        <td id="L1355" class="blob-num js-line-number" data-line-number="1355"></td>
        <td id="LC1355" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">int</span> YQT[] = {<span class="pl-c1">16</span>,<span class="pl-c1">11</span>,<span class="pl-c1">10</span>,<span class="pl-c1">16</span>,<span class="pl-c1">24</span>,<span class="pl-c1">40</span>,<span class="pl-c1">51</span>,<span class="pl-c1">61</span>,<span class="pl-c1">12</span>,<span class="pl-c1">12</span>,<span class="pl-c1">14</span>,<span class="pl-c1">19</span>,<span class="pl-c1">26</span>,<span class="pl-c1">58</span>,<span class="pl-c1">60</span>,<span class="pl-c1">55</span>,<span class="pl-c1">14</span>,<span class="pl-c1">13</span>,<span class="pl-c1">16</span>,<span class="pl-c1">24</span>,<span class="pl-c1">40</span>,<span class="pl-c1">57</span>,<span class="pl-c1">69</span>,<span class="pl-c1">56</span>,<span class="pl-c1">14</span>,<span class="pl-c1">17</span>,<span class="pl-c1">22</span>,<span class="pl-c1">29</span>,<span class="pl-c1">51</span>,<span class="pl-c1">87</span>,<span class="pl-c1">80</span>,<span class="pl-c1">62</span>,<span class="pl-c1">18</span>,<span class="pl-c1">22</span>,</td>
      </tr>
      <tr>
        <td id="L1356" class="blob-num js-line-number" data-line-number="1356"></td>
        <td id="LC1356" class="blob-code blob-code-inner js-file-line">                             <span class="pl-c1">37</span>,<span class="pl-c1">56</span>,<span class="pl-c1">68</span>,<span class="pl-c1">109</span>,<span class="pl-c1">103</span>,<span class="pl-c1">77</span>,<span class="pl-c1">24</span>,<span class="pl-c1">35</span>,<span class="pl-c1">55</span>,<span class="pl-c1">64</span>,<span class="pl-c1">81</span>,<span class="pl-c1">104</span>,<span class="pl-c1">113</span>,<span class="pl-c1">92</span>,<span class="pl-c1">49</span>,<span class="pl-c1">64</span>,<span class="pl-c1">78</span>,<span class="pl-c1">87</span>,<span class="pl-c1">103</span>,<span class="pl-c1">121</span>,<span class="pl-c1">120</span>,<span class="pl-c1">101</span>,<span class="pl-c1">72</span>,<span class="pl-c1">92</span>,<span class="pl-c1">95</span>,<span class="pl-c1">98</span>,<span class="pl-c1">112</span>,<span class="pl-c1">100</span>,<span class="pl-c1">103</span>,<span class="pl-c1">99</span>};</td>
      </tr>
      <tr>
        <td id="L1357" class="blob-num js-line-number" data-line-number="1357"></td>
        <td id="LC1357" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">int</span> UVQT[] = {<span class="pl-c1">17</span>,<span class="pl-c1">18</span>,<span class="pl-c1">24</span>,<span class="pl-c1">47</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">18</span>,<span class="pl-c1">21</span>,<span class="pl-c1">26</span>,<span class="pl-c1">66</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">24</span>,<span class="pl-c1">26</span>,<span class="pl-c1">56</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">47</span>,<span class="pl-c1">66</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,</td>
      </tr>
      <tr>
        <td id="L1358" class="blob-num js-line-number" data-line-number="1358"></td>
        <td id="LC1358" class="blob-code blob-code-inner js-file-line">                              <span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>,<span class="pl-c1">99</span>};</td>
      </tr>
      <tr>
        <td id="L1359" class="blob-num js-line-number" data-line-number="1359"></td>
        <td id="LC1359" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">float</span> aasf[] = { <span class="pl-c1">1</span>.<span class="pl-c1">0f</span> * <span class="pl-c1">2</span>.<span class="pl-c1">828427125f</span>, <span class="pl-c1">1</span>.<span class="pl-c1">387039845f</span> * <span class="pl-c1">2</span>.<span class="pl-c1">828427125f</span>, <span class="pl-c1">1</span>.<span class="pl-c1">306562965f</span> * <span class="pl-c1">2</span>.<span class="pl-c1">828427125f</span>, <span class="pl-c1">1</span>.<span class="pl-c1">175875602f</span> * <span class="pl-c1">2</span>.<span class="pl-c1">828427125f</span>, </td>
      </tr>
      <tr>
        <td id="L1360" class="blob-num js-line-number" data-line-number="1360"></td>
        <td id="LC1360" class="blob-code blob-code-inner js-file-line">                                 <span class="pl-c1">1</span>.<span class="pl-c1">0f</span> * <span class="pl-c1">2</span>.<span class="pl-c1">828427125f</span>, <span class="pl-c1">0</span>.<span class="pl-c1">785694958f</span> * <span class="pl-c1">2</span>.<span class="pl-c1">828427125f</span>, <span class="pl-c1">0</span>.<span class="pl-c1">541196100f</span> * <span class="pl-c1">2</span>.<span class="pl-c1">828427125f</span>, <span class="pl-c1">0</span>.<span class="pl-c1">275899379f</span> * <span class="pl-c1">2</span>.<span class="pl-c1">828427125f</span> };</td>
      </tr>
      <tr>
        <td id="L1361" class="blob-num js-line-number" data-line-number="1361"></td>
        <td id="LC1361" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1362" class="blob-num js-line-number" data-line-number="1362"></td>
        <td id="LC1362" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">int</span> row, col, i, k;</td>
      </tr>
      <tr>
        <td id="L1363" class="blob-num js-line-number" data-line-number="1363"></td>
        <td id="LC1363" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">float</span> fdtbl_Y[<span class="pl-c1">64</span>], fdtbl_UV[<span class="pl-c1">64</span>];</td>
      </tr>
      <tr>
        <td id="L1364" class="blob-num js-line-number" data-line-number="1364"></td>
        <td id="LC1364" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">unsigned</span> <span class="pl-k">char</span> YTable[<span class="pl-c1">64</span>], UVTable[<span class="pl-c1">64</span>];</td>
      </tr>
      <tr>
        <td id="L1365" class="blob-num js-line-number" data-line-number="1365"></td>
        <td id="LC1365" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1366" class="blob-num js-line-number" data-line-number="1366"></td>
        <td id="LC1366" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span>(!data || !width || !height || comp &gt; <span class="pl-c1">4</span> || comp &lt; <span class="pl-c1">1</span>) {</td>
      </tr>
      <tr>
        <td id="L1367" class="blob-num js-line-number" data-line-number="1367"></td>
        <td id="LC1367" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1368" class="blob-num js-line-number" data-line-number="1368"></td>
        <td id="LC1368" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1369" class="blob-num js-line-number" data-line-number="1369"></td>
        <td id="LC1369" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1370" class="blob-num js-line-number" data-line-number="1370"></td>
        <td id="LC1370" class="blob-code blob-code-inner js-file-line">   quality = quality ? quality : <span class="pl-c1">90</span>;</td>
      </tr>
      <tr>
        <td id="L1371" class="blob-num js-line-number" data-line-number="1371"></td>
        <td id="LC1371" class="blob-code blob-code-inner js-file-line">   quality = quality &lt; <span class="pl-c1">1</span> ? <span class="pl-c1">1</span> : quality &gt; <span class="pl-c1">100</span> ? <span class="pl-c1">100</span> : quality;</td>
      </tr>
      <tr>
        <td id="L1372" class="blob-num js-line-number" data-line-number="1372"></td>
        <td id="LC1372" class="blob-code blob-code-inner js-file-line">   quality = quality &lt; <span class="pl-c1">50</span> ? <span class="pl-c1">5000</span> / quality : <span class="pl-c1">200</span> - quality * <span class="pl-c1">2</span>;</td>
      </tr>
      <tr>
        <td id="L1373" class="blob-num js-line-number" data-line-number="1373"></td>
        <td id="LC1373" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1374" class="blob-num js-line-number" data-line-number="1374"></td>
        <td id="LC1374" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span>(i = <span class="pl-c1">0</span>; i &lt; <span class="pl-c1">64</span>; ++i) {</td>
      </tr>
      <tr>
        <td id="L1375" class="blob-num js-line-number" data-line-number="1375"></td>
        <td id="LC1375" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> uvti, yti = (YQT[i]*quality+<span class="pl-c1">50</span>)/<span class="pl-c1">100</span>;</td>
      </tr>
      <tr>
        <td id="L1376" class="blob-num js-line-number" data-line-number="1376"></td>
        <td id="LC1376" class="blob-code blob-code-inner js-file-line">      YTable[stbiw__jpg_ZigZag[i]] = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span>) (yti &lt; <span class="pl-c1">1</span> ? <span class="pl-c1">1</span> : yti &gt; <span class="pl-c1">255</span> ? <span class="pl-c1">255</span> : yti);</td>
      </tr>
      <tr>
        <td id="L1377" class="blob-num js-line-number" data-line-number="1377"></td>
        <td id="LC1377" class="blob-code blob-code-inner js-file-line">      uvti = (UVQT[i]*quality+<span class="pl-c1">50</span>)/<span class="pl-c1">100</span>;</td>
      </tr>
      <tr>
        <td id="L1378" class="blob-num js-line-number" data-line-number="1378"></td>
        <td id="LC1378" class="blob-code blob-code-inner js-file-line">      UVTable[stbiw__jpg_ZigZag[i]] = (<span class="pl-k">unsigned</span> <span class="pl-k">char</span>) (uvti &lt; <span class="pl-c1">1</span> ? <span class="pl-c1">1</span> : uvti &gt; <span class="pl-c1">255</span> ? <span class="pl-c1">255</span> : uvti);</td>
      </tr>
      <tr>
        <td id="L1379" class="blob-num js-line-number" data-line-number="1379"></td>
        <td id="LC1379" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1380" class="blob-num js-line-number" data-line-number="1380"></td>
        <td id="LC1380" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1381" class="blob-num js-line-number" data-line-number="1381"></td>
        <td id="LC1381" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">for</span>(row = <span class="pl-c1">0</span>, k = <span class="pl-c1">0</span>; row &lt; <span class="pl-c1">8</span>; ++row) {</td>
      </tr>
      <tr>
        <td id="L1382" class="blob-num js-line-number" data-line-number="1382"></td>
        <td id="LC1382" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span>(col = <span class="pl-c1">0</span>; col &lt; <span class="pl-c1">8</span>; ++col, ++k) {</td>
      </tr>
      <tr>
        <td id="L1383" class="blob-num js-line-number" data-line-number="1383"></td>
        <td id="LC1383" class="blob-code blob-code-inner js-file-line">         fdtbl_Y[k]  = <span class="pl-c1">1</span> / (YTable [stbiw__jpg_ZigZag[k]] * aasf[row] * aasf[col]);</td>
      </tr>
      <tr>
        <td id="L1384" class="blob-num js-line-number" data-line-number="1384"></td>
        <td id="LC1384" class="blob-code blob-code-inner js-file-line">         fdtbl_UV[k] = <span class="pl-c1">1</span> / (UVTable[stbiw__jpg_ZigZag[k]] * aasf[row] * aasf[col]);</td>
      </tr>
      <tr>
        <td id="L1385" class="blob-num js-line-number" data-line-number="1385"></td>
        <td id="LC1385" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1386" class="blob-num js-line-number" data-line-number="1386"></td>
        <td id="LC1386" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1387" class="blob-num js-line-number" data-line-number="1387"></td>
        <td id="LC1387" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1388" class="blob-num js-line-number" data-line-number="1388"></td>
        <td id="LC1388" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> Write Headers</span></td>
      </tr>
      <tr>
        <td id="L1389" class="blob-num js-line-number" data-line-number="1389"></td>
        <td id="LC1389" class="blob-code blob-code-inner js-file-line">   {</td>
      </tr>
      <tr>
        <td id="L1390" class="blob-num js-line-number" data-line-number="1390"></td>
        <td id="LC1390" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> head0[] = { <span class="pl-c1">0xFF</span>,<span class="pl-c1">0xD8</span>,<span class="pl-c1">0xFF</span>,<span class="pl-c1">0xE0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0x10</span>,<span class="pl-s"><span class="pl-pds">&#39;</span>J<span class="pl-pds">&#39;</span></span>,<span class="pl-s"><span class="pl-pds">&#39;</span>F<span class="pl-pds">&#39;</span></span>,<span class="pl-s"><span class="pl-pds">&#39;</span>I<span class="pl-pds">&#39;</span></span>,<span class="pl-s"><span class="pl-pds">&#39;</span>F<span class="pl-pds">&#39;</span></span>,<span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">1</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">0</span>,<span class="pl-c1">1</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0xFF</span>,<span class="pl-c1">0xDB</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0x84</span>,<span class="pl-c1">0</span> };</td>
      </tr>
      <tr>
        <td id="L1391" class="blob-num js-line-number" data-line-number="1391"></td>
        <td id="LC1391" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> head2[] = { <span class="pl-c1">0xFF</span>,<span class="pl-c1">0xDA</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0xC</span>,<span class="pl-c1">3</span>,<span class="pl-c1">1</span>,<span class="pl-c1">0</span>,<span class="pl-c1">2</span>,<span class="pl-c1">0x11</span>,<span class="pl-c1">3</span>,<span class="pl-c1">0x11</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0x3F</span>,<span class="pl-c1">0</span> };</td>
      </tr>
      <tr>
        <td id="L1392" class="blob-num js-line-number" data-line-number="1392"></td>
        <td id="LC1392" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> head1[] = { <span class="pl-c1">0xFF</span>,<span class="pl-c1">0xC0</span>,<span class="pl-c1">0</span>,<span class="pl-c1">0x11</span>,<span class="pl-c1">8</span>,(<span class="pl-k">unsigned</span> <span class="pl-k">char</span>)(height&gt;&gt;<span class="pl-c1">8</span>),<span class="pl-c1">STBIW_UCHAR</span>(height),(<span class="pl-k">unsigned</span> <span class="pl-k">char</span>)(width&gt;&gt;<span class="pl-c1">8</span>),<span class="pl-c1">STBIW_UCHAR</span>(width),</td>
      </tr>
      <tr>
        <td id="L1393" class="blob-num js-line-number" data-line-number="1393"></td>
        <td id="LC1393" class="blob-code blob-code-inner js-file-line">                                      <span class="pl-c1">3</span>,<span class="pl-c1">1</span>,<span class="pl-c1">0x11</span>,<span class="pl-c1">0</span>,<span class="pl-c1">2</span>,<span class="pl-c1">0x11</span>,<span class="pl-c1">1</span>,<span class="pl-c1">3</span>,<span class="pl-c1">0x11</span>,<span class="pl-c1">1</span>,<span class="pl-c1">0xFF</span>,<span class="pl-c1">0xC4</span>,<span class="pl-c1">0x01</span>,<span class="pl-c1">0xA2</span>,<span class="pl-c1">0</span> };</td>
      </tr>
      <tr>
        <td id="L1394" class="blob-num js-line-number" data-line-number="1394"></td>
        <td id="LC1394" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)head0, <span class="pl-k">sizeof</span>(head0));</td>
      </tr>
      <tr>
        <td id="L1395" class="blob-num js-line-number" data-line-number="1395"></td>
        <td id="LC1395" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)YTable, <span class="pl-k">sizeof</span>(YTable));</td>
      </tr>
      <tr>
        <td id="L1396" class="blob-num js-line-number" data-line-number="1396"></td>
        <td id="LC1396" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__putc</span>(s, <span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L1397" class="blob-num js-line-number" data-line-number="1397"></td>
        <td id="LC1397" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, UVTable, <span class="pl-k">sizeof</span>(UVTable));</td>
      </tr>
      <tr>
        <td id="L1398" class="blob-num js-line-number" data-line-number="1398"></td>
        <td id="LC1398" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)head1, <span class="pl-k">sizeof</span>(head1));</td>
      </tr>
      <tr>
        <td id="L1399" class="blob-num js-line-number" data-line-number="1399"></td>
        <td id="LC1399" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)(std_dc_luminance_nrcodes+<span class="pl-c1">1</span>), <span class="pl-k">sizeof</span>(std_dc_luminance_nrcodes)-<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L1400" class="blob-num js-line-number" data-line-number="1400"></td>
        <td id="LC1400" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)std_dc_luminance_values, <span class="pl-k">sizeof</span>(std_dc_luminance_values));</td>
      </tr>
      <tr>
        <td id="L1401" class="blob-num js-line-number" data-line-number="1401"></td>
        <td id="LC1401" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__putc</span>(s, <span class="pl-c1">0x10</span>); <span class="pl-c"><span class="pl-c">//</span> HTYACinfo</span></td>
      </tr>
      <tr>
        <td id="L1402" class="blob-num js-line-number" data-line-number="1402"></td>
        <td id="LC1402" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)(std_ac_luminance_nrcodes+<span class="pl-c1">1</span>), <span class="pl-k">sizeof</span>(std_ac_luminance_nrcodes)-<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L1403" class="blob-num js-line-number" data-line-number="1403"></td>
        <td id="LC1403" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)std_ac_luminance_values, <span class="pl-k">sizeof</span>(std_ac_luminance_values));</td>
      </tr>
      <tr>
        <td id="L1404" class="blob-num js-line-number" data-line-number="1404"></td>
        <td id="LC1404" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__putc</span>(s, <span class="pl-c1">1</span>); <span class="pl-c"><span class="pl-c">//</span> HTUDCinfo</span></td>
      </tr>
      <tr>
        <td id="L1405" class="blob-num js-line-number" data-line-number="1405"></td>
        <td id="LC1405" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)(std_dc_chrominance_nrcodes+<span class="pl-c1">1</span>), <span class="pl-k">sizeof</span>(std_dc_chrominance_nrcodes)-<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L1406" class="blob-num js-line-number" data-line-number="1406"></td>
        <td id="LC1406" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)std_dc_chrominance_values, <span class="pl-k">sizeof</span>(std_dc_chrominance_values));</td>
      </tr>
      <tr>
        <td id="L1407" class="blob-num js-line-number" data-line-number="1407"></td>
        <td id="LC1407" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__putc</span>(s, <span class="pl-c1">0x11</span>); <span class="pl-c"><span class="pl-c">//</span> HTUACinfo</span></td>
      </tr>
      <tr>
        <td id="L1408" class="blob-num js-line-number" data-line-number="1408"></td>
        <td id="LC1408" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)(std_ac_chrominance_nrcodes+<span class="pl-c1">1</span>), <span class="pl-k">sizeof</span>(std_ac_chrominance_nrcodes)-<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="L1409" class="blob-num js-line-number" data-line-number="1409"></td>
        <td id="LC1409" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)std_ac_chrominance_values, <span class="pl-k">sizeof</span>(std_ac_chrominance_values));</td>
      </tr>
      <tr>
        <td id="L1410" class="blob-num js-line-number" data-line-number="1410"></td>
        <td id="LC1410" class="blob-code blob-code-inner js-file-line">      s-&gt;<span class="pl-c1">func</span>(s-&gt;<span class="pl-smi">context</span>, (<span class="pl-k">void</span>*)head2, <span class="pl-k">sizeof</span>(head2));</td>
      </tr>
      <tr>
        <td id="L1411" class="blob-num js-line-number" data-line-number="1411"></td>
        <td id="LC1411" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1412" class="blob-num js-line-number" data-line-number="1412"></td>
        <td id="LC1412" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1413" class="blob-num js-line-number" data-line-number="1413"></td>
        <td id="LC1413" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> Encode 8x8 macroblocks</span></td>
      </tr>
      <tr>
        <td id="L1414" class="blob-num js-line-number" data-line-number="1414"></td>
        <td id="LC1414" class="blob-code blob-code-inner js-file-line">   {</td>
      </tr>
      <tr>
        <td id="L1415" class="blob-num js-line-number" data-line-number="1415"></td>
        <td id="LC1415" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">static</span> <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">short</span> fillBits[] = {<span class="pl-c1">0x7F</span>, <span class="pl-c1">7</span>};</td>
      </tr>
      <tr>
        <td id="L1416" class="blob-num js-line-number" data-line-number="1416"></td>
        <td id="LC1416" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *imageData = (<span class="pl-k">const</span> <span class="pl-k">unsigned</span> <span class="pl-k">char</span> *)data;</td>
      </tr>
      <tr>
        <td id="L1417" class="blob-num js-line-number" data-line-number="1417"></td>
        <td id="LC1417" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> DCY=<span class="pl-c1">0</span>, DCU=<span class="pl-c1">0</span>, DCV=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1418" class="blob-num js-line-number" data-line-number="1418"></td>
        <td id="LC1418" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> bitBuf=<span class="pl-c1">0</span>, bitCnt=<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1419" class="blob-num js-line-number" data-line-number="1419"></td>
        <td id="LC1419" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> comp == 2 is grey+alpha (alpha is ignored)</span></td>
      </tr>
      <tr>
        <td id="L1420" class="blob-num js-line-number" data-line-number="1420"></td>
        <td id="LC1420" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> ofsG = comp &gt; <span class="pl-c1">2</span> ? <span class="pl-c1">1</span> : <span class="pl-c1">0</span>, ofsB = comp &gt; <span class="pl-c1">2</span> ? <span class="pl-c1">2</span> : <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1421" class="blob-num js-line-number" data-line-number="1421"></td>
        <td id="LC1421" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> x, y, pos;</td>
      </tr>
      <tr>
        <td id="L1422" class="blob-num js-line-number" data-line-number="1422"></td>
        <td id="LC1422" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">for</span>(y = <span class="pl-c1">0</span>; y &lt; height; y += <span class="pl-c1">8</span>) {</td>
      </tr>
      <tr>
        <td id="L1423" class="blob-num js-line-number" data-line-number="1423"></td>
        <td id="LC1423" class="blob-code blob-code-inner js-file-line">         <span class="pl-k">for</span>(x = <span class="pl-c1">0</span>; x &lt; width; x += <span class="pl-c1">8</span>) {</td>
      </tr>
      <tr>
        <td id="L1424" class="blob-num js-line-number" data-line-number="1424"></td>
        <td id="LC1424" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">float</span> YDU[<span class="pl-c1">64</span>], UDU[<span class="pl-c1">64</span>], VDU[<span class="pl-c1">64</span>];</td>
      </tr>
      <tr>
        <td id="L1425" class="blob-num js-line-number" data-line-number="1425"></td>
        <td id="LC1425" class="blob-code blob-code-inner js-file-line">            <span class="pl-k">for</span>(row = y, pos = <span class="pl-c1">0</span>; row &lt; y+<span class="pl-c1">8</span>; ++row) {</td>
      </tr>
      <tr>
        <td id="L1426" class="blob-num js-line-number" data-line-number="1426"></td>
        <td id="LC1426" class="blob-code blob-code-inner js-file-line">               <span class="pl-k">for</span>(col = x; col &lt; x+<span class="pl-c1">8</span>; ++col, ++pos) {</td>
      </tr>
      <tr>
        <td id="L1427" class="blob-num js-line-number" data-line-number="1427"></td>
        <td id="LC1427" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">int</span> p = (stbi__flip_vertically_on_write ? height-<span class="pl-c1">1</span>-row : row)*width*comp + col*comp;</td>
      </tr>
      <tr>
        <td id="L1428" class="blob-num js-line-number" data-line-number="1428"></td>
        <td id="LC1428" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">float</span> r, g, b;</td>
      </tr>
      <tr>
        <td id="L1429" class="blob-num js-line-number" data-line-number="1429"></td>
        <td id="LC1429" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">if</span>(row &gt;= height) {</td>
      </tr>
      <tr>
        <td id="L1430" class="blob-num js-line-number" data-line-number="1430"></td>
        <td id="LC1430" class="blob-code blob-code-inner js-file-line">                     p -= width*comp*(row+<span class="pl-c1">1</span> - height);</td>
      </tr>
      <tr>
        <td id="L1431" class="blob-num js-line-number" data-line-number="1431"></td>
        <td id="LC1431" class="blob-code blob-code-inner js-file-line">                  }</td>
      </tr>
      <tr>
        <td id="L1432" class="blob-num js-line-number" data-line-number="1432"></td>
        <td id="LC1432" class="blob-code blob-code-inner js-file-line">                  <span class="pl-k">if</span>(col &gt;= width) {</td>
      </tr>
      <tr>
        <td id="L1433" class="blob-num js-line-number" data-line-number="1433"></td>
        <td id="LC1433" class="blob-code blob-code-inner js-file-line">                     p -= comp*(col+<span class="pl-c1">1</span> - width);</td>
      </tr>
      <tr>
        <td id="L1434" class="blob-num js-line-number" data-line-number="1434"></td>
        <td id="LC1434" class="blob-code blob-code-inner js-file-line">                  }</td>
      </tr>
      <tr>
        <td id="L1435" class="blob-num js-line-number" data-line-number="1435"></td>
        <td id="LC1435" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1436" class="blob-num js-line-number" data-line-number="1436"></td>
        <td id="LC1436" class="blob-code blob-code-inner js-file-line">                  r = imageData[p+<span class="pl-c1">0</span>];</td>
      </tr>
      <tr>
        <td id="L1437" class="blob-num js-line-number" data-line-number="1437"></td>
        <td id="LC1437" class="blob-code blob-code-inner js-file-line">                  g = imageData[p+ofsG];</td>
      </tr>
      <tr>
        <td id="L1438" class="blob-num js-line-number" data-line-number="1438"></td>
        <td id="LC1438" class="blob-code blob-code-inner js-file-line">                  b = imageData[p+ofsB];</td>
      </tr>
      <tr>
        <td id="L1439" class="blob-num js-line-number" data-line-number="1439"></td>
        <td id="LC1439" class="blob-code blob-code-inner js-file-line">                  YDU[pos]=+<span class="pl-c1">0</span>.<span class="pl-c1">29900f</span>*r+<span class="pl-c1">0</span>.<span class="pl-c1">58700f</span>*g+<span class="pl-c1">0</span>.<span class="pl-c1">11400f</span>*b-<span class="pl-c1">128</span>;</td>
      </tr>
      <tr>
        <td id="L1440" class="blob-num js-line-number" data-line-number="1440"></td>
        <td id="LC1440" class="blob-code blob-code-inner js-file-line">                  UDU[pos]=-<span class="pl-c1">0</span>.<span class="pl-c1">16874f</span>*r-<span class="pl-c1">0</span>.<span class="pl-c1">33126f</span>*g+<span class="pl-c1">0</span>.<span class="pl-c1">50000f</span>*b;</td>
      </tr>
      <tr>
        <td id="L1441" class="blob-num js-line-number" data-line-number="1441"></td>
        <td id="LC1441" class="blob-code blob-code-inner js-file-line">                  VDU[pos]=+<span class="pl-c1">0</span>.<span class="pl-c1">50000f</span>*r-<span class="pl-c1">0</span>.<span class="pl-c1">41869f</span>*g-<span class="pl-c1">0</span>.<span class="pl-c1">08131f</span>*b;</td>
      </tr>
      <tr>
        <td id="L1442" class="blob-num js-line-number" data-line-number="1442"></td>
        <td id="LC1442" class="blob-code blob-code-inner js-file-line">               }</td>
      </tr>
      <tr>
        <td id="L1443" class="blob-num js-line-number" data-line-number="1443"></td>
        <td id="LC1443" class="blob-code blob-code-inner js-file-line">            }</td>
      </tr>
      <tr>
        <td id="L1444" class="blob-num js-line-number" data-line-number="1444"></td>
        <td id="LC1444" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1445" class="blob-num js-line-number" data-line-number="1445"></td>
        <td id="LC1445" class="blob-code blob-code-inner js-file-line">            DCY = <span class="pl-c1">stbiw__jpg_processDU</span>(s, &amp;bitBuf, &amp;bitCnt, YDU, fdtbl_Y, DCY, YDC_HT, YAC_HT);</td>
      </tr>
      <tr>
        <td id="L1446" class="blob-num js-line-number" data-line-number="1446"></td>
        <td id="LC1446" class="blob-code blob-code-inner js-file-line">            DCU = <span class="pl-c1">stbiw__jpg_processDU</span>(s, &amp;bitBuf, &amp;bitCnt, UDU, fdtbl_UV, DCU, UVDC_HT, UVAC_HT);</td>
      </tr>
      <tr>
        <td id="L1447" class="blob-num js-line-number" data-line-number="1447"></td>
        <td id="LC1447" class="blob-code blob-code-inner js-file-line">            DCV = <span class="pl-c1">stbiw__jpg_processDU</span>(s, &amp;bitBuf, &amp;bitCnt, VDU, fdtbl_UV, DCV, UVDC_HT, UVAC_HT);</td>
      </tr>
      <tr>
        <td id="L1448" class="blob-num js-line-number" data-line-number="1448"></td>
        <td id="LC1448" class="blob-code blob-code-inner js-file-line">         }</td>
      </tr>
      <tr>
        <td id="L1449" class="blob-num js-line-number" data-line-number="1449"></td>
        <td id="LC1449" class="blob-code blob-code-inner js-file-line">      }</td>
      </tr>
      <tr>
        <td id="L1450" class="blob-num js-line-number" data-line-number="1450"></td>
        <td id="LC1450" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1451" class="blob-num js-line-number" data-line-number="1451"></td>
        <td id="LC1451" class="blob-code blob-code-inner js-file-line">      <span class="pl-c"><span class="pl-c">//</span> Do the bit alignment of the EOI marker</span></td>
      </tr>
      <tr>
        <td id="L1452" class="blob-num js-line-number" data-line-number="1452"></td>
        <td id="LC1452" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbiw__jpg_writeBits</span>(s, &amp;bitBuf, &amp;bitCnt, fillBits);</td>
      </tr>
      <tr>
        <td id="L1453" class="blob-num js-line-number" data-line-number="1453"></td>
        <td id="LC1453" class="blob-code blob-code-inner js-file-line">   }</td>
      </tr>
      <tr>
        <td id="L1454" class="blob-num js-line-number" data-line-number="1454"></td>
        <td id="LC1454" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1455" class="blob-num js-line-number" data-line-number="1455"></td>
        <td id="LC1455" class="blob-code blob-code-inner js-file-line">   <span class="pl-c"><span class="pl-c">//</span> EOI</span></td>
      </tr>
      <tr>
        <td id="L1456" class="blob-num js-line-number" data-line-number="1456"></td>
        <td id="LC1456" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__putc</span>(s, <span class="pl-c1">0xFF</span>);</td>
      </tr>
      <tr>
        <td id="L1457" class="blob-num js-line-number" data-line-number="1457"></td>
        <td id="LC1457" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbiw__putc</span>(s, <span class="pl-c1">0xD9</span>);</td>
      </tr>
      <tr>
        <td id="L1458" class="blob-num js-line-number" data-line-number="1458"></td>
        <td id="LC1458" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1459" class="blob-num js-line-number" data-line-number="1459"></td>
        <td id="LC1459" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">1</span>;</td>
      </tr>
      <tr>
        <td id="L1460" class="blob-num js-line-number" data-line-number="1460"></td>
        <td id="LC1460" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1461" class="blob-num js-line-number" data-line-number="1461"></td>
        <td id="LC1461" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1462" class="blob-num js-line-number" data-line-number="1462"></td>
        <td id="LC1462" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_jpg_to_func</span>(stbi_write_func *func, <span class="pl-k">void</span> *context, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span> *data, <span class="pl-k">int</span> quality)</td>
      </tr>
      <tr>
        <td id="L1463" class="blob-num js-line-number" data-line-number="1463"></td>
        <td id="LC1463" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L1464" class="blob-num js-line-number" data-line-number="1464"></td>
        <td id="LC1464" class="blob-code blob-code-inner js-file-line">   stbi__write_context s;</td>
      </tr>
      <tr>
        <td id="L1465" class="blob-num js-line-number" data-line-number="1465"></td>
        <td id="LC1465" class="blob-code blob-code-inner js-file-line">   <span class="pl-c1">stbi__start_write_callbacks</span>(&amp;s, func, context);</td>
      </tr>
      <tr>
        <td id="L1466" class="blob-num js-line-number" data-line-number="1466"></td>
        <td id="LC1466" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">return</span> <span class="pl-c1">stbi_write_jpg_core</span>(&amp;s, x, y, comp, (<span class="pl-k">void</span> *) data, quality);</td>
      </tr>
      <tr>
        <td id="L1467" class="blob-num js-line-number" data-line-number="1467"></td>
        <td id="LC1467" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1468" class="blob-num js-line-number" data-line-number="1468"></td>
        <td id="LC1468" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1469" class="blob-num js-line-number" data-line-number="1469"></td>
        <td id="LC1469" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1470" class="blob-num js-line-number" data-line-number="1470"></td>
        <td id="LC1470" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">ifndef</span> STBI_WRITE_NO_STDIO</td>
      </tr>
      <tr>
        <td id="L1471" class="blob-num js-line-number" data-line-number="1471"></td>
        <td id="LC1471" class="blob-code blob-code-inner js-file-line">STBIWDEF <span class="pl-k">int</span> <span class="pl-en">stbi_write_jpg</span>(<span class="pl-k">char</span> <span class="pl-k">const</span> *filename, <span class="pl-k">int</span> x, <span class="pl-k">int</span> y, <span class="pl-k">int</span> comp, <span class="pl-k">const</span> <span class="pl-k">void</span> *data, <span class="pl-k">int</span> quality)</td>
      </tr>
      <tr>
        <td id="L1472" class="blob-num js-line-number" data-line-number="1472"></td>
        <td id="LC1472" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="L1473" class="blob-num js-line-number" data-line-number="1473"></td>
        <td id="LC1473" class="blob-code blob-code-inner js-file-line">   stbi__write_context s;</td>
      </tr>
      <tr>
        <td id="L1474" class="blob-num js-line-number" data-line-number="1474"></td>
        <td id="LC1474" class="blob-code blob-code-inner js-file-line">   <span class="pl-k">if</span> (<span class="pl-c1">stbi__start_write_file</span>(&amp;s,filename)) {</td>
      </tr>
      <tr>
        <td id="L1475" class="blob-num js-line-number" data-line-number="1475"></td>
        <td id="LC1475" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">int</span> r = <span class="pl-c1">stbi_write_jpg_core</span>(&amp;s, x, y, comp, data, quality);</td>
      </tr>
      <tr>
        <td id="L1476" class="blob-num js-line-number" data-line-number="1476"></td>
        <td id="LC1476" class="blob-code blob-code-inner js-file-line">      <span class="pl-c1">stbi__end_write_file</span>(&amp;s);</td>
      </tr>
      <tr>
        <td id="L1477" class="blob-num js-line-number" data-line-number="1477"></td>
        <td id="LC1477" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> r;</td>
      </tr>
      <tr>
        <td id="L1478" class="blob-num js-line-number" data-line-number="1478"></td>
        <td id="LC1478" class="blob-code blob-code-inner js-file-line">   } <span class="pl-k">else</span></td>
      </tr>
      <tr>
        <td id="L1479" class="blob-num js-line-number" data-line-number="1479"></td>
        <td id="LC1479" class="blob-code blob-code-inner js-file-line">      <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="L1480" class="blob-num js-line-number" data-line-number="1480"></td>
        <td id="LC1480" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="L1481" class="blob-num js-line-number" data-line-number="1481"></td>
        <td id="LC1481" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span></td>
      </tr>
      <tr>
        <td id="L1482" class="blob-num js-line-number" data-line-number="1482"></td>
        <td id="LC1482" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1483" class="blob-num js-line-number" data-line-number="1483"></td>
        <td id="LC1483" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">endif</span> <span class="pl-c"><span class="pl-c">//</span> STB_IMAGE_WRITE_IMPLEMENTATION</span></td>
      </tr>
      <tr>
        <td id="L1484" class="blob-num js-line-number" data-line-number="1484"></td>
        <td id="LC1484" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1485" class="blob-num js-line-number" data-line-number="1485"></td>
        <td id="LC1485" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">/*</span> Revision history</span></td>
      </tr>
      <tr>
        <td id="L1486" class="blob-num js-line-number" data-line-number="1486"></td>
        <td id="LC1486" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      1.09  (2018-02-11)</span></td>
      </tr>
      <tr>
        <td id="L1487" class="blob-num js-line-number" data-line-number="1487"></td>
        <td id="LC1487" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             fix typo in zlib quality API, improve STB_I_W_STATIC in C++</span></td>
      </tr>
      <tr>
        <td id="L1488" class="blob-num js-line-number" data-line-number="1488"></td>
        <td id="LC1488" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      1.08  (2018-01-29)</span></td>
      </tr>
      <tr>
        <td id="L1489" class="blob-num js-line-number" data-line-number="1489"></td>
        <td id="LC1489" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             add stbi__flip_vertically_on_write, external zlib, zlib quality, choose PNG filter</span></td>
      </tr>
      <tr>
        <td id="L1490" class="blob-num js-line-number" data-line-number="1490"></td>
        <td id="LC1490" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      1.07  (2017-07-24)</span></td>
      </tr>
      <tr>
        <td id="L1491" class="blob-num js-line-number" data-line-number="1491"></td>
        <td id="LC1491" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             doc fix</span></td>
      </tr>
      <tr>
        <td id="L1492" class="blob-num js-line-number" data-line-number="1492"></td>
        <td id="LC1492" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      1.06 (2017-07-23)</span></td>
      </tr>
      <tr>
        <td id="L1493" class="blob-num js-line-number" data-line-number="1493"></td>
        <td id="LC1493" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             writing JPEG (using Jon Olick&#39;s code)</span></td>
      </tr>
      <tr>
        <td id="L1494" class="blob-num js-line-number" data-line-number="1494"></td>
        <td id="LC1494" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      1.05   ???</span></td>
      </tr>
      <tr>
        <td id="L1495" class="blob-num js-line-number" data-line-number="1495"></td>
        <td id="LC1495" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      1.04 (2017-03-03)</span></td>
      </tr>
      <tr>
        <td id="L1496" class="blob-num js-line-number" data-line-number="1496"></td>
        <td id="LC1496" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             monochrome BMP expansion</span></td>
      </tr>
      <tr>
        <td id="L1497" class="blob-num js-line-number" data-line-number="1497"></td>
        <td id="LC1497" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      1.03   ???</span></td>
      </tr>
      <tr>
        <td id="L1498" class="blob-num js-line-number" data-line-number="1498"></td>
        <td id="LC1498" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      1.02 (2016-04-02)</span></td>
      </tr>
      <tr>
        <td id="L1499" class="blob-num js-line-number" data-line-number="1499"></td>
        <td id="LC1499" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             avoid allocating large structures on the stack</span></td>
      </tr>
      <tr>
        <td id="L1500" class="blob-num js-line-number" data-line-number="1500"></td>
        <td id="LC1500" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      1.01 (2016-01-16)</span></td>
      </tr>
      <tr>
        <td id="L1501" class="blob-num js-line-number" data-line-number="1501"></td>
        <td id="LC1501" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             STBIW_REALLOC_SIZED: support allocators with no realloc support</span></td>
      </tr>
      <tr>
        <td id="L1502" class="blob-num js-line-number" data-line-number="1502"></td>
        <td id="LC1502" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             avoid race-condition in crc initialization</span></td>
      </tr>
      <tr>
        <td id="L1503" class="blob-num js-line-number" data-line-number="1503"></td>
        <td id="LC1503" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             minor compile issues</span></td>
      </tr>
      <tr>
        <td id="L1504" class="blob-num js-line-number" data-line-number="1504"></td>
        <td id="LC1504" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      1.00 (2015-09-14)</span></td>
      </tr>
      <tr>
        <td id="L1505" class="blob-num js-line-number" data-line-number="1505"></td>
        <td id="LC1505" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             installable file IO function</span></td>
      </tr>
      <tr>
        <td id="L1506" class="blob-num js-line-number" data-line-number="1506"></td>
        <td id="LC1506" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      0.99 (2015-09-13)</span></td>
      </tr>
      <tr>
        <td id="L1507" class="blob-num js-line-number" data-line-number="1507"></td>
        <td id="LC1507" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             warning fixes; TGA rle support</span></td>
      </tr>
      <tr>
        <td id="L1508" class="blob-num js-line-number" data-line-number="1508"></td>
        <td id="LC1508" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      0.98 (2015-04-08)</span></td>
      </tr>
      <tr>
        <td id="L1509" class="blob-num js-line-number" data-line-number="1509"></td>
        <td id="LC1509" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             added STBIW_MALLOC, STBIW_ASSERT etc</span></td>
      </tr>
      <tr>
        <td id="L1510" class="blob-num js-line-number" data-line-number="1510"></td>
        <td id="LC1510" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      0.97 (2015-01-18)</span></td>
      </tr>
      <tr>
        <td id="L1511" class="blob-num js-line-number" data-line-number="1511"></td>
        <td id="LC1511" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             fixed HDR asserts, rewrote HDR rle logic</span></td>
      </tr>
      <tr>
        <td id="L1512" class="blob-num js-line-number" data-line-number="1512"></td>
        <td id="LC1512" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      0.96 (2015-01-17)</span></td>
      </tr>
      <tr>
        <td id="L1513" class="blob-num js-line-number" data-line-number="1513"></td>
        <td id="LC1513" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             add HDR output</span></td>
      </tr>
      <tr>
        <td id="L1514" class="blob-num js-line-number" data-line-number="1514"></td>
        <td id="LC1514" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             fix monochrome BMP</span></td>
      </tr>
      <tr>
        <td id="L1515" class="blob-num js-line-number" data-line-number="1515"></td>
        <td id="LC1515" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      0.95 (2014-08-17)</span></td>
      </tr>
      <tr>
        <td id="L1516" class="blob-num js-line-number" data-line-number="1516"></td>
        <td id="LC1516" class="blob-code blob-code-inner js-file-line"><span class="pl-c">		       add monochrome TGA output</span></td>
      </tr>
      <tr>
        <td id="L1517" class="blob-num js-line-number" data-line-number="1517"></td>
        <td id="LC1517" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      0.94 (2014-05-31)</span></td>
      </tr>
      <tr>
        <td id="L1518" class="blob-num js-line-number" data-line-number="1518"></td>
        <td id="LC1518" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             rename private functions to avoid conflicts with stb_image.h</span></td>
      </tr>
      <tr>
        <td id="L1519" class="blob-num js-line-number" data-line-number="1519"></td>
        <td id="LC1519" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      0.93 (2014-05-27)</span></td>
      </tr>
      <tr>
        <td id="L1520" class="blob-num js-line-number" data-line-number="1520"></td>
        <td id="LC1520" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             warning fixes</span></td>
      </tr>
      <tr>
        <td id="L1521" class="blob-num js-line-number" data-line-number="1521"></td>
        <td id="LC1521" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      0.92 (2010-08-01)</span></td>
      </tr>
      <tr>
        <td id="L1522" class="blob-num js-line-number" data-line-number="1522"></td>
        <td id="LC1522" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             casts to unsigned char to fix warnings</span></td>
      </tr>
      <tr>
        <td id="L1523" class="blob-num js-line-number" data-line-number="1523"></td>
        <td id="LC1523" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      0.91 (2010-07-17)</span></td>
      </tr>
      <tr>
        <td id="L1524" class="blob-num js-line-number" data-line-number="1524"></td>
        <td id="LC1524" class="blob-code blob-code-inner js-file-line"><span class="pl-c">             first public release</span></td>
      </tr>
      <tr>
        <td id="L1525" class="blob-num js-line-number" data-line-number="1525"></td>
        <td id="LC1525" class="blob-code blob-code-inner js-file-line"><span class="pl-c">      0.90   first internal release</span></td>
      </tr>
      <tr>
        <td id="L1526" class="blob-num js-line-number" data-line-number="1526"></td>
        <td id="LC1526" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">*/</span></span></td>
      </tr>
      <tr>
        <td id="L1527" class="blob-num js-line-number" data-line-number="1527"></td>
        <td id="LC1527" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1528" class="blob-num js-line-number" data-line-number="1528"></td>
        <td id="LC1528" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">/*</span></span></td>
      </tr>
      <tr>
        <td id="L1529" class="blob-num js-line-number" data-line-number="1529"></td>
        <td id="LC1529" class="blob-code blob-code-inner js-file-line"><span class="pl-c">------------------------------------------------------------------------------</span></td>
      </tr>
      <tr>
        <td id="L1530" class="blob-num js-line-number" data-line-number="1530"></td>
        <td id="LC1530" class="blob-code blob-code-inner js-file-line"><span class="pl-c">This software is available under 2 licenses -- choose whichever you prefer.</span></td>
      </tr>
      <tr>
        <td id="L1531" class="blob-num js-line-number" data-line-number="1531"></td>
        <td id="LC1531" class="blob-code blob-code-inner js-file-line"><span class="pl-c">------------------------------------------------------------------------------</span></td>
      </tr>
      <tr>
        <td id="L1532" class="blob-num js-line-number" data-line-number="1532"></td>
        <td id="LC1532" class="blob-code blob-code-inner js-file-line"><span class="pl-c">ALTERNATIVE A - MIT License</span></td>
      </tr>
      <tr>
        <td id="L1533" class="blob-num js-line-number" data-line-number="1533"></td>
        <td id="LC1533" class="blob-code blob-code-inner js-file-line"><span class="pl-c">Copyright (c) 2017 Sean Barrett</span></td>
      </tr>
      <tr>
        <td id="L1534" class="blob-num js-line-number" data-line-number="1534"></td>
        <td id="LC1534" class="blob-code blob-code-inner js-file-line"><span class="pl-c">Permission is hereby granted, free of charge, to any person obtaining a copy of </span></td>
      </tr>
      <tr>
        <td id="L1535" class="blob-num js-line-number" data-line-number="1535"></td>
        <td id="LC1535" class="blob-code blob-code-inner js-file-line"><span class="pl-c">this software and associated documentation files (the &quot;Software&quot;), to deal in </span></td>
      </tr>
      <tr>
        <td id="L1536" class="blob-num js-line-number" data-line-number="1536"></td>
        <td id="LC1536" class="blob-code blob-code-inner js-file-line"><span class="pl-c">the Software without restriction, including without limitation the rights to </span></td>
      </tr>
      <tr>
        <td id="L1537" class="blob-num js-line-number" data-line-number="1537"></td>
        <td id="LC1537" class="blob-code blob-code-inner js-file-line"><span class="pl-c">use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies </span></td>
      </tr>
      <tr>
        <td id="L1538" class="blob-num js-line-number" data-line-number="1538"></td>
        <td id="LC1538" class="blob-code blob-code-inner js-file-line"><span class="pl-c">of the Software, and to permit persons to whom the Software is furnished to do </span></td>
      </tr>
      <tr>
        <td id="L1539" class="blob-num js-line-number" data-line-number="1539"></td>
        <td id="LC1539" class="blob-code blob-code-inner js-file-line"><span class="pl-c">so, subject to the following conditions:</span></td>
      </tr>
      <tr>
        <td id="L1540" class="blob-num js-line-number" data-line-number="1540"></td>
        <td id="LC1540" class="blob-code blob-code-inner js-file-line"><span class="pl-c">The above copyright notice and this permission notice shall be included in all </span></td>
      </tr>
      <tr>
        <td id="L1541" class="blob-num js-line-number" data-line-number="1541"></td>
        <td id="LC1541" class="blob-code blob-code-inner js-file-line"><span class="pl-c">copies or substantial portions of the Software.</span></td>
      </tr>
      <tr>
        <td id="L1542" class="blob-num js-line-number" data-line-number="1542"></td>
        <td id="LC1542" class="blob-code blob-code-inner js-file-line"><span class="pl-c">THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR </span></td>
      </tr>
      <tr>
        <td id="L1543" class="blob-num js-line-number" data-line-number="1543"></td>
        <td id="LC1543" class="blob-code blob-code-inner js-file-line"><span class="pl-c">IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, </span></td>
      </tr>
      <tr>
        <td id="L1544" class="blob-num js-line-number" data-line-number="1544"></td>
        <td id="LC1544" class="blob-code blob-code-inner js-file-line"><span class="pl-c">FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE </span></td>
      </tr>
      <tr>
        <td id="L1545" class="blob-num js-line-number" data-line-number="1545"></td>
        <td id="LC1545" class="blob-code blob-code-inner js-file-line"><span class="pl-c">AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER </span></td>
      </tr>
      <tr>
        <td id="L1546" class="blob-num js-line-number" data-line-number="1546"></td>
        <td id="LC1546" class="blob-code blob-code-inner js-file-line"><span class="pl-c">LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, </span></td>
      </tr>
      <tr>
        <td id="L1547" class="blob-num js-line-number" data-line-number="1547"></td>
        <td id="LC1547" class="blob-code blob-code-inner js-file-line"><span class="pl-c">OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE </span></td>
      </tr>
      <tr>
        <td id="L1548" class="blob-num js-line-number" data-line-number="1548"></td>
        <td id="LC1548" class="blob-code blob-code-inner js-file-line"><span class="pl-c">SOFTWARE.</span></td>
      </tr>
      <tr>
        <td id="L1549" class="blob-num js-line-number" data-line-number="1549"></td>
        <td id="LC1549" class="blob-code blob-code-inner js-file-line"><span class="pl-c">------------------------------------------------------------------------------</span></td>
      </tr>
      <tr>
        <td id="L1550" class="blob-num js-line-number" data-line-number="1550"></td>
        <td id="LC1550" class="blob-code blob-code-inner js-file-line"><span class="pl-c">ALTERNATIVE B - Public Domain (www.unlicense.org)</span></td>
      </tr>
      <tr>
        <td id="L1551" class="blob-num js-line-number" data-line-number="1551"></td>
        <td id="LC1551" class="blob-code blob-code-inner js-file-line"><span class="pl-c">This is free and unencumbered software released into the public domain.</span></td>
      </tr>
      <tr>
        <td id="L1552" class="blob-num js-line-number" data-line-number="1552"></td>
        <td id="LC1552" class="blob-code blob-code-inner js-file-line"><span class="pl-c">Anyone is free to copy, modify, publish, use, compile, sell, or distribute this </span></td>
      </tr>
      <tr>
        <td id="L1553" class="blob-num js-line-number" data-line-number="1553"></td>
        <td id="LC1553" class="blob-code blob-code-inner js-file-line"><span class="pl-c">software, either in source code form or as a compiled binary, for any purpose, </span></td>
      </tr>
      <tr>
        <td id="L1554" class="blob-num js-line-number" data-line-number="1554"></td>
        <td id="LC1554" class="blob-code blob-code-inner js-file-line"><span class="pl-c">commercial or non-commercial, and by any means.</span></td>
      </tr>
      <tr>
        <td id="L1555" class="blob-num js-line-number" data-line-number="1555"></td>
        <td id="LC1555" class="blob-code blob-code-inner js-file-line"><span class="pl-c">In jurisdictions that recognize copyright laws, the author or authors of this </span></td>
      </tr>
      <tr>
        <td id="L1556" class="blob-num js-line-number" data-line-number="1556"></td>
        <td id="LC1556" class="blob-code blob-code-inner js-file-line"><span class="pl-c">software dedicate any and all copyright interest in the software to the public </span></td>
      </tr>
      <tr>
        <td id="L1557" class="blob-num js-line-number" data-line-number="1557"></td>
        <td id="LC1557" class="blob-code blob-code-inner js-file-line"><span class="pl-c">domain. We make this dedication for the benefit of the public at large and to </span></td>
      </tr>
      <tr>
        <td id="L1558" class="blob-num js-line-number" data-line-number="1558"></td>
        <td id="LC1558" class="blob-code blob-code-inner js-file-line"><span class="pl-c">the detriment of our heirs and successors. We intend this dedication to be an </span></td>
      </tr>
      <tr>
        <td id="L1559" class="blob-num js-line-number" data-line-number="1559"></td>
        <td id="LC1559" class="blob-code blob-code-inner js-file-line"><span class="pl-c">overt act of relinquishment in perpetuity of all present and future rights to </span></td>
      </tr>
      <tr>
        <td id="L1560" class="blob-num js-line-number" data-line-number="1560"></td>
        <td id="LC1560" class="blob-code blob-code-inner js-file-line"><span class="pl-c">this software under copyright law.</span></td>
      </tr>
      <tr>
        <td id="L1561" class="blob-num js-line-number" data-line-number="1561"></td>
        <td id="LC1561" class="blob-code blob-code-inner js-file-line"><span class="pl-c">THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR </span></td>
      </tr>
      <tr>
        <td id="L1562" class="blob-num js-line-number" data-line-number="1562"></td>
        <td id="LC1562" class="blob-code blob-code-inner js-file-line"><span class="pl-c">IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, </span></td>
      </tr>
      <tr>
        <td id="L1563" class="blob-num js-line-number" data-line-number="1563"></td>
        <td id="LC1563" class="blob-code blob-code-inner js-file-line"><span class="pl-c">FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE </span></td>
      </tr>
      <tr>
        <td id="L1564" class="blob-num js-line-number" data-line-number="1564"></td>
        <td id="LC1564" class="blob-code blob-code-inner js-file-line"><span class="pl-c">AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN </span></td>
      </tr>
      <tr>
        <td id="L1565" class="blob-num js-line-number" data-line-number="1565"></td>
        <td id="LC1565" class="blob-code blob-code-inner js-file-line"><span class="pl-c">ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION </span></td>
      </tr>
      <tr>
        <td id="L1566" class="blob-num js-line-number" data-line-number="1566"></td>
        <td id="LC1566" class="blob-code blob-code-inner js-file-line"><span class="pl-c">WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.</span></td>
      </tr>
      <tr>
        <td id="L1567" class="blob-num js-line-number" data-line-number="1567"></td>
        <td id="LC1567" class="blob-code blob-code-inner js-file-line"><span class="pl-c">------------------------------------------------------------------------------</span></td>
      </tr>
      <tr>
        <td id="L1568" class="blob-num js-line-number" data-line-number="1568"></td>
        <td id="LC1568" class="blob-code blob-code-inner js-file-line"><span class="pl-c"><span class="pl-c">*/</span></span></td>
      </tr>
</table>

  <div class="BlobToolbar position-absolute js-file-line-actions dropdown js-menu-container js-select-menu d-none" aria-hidden="true">
    <button class="btn-octicon ml-0 px-2 p-0 bg-white border border-gray-dark rounded-1 dropdown-toggle js-menu-target" type="button" aria-expanded="false" aria-haspopup="true" aria-label="Inline file action toolbar" aria-controls="inline-file-actions">
      <svg class="octicon octicon-kebab-horizontal" viewBox="0 0 13 16" version="1.1" width="13" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M1.5 9a1.5 1.5 0 1 1 0-3 1.5 1.5 0 0 1 0 3zm5 0a1.5 1.5 0 1 1 0-3 1.5 1.5 0 0 1 0 3zm5 0a1.5 1.5 0 1 1 0-3 1.5 1.5 0 0 1 0 3z"/></svg>
    </button>
    <div class="dropdown-menu-content js-menu-content" id="inline-file-actions">
      <ul class="BlobToolbar-dropdown dropdown-menu dropdown-menu-se mt-2">
        <li><clipboard-copy class="dropdown-item" id="js-copy-lines" style="cursor:pointer;" data-original-text="Copy lines">Copy lines</clipboard-copy></li>
        <li><clipboard-copy class="dropdown-item" id="js-copy-permalink" style="cursor:pointer;" data-original-text="Copy permalink">Copy permalink</clipboard-copy></li>
        <li><a class="dropdown-item js-update-url-with-hash" id="js-view-git-blame" href="/nothings/stb/blame/e6afb9cbae4064da8c3e69af3ff5c4629579c1d2/stb_image_write.h">View git blame</a></li>
          <li><a class="dropdown-item" id="js-new-issue" href="/nothings/stb/issues/new">Open new issue</a></li>
      </ul>
    </div>
  </div>

  </div>

  </div>

  <button type="button" data-facebox="#jump-to-line" data-facebox-class="linejump" data-hotkey="l" class="d-none">Jump to Line</button>
  <div id="jump-to-line" style="display:none">
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="js-jump-to-line-form" action="" accept-charset="UTF-8" method="get"><input name="utf8" type="hidden" value="&#x2713;" />
      <input class="form-control linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" aria-label="Jump to line" autofocus>
      <button type="submit" class="btn">Go</button>
</form>  </div>


  </div>
  <div class="modal-backdrop js-touch-events"></div>
</div>

    </div>
  </div>

  </div>

      
<div class="footer container-lg px-3" role="contentinfo">
  <div class="position-relative d-flex flex-justify-between pt-6 pb-2 mt-6 f6 text-gray border-top border-gray-light ">
    <ul class="list-style-none d-flex flex-wrap ">
      <li class="mr-3">&copy; 2018 <span title="0.34253s from unicorn-1694869411-p039r">GitHub</span>, Inc.</li>
        <li class="mr-3"><a data-ga-click="Footer, go to terms, text:terms" href="https://github.com/site/terms">Terms</a></li>
        <li class="mr-3"><a data-ga-click="Footer, go to privacy, text:privacy" href="https://github.com/site/privacy">Privacy</a></li>
        <li class="mr-3"><a href="https://help.github.com/articles/github-security/" data-ga-click="Footer, go to security, text:security">Security</a></li>
        <li class="mr-3"><a href="https://status.github.com/" data-ga-click="Footer, go to status, text:status">Status</a></li>
        <li><a data-ga-click="Footer, go to help, text:help" href="https://help.github.com">Help</a></li>
    </ul>

    <a aria-label="Homepage" title="GitHub" class="footer-octicon" href="https://github.com">
      <svg height="24" class="octicon octicon-mark-github" viewBox="0 0 16 16" version="1.1" width="24" aria-hidden="true"><path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0 0 16 8c0-4.42-3.58-8-8-8z"/></svg>
</a>
   <ul class="list-style-none d-flex flex-wrap ">
        <li class="mr-3"><a data-ga-click="Footer, go to contact, text:contact" href="https://github.com/contact">Contact GitHub</a></li>
      <li class="mr-3"><a href="https://developer.github.com" data-ga-click="Footer, go to api, text:api">API</a></li>
      <li class="mr-3"><a href="https://training.github.com" data-ga-click="Footer, go to training, text:training">Training</a></li>
      <li class="mr-3"><a href="https://shop.github.com" data-ga-click="Footer, go to shop, text:shop">Shop</a></li>
        <li class="mr-3"><a href="https://blog.github.com" data-ga-click="Footer, go to blog, text:blog">Blog</a></li>
        <li><a data-ga-click="Footer, go to about, text:about" href="https://github.com/about">About</a></li>

    </ul>
  </div>
  <div class="d-flex flex-justify-center pb-6">
    <span class="f6 text-gray-light"></span>
  </div>
</div>



  <div id="ajax-error-message" class="ajax-error-message flash flash-error">
    <svg class="octicon octicon-alert" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.865 1.52c-.18-.31-.51-.5-.87-.5s-.69.19-.87.5L.275 13.5c-.18.31-.18.69 0 1 .19.31.52.5.87.5h13.7c.36 0 .69-.19.86-.5.17-.31.18-.69.01-1L8.865 1.52zM8.995 13h-2v-2h2v2zm0-3h-2V6h2v4z"/></svg>
    <button type="button" class="flash-close js-ajax-error-dismiss" aria-label="Dismiss error">
      <svg class="octicon octicon-x" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
    </button>
    You can’t perform that action at this time.
  </div>


    
    <script crossorigin="anonymous" integrity="sha512-K357zOH5B5oprWdSfij/QrJZY21k7qekmQBC0tDhuEif6yO6gI9fE3mavlZxeBVmUdO6CVNAdvOe+KO8a3EKsw==" type="application/javascript" src="https://assets-cdn.github.com/assets/frameworks-f51a9ca2f1f27eeef749edc76438d035.js"></script>
    
    <script crossorigin="anonymous" async="async" integrity="sha512-Q7BsELRqusVn2d150VZrt3APwkixFStkS4TEv/I3fudlu8Ww8ta5xN9VYXnpRfI505eWlXAfjI2O4NIhivXfFA==" type="application/javascript" src="https://assets-cdn.github.com/assets/github-7820837c272dd7ef939c1ded2ed4a1b7.js"></script>
    
    
    
    
  <div class="js-stale-session-flash stale-session-flash flash flash-warn flash-banner d-none">
    <svg class="octicon octicon-alert" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M8.865 1.52c-.18-.31-.51-.5-.87-.5s-.69.19-.87.5L.275 13.5c-.18.31-.18.69 0 1 .19.31.52.5.87.5h13.7c.36 0 .69-.19.86-.5.17-.31.18-.69.01-1L8.865 1.52zM8.995 13h-2v-2h2v2zm0-3h-2V6h2v4z"/></svg>
    <span class="signed-in-tab-flash">You signed in with another tab or window. <a href="">Reload</a> to refresh your session.</span>
    <span class="signed-out-tab-flash">You signed out in another tab or window. <a href="">Reload</a> to refresh your session.</span>
  </div>
  <div class="facebox" id="facebox" style="display:none;">
  <div class="facebox-popup">
    <div class="facebox-content" role="dialog" aria-labelledby="facebox-header" aria-describedby="facebox-description">
    </div>
    <button type="button" class="facebox-close js-facebox-close" aria-label="Close modal">
      <svg class="octicon octicon-x" viewBox="0 0 12 16" version="1.1" width="12" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
    </button>
  </div>
</div>

  <div class="Popover js-hovercard-content position-absolute" style="display: none; outline: none;" tabindex="0">
  <div class="Popover-message Popover-message--bottom-left Popover-message--large Box box-shadow-large" style="width:360px;">
  </div>
</div>

<div id="hovercard-aria-description" class="sr-only">
  Press h to open a hovercard with more details.
</div>


  </body>
</html>

