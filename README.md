# 🚦 ign_b7e_traffic_ctrl

### SZE – Autonóm járművek és robotok programozása *(GKNB_AUTM078)*  
### Kis beadandó – ROS 2 Humble (C++)

Ez a projekt a **SZE – Autonóm járművek és robotok programozása** kurzushoz készült kis beadandó.  
Célja, hogy gyakorlati tapasztalatot adjon a **ROS 2 publisher–subscriber** kommunikációban és a node-ok közötti adatátvitelben.  

A feladat egy **okos közlekedési lámpa rendszer** szimulációja két node segítségével:  
- a `traffic_light_node` váltogatja a lámpa állapotát (zöld, sárga, piros),  
- a `car_node` figyeli az állapotot, és ennek alapján „vezetési döntéseket” hoz (halad, lassít, megáll).
