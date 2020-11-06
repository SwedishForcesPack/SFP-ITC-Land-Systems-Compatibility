class CfgVehicles {
	class StaticWeapon;
	class StaticMortar: StaticWeapon {
		class Turrets;
	};
	class sfp_arty_base: StaticMortar {
		class Turrets: Turrets {
			class MainTurret;
		};
	};
	class sfp_fh77 : sfp_arty_base {
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				turretInfoType = "ITC_Land_RscGunnerSightBasic";
			};
		};
	};
};
