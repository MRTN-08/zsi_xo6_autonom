# 🚦 zsi_xo6_autonom

### SZE – Autonóm járművek és robotok programozása *(GKNB_AUTM078)*  
### Kis beadandó – ROS 2 Humble (C++)

Ez a projekt a **SZE – Autonóm járművek és robotok programozása** kurzushoz készült kis beadandó.  
Célja, hogy gyakorlati tapasztalatot adjon a **ROS 2 publisher–subscriber** kommunikációban és a node-ok közötti adatátvitelben.

---

## 📦 Felépítés

- `traffic_light_node`: A közlekedési lámpa állapotát (zöld, sárga, piros) váltogatja, és ezt a `/traffic/state` topicon publikálja.
- `car_node`: Figyeli a `/traffic/state` topicot, és ennek alapján döntéseket hoz (pl. halad, lassít, megáll), amelyeket a `/car/status` topicon publikál.

---

## ⚙️ Telepítés és futtatás

1. 📦 Clone the package:

   ```bash
   cd ~/ros2_ws/src
   git clone https://github.com/MRTN-08/zsi_xo6_autonom
   
2. c Build ROS 2 package

   ```bash
   cd ~/ros2_ws
   colcon build --packages-select zsi_xo6_autonom --symlink-install

3. 🔗 Source the workspace
   ```bash
   source ~/ros2_ws/install/setup.bash

4. ▶️ Launch the traffic system
   ```bash
   ros2 launch zsi_xo6_autonom traffic_system.launch.py

5. 📝ROS 2 Traffic System – Monitor Traffic Light and Car States
   ~~~bash
   source ~/ros2_ws/install/setup.bash
   ros2 topic echo /traffic/state
   ros2 topic echo /car/status
   
+ 🏎️ Run individual nodes (optional)
   ```bash
   ros2 run zsi_xo6_autonom traffic_light_node
   ros2 run zsi_xo6_autonom car_node
   

```mermaid
graph LR
  TL[/traffic_light_node/] -->|/traffic/state| CAR[/car_node/]
  CAR -->|/car/status| CONSOLE[/console/]
