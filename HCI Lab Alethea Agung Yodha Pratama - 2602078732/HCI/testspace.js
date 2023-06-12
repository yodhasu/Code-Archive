// let option = {
//     root: null,
//     rootmargin:'0px',
//     threshold: 1.0
// };

// let callback = (enteries, observer)=>{
//     enteries.forEach(entry => {
//         if(entry.target.id == 'myVideo'){
//             if(entry.isIntersecting){
//                 entry.target.play();
//             }
//             else{
//                 entry.target.pause();
//             }
//         }
//     });
// }
// let observer = new IntersectionObserver(callback, option);
// obeserver.observe(document.querySelector('#myVideo'))

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