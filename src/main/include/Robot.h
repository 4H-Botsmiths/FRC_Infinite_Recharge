/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <rev/CANSparkMax.h>

#include "StarDust/sensor/vision/limelight/Limelight.hpp"
#include "StarDust/pneumatics/DoubleSolenoid.hpp"
#include "StarDust/sensor/motion/AHRS_Gyro.hpp"
#include "StarDust/control/XboxController.hpp"
#include "StarDust/core/StarDustRobot.hpp"
#include "StarDust/drive/DriveSpider.hpp"
#include "StarDust/motor/MotorGroup.hpp"
#include "StarDust/logging/CSV.hpp"
#include "StarDust/motor/Motor.hpp"

class Robot : public frc::TimedRobot {
public:
	void RobotInit() override;
	void RobotPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
	void DisabledInit() override;

private:
	Limelight limelight;

	DoubleSolenoid driveRocker { 0, 1, true };
	DoubleSolenoid intakeArm { 4, 5 };

	rev::CANSparkMax motor1 { 1, rev::CANSparkMax::MotorType::kBrushless };
	rev::CANSparkMax motor2 { 2, rev::CANSparkMax::MotorType::kBrushless };
	rev::CANSparkMax motor3 { 3, rev::CANSparkMax::MotorType::kBrushless };
	rev::CANSparkMax motor4 { 4, rev::CANSparkMax::MotorType::kBrushless };

	DriveSpider drivetrain {
		&motor1,
		&motor2,
		&motor3,
		&motor4,
		&driveRocker
	};

	Motor shooterRight { 0, true };
	Motor shooterLeft { 1, true };
	MotorGroup shooter {{
		&shooterLeft,
		&shooterRight
	}};

	Motor ballBeltLower { 2, true };
	Motor ballBeltUpper { 3, 0.5, true };
	MotorGroup ballBelt {{
		&ballBeltLower,
		&ballBeltUpper
	}};

	Motor ballIntake { 4, true };

	XboxController xboxController { 0, 0.15, 0.15 };

	StarDustRobot starDustRobot {{
		&drivetrain,
		&xboxController,
		&limelight
	}};
};