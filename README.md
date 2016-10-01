# Arduino-gamepad

<html>
<body>
    <div style="width: 800px; margin: 0 auto;">
        <div style="height: 55px; background-color: #97A0A9;">
            <h1 style="padding-top: 10px; text-align: center;">Arduino based gamepad</h1>
        </div>
        <div style="background-color: #f4f5f6">
            <h2 style="text-align: center;">Cirquit</h2>
            <img src="circuit.png" style="position: relative; left: 50px;" />
            <ul style="list-style-type: square">
                <li>Joystick1 used for mouse cursor manipulating.
                <li>Joystick2 used for keyboard emulation (w, s, a, d keys).
                <li>Button connected to 10 pin used as left mouse button.
                <li>Button connected to 8 pin used as right mouse button.
            </ul>
        </div>
        <div style="background-color: #f4f5f6">
            <h2 style="text-align: center;">Compilation</h2>
            <div>
                <h3>Driver</h3>
                <ul style="list-style-type: none">
                    <li>$mkdir Arduino-gamepad
                    <li>$cd Arduino-gamepad
                    <li>$wget https://github.com/sda97ghb/Arduino-gamepad/archive/master.zip
                    <li>$unzip master.zip
                    <li>$cd ?????
                    <li>$qmake gamepaddriver.pro
                    <li>$make
                    <li>$./gamepaddriver
                </ul>
            </div>
            <div>
                <h3>Sketch</h3>
                <ul style="list-style-type: decimal;">
                    <li>Download source code: <a href="https://github.com/sda97ghb/Arduino-gamepad/archive/master.zip">github</a>
                    <li>Unzip it
                    <li>Run Arduino Studio and open sketch/gamepadsketch.ino
                    <li>Connect your arduino and upload sketch to it
                </ul>
            </div>
        </div>
        <div style="background-color: #A99C86; height: 20px">
            <p style="text-align: center;">in progress...</p>
        </div>
    </div>
</body>
</html>
