/*//
//  GameScene.swift
//  Simple Shooter
//
//  Created by Phillip Viau on 4/27/16.
//  Copyright (c) 2016 Build it Love it. All rights reserved.
//

import SpriteKit

var player = SKSpriteNode ? ()
var projectile = SKSpriteNode ? ()
var enemy = SKSpriteNode()
var star = SKSpriteNode ? ()

var scoreLabel = SKLabelNode()
var mainLabel = SKLabelNode ? ()

var locationLabel = SKLabelNode()

var fireProjectileRate = 0.15
var projectileSpeed = 0.51

var enemySpeed = 4.24
var enemySpawnRate = 0.35
var enemyTypes : [String] = ["", "", "Mini-Boss", "Boss"]
var enemyDamage : [Double] = [1.0, 2.25, 1.50, 3]
var enemyDamageMultiplier : [Int] = [1, 2, 3, 4, 5]

var starSpeed = 4.82
var starSpawnRate = 0.0035

var isAlive = true
var touching = false
var isTopScrolliing = true

var score = 0
var playerLives = 3
var playerHealth = 100

var textColorHUD = UIColor(red: 0.95, green : 0.95, blue : 0.95, alpha : 1.0)

var projectilesTypes : [String] = ["Bullet", "Laser", "Spread", "Twist"]

var playerPowerUp : [String] = ["Missile", "Spread", "Homing", "Conucussive", "Spiral"]

var projectileLevel = 1

var projectileDamage : [Float] = [1.0, 3.5, 2.25, 1.50]




	struct physicsCategory {
		static let player : UInt32 = 1
			static let enemy : UInt32 = 2
			static let projectile : UInt32 = 3
			static let projectilePowerUp : UInt32 = 4
			//static let star : UInt32 = 0
	}

	class GameScene : SKScene, SKPhysicsContactDelegate { // add SKPhysicsContactDelegate for collision
		override func didMoveToView(view: SKView) {

			physicsWorld.contactDelegate = self // instantiates contactDelegate to self

				self.backgroundColor = UIColor.blackColor()
				spawnPlayer()
				spawnScoreLabel()
				spawnMainLabel()
				spawnLocatoinLabel()
				spawnProjectile()
				spawnEnemy()
				fireProjectile()
				randomStarTimerSpawn()
				randomEnemyTimerSpawn()
				updateScore()
				hideLabel()
				resetVariablesOnStart()
				//spawnStars()

		}

		override func touchesBegan(touches: Set<UITouch>, withEvent event : UIEvent ? ) {
			/* Called when a touch begins */

			for touch in touches{
				if isAlive{
					touching = true
				}
			}


		}

		override func touchesEnded(touches: Set<UITouch>, withEvent event : UIEvent ? ) {
			touching = false
		}



		override func touchesMoved(touches: Set<UITouch>, withEvent event : UIEvent ? ) {
			for touch in touches{
				let touchLocation = touch.locationInNode(self)
				locationLabel.text = "X: \(player!.position.x) Y: \(player!.position.y)"

				//locationLabel?.text = "X: \(frame.size.width) Y: \(frame.size.height)"

				if isAlive{
					if touchLocation.x <= 320 {
						player ? .position.x = 320
							player ? .position.y = touchLocation.y
					}
					else if touchLocation.y <= 20 {
						player ? .position.x = touchLocation.x
							player ? .position.y = 20
					}
					else if touchLocation.x >= frame.width - 324  {
						player ? .position.x = frame.width - 324
							player ? .position.y = touchLocation.y

					}
					else if touchLocation.x <= 320 && touchLocation.y <= 20 {

						player ? .position.x = 320
							player ? .position.y = 20

					}
					else {
						player ? .position.x = touchLocation.x
							player ? .position.y = touchLocation.y
					}


				}

					if !isAlive{
						touching = false
						player ? .position.x = -200 // moves offscreen for performance if player dies
					}

			}
		}

		override func update(currentTime: CFTimeInterval) {
			/* Called before each frame is rendered */
			if !isAlive{
				touching = false
				player ? .position.x = -200 // moves offscreen for performance if player dies

			}





		}

		func spawnPlayer() {

			player = SKSpriteNode(imageNamed: "playerBlue") // instantiates player object size
				player ? .position = CGPoint(x : CGRectGetMidX(self.frame), y : 20) // instantiates object to scene at location
				player ? .physicsBody = SKPhysicsBody(rectangleOfSize : (player ? .size)!) // player sprite
				player ? .physicsBody ? .affectedByGravity = false // prevents player sprite from being affected by gravity
				player ? .physicsBody ? .categoryBitMask = physicsCategory.player // assigns player to physics category from struct
				player ? .physicsBody ? .contactTestBitMask = physicsCategory.enemy // assigns enemy to physics categor from struct
				player ? .physicsBody ? .dynamic = false

				self.addChild(player!) // adds player to scene as a child object to parent self
		}

		func spawnScoreLabel() {
			scoreLabel = SKLabelNode(fontNamed: "Futura")
				scoreLabel.fontSize = 20
				scoreLabel.fontColor = textColorHUD
				scoreLabel.position = CGPoint(x: CGRectGetMidX(self.frame) + 160, y : CGRectGetMaxY(self.frame) - 35)
				scoreLabel.text = "Score"
				self.addChild(scoreLabel)


		}

		func spawnLocatoinLabel() {
			locationLabel = SKLabelNode(fontNamed: "Futura")
				locationLabel.fontSize = 18
				locationLabel.fontColor = textColorHUD
				locationLabel.position = CGPoint(x: CGRectGetMidX(self.frame), y : CGRectGetMaxY(self.frame) - 60)
				locationLabel.text = "X: 0 Y: 0"

				self.addChild(locationLabel)
		}

		func spawnMainLabel() {
			mainLabel = SKLabelNode(fontNamed: "Futura")
				mainLabel ? .fontSize = 100
				mainLabel ? .fontColor = textColorHUD
				mainLabel ? .position = CGPoint(x : CGRectGetMidX(self.frame), y : CGRectGetMidY(self.frame))
				mainLabel ? .text = "Start"

				self.addChild(mainLabel!)

		}

		func spawnProjectile() {

			projectile = SKSpriteNode(imageNamed: "doubleProjectile")
				projectile!.position = CGPoint(x: (player ? .position.x)!, y : (player ? .position.y)!)

				projectile ? .physicsBody = SKPhysicsBody(rectangleOfSize : (projectile ? .size)!)
				projectile ? .physicsBody ? .affectedByGravity = false
				projectile ? .physicsBody ? .categoryBitMask = physicsCategory.projectile
				projectile ? .physicsBody ? .contactTestBitMask = physicsCategory.enemy
				projectile ? .physicsBody ? .dynamic = false
				projectile ? .zPosition = -1

				let moveForward = SKAction.moveToY(800, duration: projectileSpeed)
				let destroy = SKAction.removeFromParent()

				projectile!.runAction(SKAction.sequence([moveForward, destroy]))
				self.addChild(projectile!)

		}

		func spawnEnemy() {
			//let enemySize = 30
			enemy = SKSpriteNode(imageNamed: "enemy")
				enemy.position = CGPoint(x: Int(arc4random_uniform(410) + 310), y : 768)
				enemy.physicsBody = SKPhysicsBody(rectangleOfSize: enemy.size)
				enemy.physicsBody ? .affectedByGravity = false
				enemy.physicsBody ? .categoryBitMask = physicsCategory.enemy
				enemy.physicsBody ? .contactTestBitMask = physicsCategory.projectile
				enemy.physicsBody ? .allowsRotation = false // prevents object from rotating when colliding with other physics object
				enemy.physicsBody ? .dynamic = true // adds collision
				enemy.physicsBody ? .collisionBitMask = 0 // prevents moving if hit other physics object


				let moveForward = SKAction.moveToY(20, duration: enemySpeed)
				let destroy = SKAction.removeFromParent()
				enemy.runAction(SKAction.sequence([moveForward, destroy]))



				self.addChild(enemy)


		}

		func spawnExplosion(enemyTemp: SKSpriteNode) {
			let explosionEmitterPath : NSString = NSBundle.mainBundle().pathForResource("explosion", ofType: "sks")!
				let explosion = NSKeyedUnarchiver.unarchiveObjectWithFile(explosionEmitterPath as String) as!SKEmitterNode

				explosion.position = CGPoint(x : enemyTemp.position.x, y : enemyTemp.position.y)
				explosion.zPosition = 1
				explosion.targetNode = self

				self.addChild(explosion)

				let explosionTimerRemove = SKAction.waitForDuration(0.5)
				let removeExplosion = SKAction.runBlock{
				explosion.removeFromParent()

			}

				self.runAction(SKAction.sequence([explosionTimerRemove, removeExplosion]))


		}

		func randomStarTimerSpawn() {
			let spawnStarTimer = SKAction.waitForDuration(starSpawnRate)
				let spawn = SKAction.runBlock{
				//self.spawnStars()
				self.spawnBackgroundStars()
			}

				let sequence = SKAction.sequence([spawnStarTimer, spawn])
				self.runAction(SKAction.repeatActionForever(sequence))
		}

		func fireProjectile() {
			let fireProjectileTimer = SKAction.waitForDuration(fireProjectileRate)
				let spawn = SKAction.runBlock{
				if touching{
					self.spawnProjectile()
				}
			}




				let sequence = SKAction.sequence([fireProjectileTimer, spawn])

					self.runAction(SKAction.repeatActionForever(sequence))


		}

		func randomEnemyTimerSpawn() {
			let spawnEnemyTimer = SKAction.waitForDuration(enemySpawnRate)
				let spawn = SKAction.runBlock{
				self.spawnEnemy()
			}



				let sequence = SKAction.sequence([spawnEnemyTimer, spawn])
				self.runAction(SKAction.repeatActionForever(sequence))
		}

		func didBeginContact(contact: SKPhysicsContact) { // collision detection function
			let firstBody : SKPhysicsBody = contact.bodyA // assigns first collided object to variable
				let secondBody : SKPhysicsBody = contact.bodyB // assigns second collided object to variable

				if (((firstBody.categoryBitMask == physicsCategory.enemy) && (secondBody.categoryBitMask == physicsCategory.player)) || ((firstBody.categoryBitMask == physicsCategory.player) && (secondBody.categoryBitMask == physicsCategory.enemy))) { // checks if enemy and player collide OR if player and enemy collide

					enemyPlayerCollision(firstBody.node as!SKSpriteNode, playerTemp: secondBody.node as!SKSpriteNode)

				}

			if (((firstBody.categoryBitMask == physicsCategory.enemy) && (secondBody.categoryBitMask == physicsCategory.projectile)) || ((firstBody.categoryBitMask == physicsCategory.projectile) && (secondBody.categoryBitMask == physicsCategory.enemy))) { // checks if enemy and projectile collide OR if projectile and enemy collide

				spawnExplosion(firstBody.node as!SKSpriteNode)
					projectileCollision(firstBody.node as!SKSpriteNode, projectileTemp: secondBody.node as!SKSpriteNode)

			}




		}

		func projectileCollision(enemyTemp: SKSpriteNode, projectileTemp : SKSpriteNode) {
			enemyTemp.removeFromParent()
				projectileTemp.removeFromParent()

				score += 1

				updateScore()
		}

		func enemyPlayerCollision(enemyTemp: SKSpriteNode, playerTemp : SKSpriteNode) {

			mainLabel ? .fontSize = 50
				mainLabel ? .alpha = 1.0
				mainLabel ? .text = "Game Over"

				player ? .removeFromParent()

				isAlive = false

				waitThenMoveToTitleScreen()

		}

		func waitThenMoveToTitleScreen() {

			let wait = SKAction.waitForDuration(3.0)
				let transition = SKAction.runBlock{
				self.view ? .presentScene(TitleScene(), transition: SKTransition.crossFadeWithDuration(1.0))
			}

				let sequence = SKAction.sequence([wait, transition])

				self.runAction(SKAction.repeatAction(sequence, count: 1))


		}


		func updateScore() {
			scoreLabel.text = "Score \(score)"
		}

		func hideLabel() {
			let wait = SKAction.waitForDuration(3.0)
				let hide = SKAction.runBlock{
				mainLabel ? .alpha = 0.0
			}

				let sequence = SKAction.sequence([wait, hide])
				self.runAction(SKAction.repeatAction(sequence, count: 1))

		}

		func resetVariablesOnStart() { // function to reset variables back to default
			isAlive = true
				score = 0
		}

		func spawnBackgroundStars() {
			let starSize = Int((arc4random_uniform(3) + UInt32(0.5)))

				star = SKSpriteNode(color: UIColor.whiteColor(), size : CGSize(width : starSize, height : starSize))
				star!.position = CGPoint(x: Int(arc4random_uniform(420) + 300), y : 800)
				star ? .physicsBody = SKPhysicsBody(rectangleOfSize : star!.size)
				star ? .physicsBody ? .affectedByGravity = false
				//star?.physicsBody?.categoryBitMask = physicsCategory.enemy
				//star?.physicsBody?.contactTestBitMask = physicsCategory.projectile
				star ? .physicsBody ? .allowsRotation = false // prevents object from ro
				star ? .physicsBody ? .dynamic = false
				star ? .zPosition = -2

				let moveForward = SKAction.moveToY(-5, duration: starSpeed - 2.45)
				let destroy = SKAction.removeFromParent()
				star ? .runAction(SKAction.sequence([moveForward, destroy]))

				self.addChild(star!)

		}

		func spawnStars() {
			let starSize = Int((arc4random_uniform(2) + UInt32(0.5)))

				star = SKSpriteNode(color: UIColor.whiteColor(), size : CGSize(width : starSize, height : starSize))
				star!.position = CGPoint(x: Int(arc4random_uniform(400 + 320) - 320), y : 1000)
				star ? .physicsBody = SKPhysicsBody(rectangleOfSize : star!.size)
				star ? .physicsBody ? .affectedByGravity = false
				//star?.physicsBody?.categoryBitMask = physicsCategory.enemy
				//star?.physicsBody?.contactTestBitMask = physicsCategory.projectile
				star ? .physicsBody ? .allowsRotation = false // prevents object from ro
				star ? .physicsBody ? .dynamic = false
				star ? .zPosition = -2

				let moveForward = SKAction.moveToY(-5, duration: starSpeed)
				let destroy = SKAction.removeFromParent()
				star ? .runAction(SKAction.sequence([moveForward, destroy]))

				self.addChild(star!)
		}

	}
	*/