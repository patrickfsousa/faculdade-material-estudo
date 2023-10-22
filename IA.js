// Flood Fill Algorithm.

// clear the driver object.
driver = {};

// boolean. TRUE = go to goal.  FALSE = go home
driver.goGoal;

// Gets called only when downloaded to the mouse
// Performs initialization
driver.load = function () {
  // default maze
  //mouse.loadMaze("91japa1");
  driver.goGoal = true;
};

// Figure out next move.
// Gets called each iteration of the simulator.
driver.next = function () {
  var lval = 255;
  var ldir;

  if (mouse.isGoal() && driver.goGoal) {
    mouse.stop();
    alert(
      "Center Reached! Moves: " +
        mouse.moveCount() +
        "\nPress start to go home."
    );
    mouse.home();
  }

  // get the current flood values.
  mouse.memFlood(driver.goGoal);

  if (mouse.isPathLeft()) {
    lval = mouse.memGetDataLeft();
    mouse.left();
    mouse.fwd();
  } else if (mouse.isPathfwd()) {
    if (mouse.memGetDataFwd() < lval) {
      lval = mouse.memGetDataFwd();
      mouse.fwd();
    } else if (mouse.isPathRight()) {
      if (mouse.memGetDataRight() < lval) {
        lval = mouse.memGetDataRight();
        mouse.right();
        mouse.fwd();
      } else if (mouse.isPathBack()) {
        if (mouse.memGetDataBack() < lval) {
          lval = mouse.memGetDataBack();
          mouse.left(2);
          mouse.fwd();
        }
      }
    }
  }
};
