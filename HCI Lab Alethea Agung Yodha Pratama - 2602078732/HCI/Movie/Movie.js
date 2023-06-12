function playVisibleVideos() {
    document.querySelectorAll("video").forEach(video => elementIsVisible(video) ? video.play() : video.pause());
  }
  
  function elementIsVisible(el) {
    let rect = el.getBoundingClientRect();
    return (rect.bottom >= 0 && rect.right >= 0 && rect.top <= (window.innerHeight || document.documentElement.clientHeight) && rect.left <= (window.innerWidth || document.documentElement.clientWidth));
  }
  
  let playVisibleVideosTimeout;
  window.addEventListener("scroll", () => {
    clearTimeout(playVisibleVideosTimeout);
    playVisibleVideosTimeout = setTimeout(playVisibleVideos, 100);
  
  });

  function gotoLink(){
    location.href = 'https://youtu.be/dQw4w9WgXcQ'
  }

  // References:
  // https://discourse.webflow.com/t/play-pause-restart-html5-videos-based-on-visibility/147845