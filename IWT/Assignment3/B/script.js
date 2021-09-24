var P1 = {
    x: 0,
    y: 0,
  };

  var P2 = {
    x: 0,
    y: 0,
  };

  function distance() {
    var distance = Math.sqrt(
      Math.pow(P2.x - P1.x, 2) + Math.pow(P2.y - P1.y, 2)
    );
    document.getElementById("result").textContent = distance;
  }