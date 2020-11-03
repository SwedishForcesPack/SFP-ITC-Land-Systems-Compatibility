class CfgVehicles {
	class StaticWeapon;
	class StaticMortar: StaticWeapon {
		class Turrets;
	};
	class Mortar_01_base_F: StaticMortar {
		class Turrets: Turrets {
			class MainTurret;
		};
	};
	class sfp_grk84_base: Mortar_01_base_F {
	};
	class sfp_grk84: sfp_grk84_base {
		artilleryScanner = 0;		
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				turretInfoType = "ITC_Land_RscGunnerSightBasic";
			};
		};
	};
};
