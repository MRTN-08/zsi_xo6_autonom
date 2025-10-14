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

1. Klónozd a repót:

   ```bash
   cd ~/ros2_ws/src
   git clone https://github.com/MRTN-08/zsi_xo6_autonom


```mermaid
graph LR
  TL[/traffic_light_node/] -->|/traffic/state| CAR[/car_node/]
  CAR -->|/car/status| CONSOLE[/console/]
