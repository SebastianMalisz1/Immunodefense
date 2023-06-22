#include "Game.h"

struct PlayerScore {
	std::string nickname;
	int points;
};

bool compareScores(const PlayerScore& a, const PlayerScore& b) {
	return a.points > b.points;
}

void saveLeaderboard(const std::vector<PlayerScore>& leaderboard) {
	std::ofstream file("leaderboard.txt");
	if (file.is_open()) {
		std::unordered_set<std::string> uniqueNicknames;  // Track unique nicknames

		// Use ranges to write leaderboard data to the file
		std::ranges::for_each(leaderboard, [&](const PlayerScore& playerScore) {
			// Check if the nickname is unique before saving
			if (uniqueNicknames.insert(playerScore.nickname).second) {
				file << playerScore.nickname << " " << playerScore.points << "\n";
			}
			});

		file.close();
		std::cout << "Leaderboard saved successfully.\n";
	}
	else {
		std::cerr << "Failed to save leaderboard.\n";
	}
}

std::vector<PlayerScore> loadLeaderboard() {
	std::vector<PlayerScore> leaderboard;
	if (std::filesystem::exists("leaderboard.txt")) {
		std::ifstream file("leaderboard.txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::istringstream iss(line);
				std::string nickname;
				int points;
				if (iss >> nickname >> points) {
					leaderboard.push_back({ nickname, points });
				}
			}
			file.close();
			//std::cout << "Leaderboard loaded successfully.\n";
		}
		else {
			std::cerr << "Failed to load leaderboard.\n";
		}
		return leaderboard;
	}
	else {
		std::cout << "leaderboard.txt does not exists" << std::endl;
	}
	return leaderboard;
}

void Game::displayLeaderboard() {
	// Button clicked, open leaderboard
	std::vector<PlayerScore> leaderboard = loadLeaderboard();

	// Sort the leaderboard by score in descending order
	std::ranges::sort(leaderboard, compareScores);

	std::ostringstream oss;
	int lineCount = 0; // Counter for the number of lines written
	for (const PlayerScore& playerScore : leaderboard) {
		oss << playerScore.nickname << " - " << playerScore.points << "\n";
		lineCount++;
		if (lineCount >= 10) {
			break; // Exit the loop after writing 10 lines
		}
	}
	nicknameTextinLeanderboard.setString(oss.str());

	this->window->draw(this->leaderboardScreenShow);
	this->window->draw(this->leaderboardTitle);
	this->window->draw(this->nicknameTextinLeanderboard);
	this->window->draw(this->backButton);
	this->window->draw(this->backButtonText);
}
void Game::initStartWindow()
{
	sf::FloatRect playTextBounds = playText.getLocalBounds();
	sf::FloatRect leaderboardTextBounds = leaderboardText.getLocalBounds();
	sf::FloatRect exitTextBounds = exitText.getLocalBounds();
	//Load font
	if (!this->font.loadFromFile("Font/Lato-BlackItalic.ttf"))
	{
		std::cout << "ERROR::GAME::FAILED TO LOAD FONT" << "\n";
	}

	this->start.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
	this->start.setFillColor(sf::Color(0, 153, 76));

	this->play.setSize(sf::Vector2f(300.f, 100.f));
	this->play.setPosition(800.f, 500.f);
	this->play.setFillColor(sf::Color::White);
	this->play.setOutlineThickness(4.f);
	this->play.setOutlineColor(sf::Color::Black);

	this->leaderboardRectangle.setSize(sf::Vector2f(300.f, 100.f));
	this->leaderboardRectangle.setPosition(800.f, 650.f);
	this->leaderboardRectangle.setFillColor(sf::Color::White);
	this->leaderboardRectangle.setOutlineThickness(4.f);
	this->leaderboardRectangle.setOutlineColor(sf::Color::Black);

	this->exit.setSize(sf::Vector2f(300.f, 100.f));
	this->exit.setPosition(800.f, 800.f);
	this->exit.setFillColor(sf::Color::White);
	this->exit.setOutlineThickness(4.f);
	this->exit.setOutlineColor(sf::Color::Black);

	////Init point text
	this->startText.setPosition(sf::Vector2f(125.f, 50.f));
	this->startText.setFont(this->font);
	this->startText.setCharacterSize(200);
	this->startText.setString("IMMUNODEFENCE");
	this->startText.setFillColor(sf::Color::Black);

	this->playText.setPosition(this->play.getPosition().x + 55.f, this->play.getPosition().y);
	this->playText.setFont(this->font);
	this->playText.setCharacterSize(80);
	this->playText.setString("PLAY");
	this->playText.setFillColor(sf::Color::Black);

	this->leaderboardText.setPosition(this->leaderboardRectangle.getPosition().x + 15.f, this->leaderboardRectangle.getPosition().y + 23.f);
	this->leaderboardText.setFont(this->font);
	this->leaderboardText.setCharacterSize(40);
	this->leaderboardText.setString("LEADERBOARD");
	this->leaderboardText.setFillColor(sf::Color::Black);

	this->exitText.setPosition(this->exit.getPosition().x + 70.f, this->exit.getPosition().y);
	this->exitText.setFont(this->font);
	this->exitText.setCharacterSize(80);
	this->exitText.setString("EXIT");
	this->exitText.setFillColor(sf::Color::Black);
}
void Game::initLeaderboardWindow()
{
	if (!this->font.loadFromFile("Font/Lato-BlackItalic.ttf"))
	{
		std::cout << "ERROR::GAME::FAILED TO LOAD FONT" << "\n";
	}

	this->leaderboardScreenShow.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
	this->leaderboardScreenShow.setFillColor(sf::Color(0, 153, 76));

	////Init point text
	this->leaderboardTitle.setPosition(sf::Vector2f(300.f, 25.f));
	this->leaderboardTitle.setFont(this->font);
	this->leaderboardTitle.setCharacterSize(200);
	this->leaderboardTitle.setString("LEADERBOARD");
	this->leaderboardTitle.setFillColor(sf::Color::Black);

	this->nicknameTextinLeanderboard.setPosition(800.f,300.f);
	this->nicknameTextinLeanderboard.setFont(this->font);
	this->nicknameTextinLeanderboard.setCharacterSize(40);
	this->nicknameTextinLeanderboard.setFillColor(sf::Color::Black);

	this->backButton.setSize(sf::Vector2f(300.f, 100.f));
	this->backButton.setPosition(800.f, 900.f);
	this->backButton.setFillColor(sf::Color::White);
	this->backButton.setOutlineThickness(4.f);
	this->backButton.setOutlineColor(sf::Color::Black);

	this->backButtonText.setPosition(this->backButton.getPosition().x + 55.f, this->backButton.getPosition().y);
	this->backButtonText.setFont(this->font);
	this->backButtonText.setCharacterSize(80);
	this->backButtonText.setString("BACK");
	this->backButtonText.setFillColor(sf::Color::Black);
}
void Game::startTimer()
{
	startTime = std::chrono::steady_clock::now();
}

bool Game::isDurationPassed(std::chrono::steady_clock::duration duration)
{
	auto currentTime = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime);
	return elapsed >= duration;
}

void Game::initText()
{
	if (!this->font.loadFromFile("Font/Lato-BlackItalic.ttf"))
	{
		std::cout << "ERROR::GAME::FAILED TO LOAD FONT" << "\n";
	}


	this->health.setPosition(20.f, 20.f);
	this->health.setFont(this->font);
	this->health.setCharacterSize(24);
	this->health.setFillColor(sf::Color::Black);
	

	this->goldText.setPosition(150, 20.f);
	this->goldText.setFont(this->font);
	this->goldText.setCharacterSize(24);
	this->goldText.setFillColor(sf::Color::Black);




}

void Game::initGameOverWindow()
{
	if (!this->font.loadFromFile("Font/Lato-BlackItalic.ttf"))
	{
		std::cout << "ERROR::GAME::FAILED TO LOAD FONT" << "\n";
	}

	this->endGame.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
	this->endGame.setFillColor(sf::Color(0, 153, 76));

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(120);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("GAME OVER!");
	this->gameOverText.setPosition(sf::Vector2f(600.f, 100.f));

	this->pointsText.setPosition(sf::Vector2f(600.f, 300.f));
	this->pointsText.setFont(this->font);
	this->pointsText.setCharacterSize(60);
	this->pointsText.setFillColor(sf::Color::White);

	this->enterNicknameText.setFont(this->font);
	this->enterNicknameText.setCharacterSize(60);
	this->enterNicknameText.setFillColor(sf::Color::White);
	this->enterNicknameText.setString("Enter your nickname: ");
	this->enterNicknameText.setPosition(sf::Vector2f(600.f, 400.f));

	this->inputbox.setPosition(sf::Vector2f(600.f, 500.f));
	this->inputbox.setSize(sf::Vector2f(300.f, 100.f));
	this->inputbox.setFillColor(sf::Color(0, 153, 76));

	this->nicknameText.setPosition(this->inputbox.getPosition().x, this->inputbox.getPosition().y);
	this->nicknameText.setFont(this->font);
	this->nicknameText.setCharacterSize(60);
	this->nicknameText.setFillColor(sf::Color::White);



	this->hintNicknameText.setFont(this->font);
	this->hintNicknameText.setCharacterSize(16);
	this->hintNicknameText.setFillColor(sf::Color::White);
	this->hintNicknameText.setString("Only small letters allowed");
	this->hintNicknameText.setPosition(sf::Vector2f(600.f, 600.f));


	this->leaderboardEnd.setPosition(sf::Vector2f(800.f,650.f));
	this->leaderboardEnd.setSize(sf::Vector2f(300.f, 100.f));
	this->leaderboardEnd.setFillColor(sf::Color::White);
	this->leaderboardEnd.setOutlineThickness(4.f);
	this->leaderboardEnd.setOutlineColor(sf::Color::Black);

	this->leaderboardEndText.setFont(this->font);
	this->leaderboardEndText.setCharacterSize(40);
	this->leaderboardEndText.setFillColor(sf::Color::Black);
	this->leaderboardEndText.setString("LEADERBOARD");
	this->leaderboardEndText.setPosition(this->leaderboardEnd.getPosition().x + 15.f, this->leaderboardEnd.getPosition().y+23.f);

	this->exitGameOver.setPosition(sf::Vector2f(800.f, 800.f));
	this->exitGameOver.setSize(sf::Vector2f(300.f, 100.f));
	this->exitGameOver.setFillColor(sf::Color::White);
	this->exitGameOver.setOutlineThickness(4.f);
	this->exitGameOver.setOutlineColor(sf::Color::Black);

	this->exitGameOverText.setFont(this->font);
	this->exitGameOverText.setCharacterSize(80);
	this->exitGameOverText.setFillColor(sf::Color::Black);
	this->exitGameOverText.setString("EXIT");
	this->exitGameOverText.setPosition(this->exitGameOver.getPosition().x + 70.f, this->exitGameOver.getPosition().y);

}


void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Immunodefence", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initMap()
{
	this->map = new Mapa(*this->window);
}

void Game::initBacteria()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

Game::Game()
{
	this->initStartWindow();
	this->initText();
	this->initLeaderboardWindow();
	this->initGameOverWindow();
	this->initWindow();
	this->initMap();
	this->initBacteria();
}

Game::~Game()
{
	delete this->window;

	//Delete Enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}
	for (auto* i : this->towers)
	{
		delete i;
	}
}

bool j = 0;
bool z = 0;
const int spawnIntervalMillis1 = 500;  // Time between arrow spawns in milliseconds
const int spawnIntervalMillis2 = 500;  // Time between arrow spawns in milliseconds
const int spawnIntervalMillis4 = 500;  // Time between arrow spawns in milliseconds
auto lastSpawnTime = std::chrono::steady_clock::now();
void Game::run()
{
	//po klikniciu myszka utw�rz w miejscu klikneicia sprite w kt�rym b�dzie opcja wyboru wierzy (grafika gdzie sa namalowanie wierze i odpowiadajace im przyciski)
	bool openToggleTurret = false;
	bool openTurretUpgrade = false;
	bool startGame = false;
	bool endGame = false;
	bool leaderboardScreen = false;
	bool leaderboardScreenEnd = false;
	this->gold = 500;
	this->hp = 10;
	this->points = 0;

	sf::Clock clock;
	float elapsedTime = 0.f;
	sf::Time updateInterval = sf::seconds(1.f);

	// Copy placeForTower elements to avaliableSpotsForTowers
	std::ranges::copy(map->placeForTower, std::back_inserter(avaliableSpotsForTowers));

	// Copy placeForTower elements to towersForUpgrade
	std::ranges::copy(map->placeForTower, std::back_inserter(towersForUpgrade));

	sf::Vector2f bounds;
	sf::Event ev;
	std::string nickname;
	bool validNickname = false;

	startTimer();
	initStartWindow();
	initLeaderboardWindow();
	initText();

	if (!this->toggleTurretTexture.loadFromFile("Textures/toggleMenu.png"))
	{
		std::cout << "ERROR::GAME::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	this->toggleTurret.setTexture(this->toggleTurretTexture);
	this->toggleTurret.setOrigin(sf::Vector2f(this->toggleTurret.getLocalBounds().width / 2.0f, this->toggleTurret.getLocalBounds().height / 2.0f));
	this->toggleTurret.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2.0f, sf::VideoMode::getDesktopMode().height / 2.0f));

	if (!this->font.loadFromFile("Font/Lato-BlackItalic.ttf"))
	{
		std::cout << "ERROR::GAME::FAILED TO LOAD FONT" << "\n";
	}
	sf::FloatRect upgradeTextBounds = upgradeText.getLocalBounds();

	this->upgrade.setSize(sf::Vector2f(300.f, 100.f));
	this->upgrade.setPosition(750.f, 500.f);
	this->upgrade.setFillColor(sf::Color::White);
	this->upgrade.setOutlineThickness(4.f);
	this->upgrade.setOutlineColor(sf::Color::Black);

	this->upgradeText.setPosition(this->upgrade.getPosition().x + 55.f, this->upgrade.getPosition().y+20.f);
	this->upgradeText.setFont(this->font);
	this->upgradeText.setCharacterSize(40);
	this->upgradeText.setString("UPGRADE");
	this->upgradeText.setFillColor(sf::Color::Black);

	while (this->window->isOpen())
	{



		while (this->window->pollEvent(ev))
		{
			if (ev.Event::type == sf::Event::Closed)
				this->window->close();
			if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape)
				this->window->close();
			if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Space)
				openToggleTurret = false;
			if (ev.Event::MouseButtonReleased && ev.Event::key.code == sf::Mouse::Left) {
				sf::FloatRect playButton = this->play.getGlobalBounds();
				sf::FloatRect leaderboardButton = this->leaderboardRectangle.getGlobalBounds();
				sf::FloatRect exitButton = this->exit.getGlobalBounds();
				sf::FloatRect backButton = this->backButton.getGlobalBounds();
				if (playButton.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
					startGame = true;
				}
				if (leaderboardButton.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
					leaderboardScreen = true;
				}
				if (exitButton.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
					this->window->close();
				}
				if (!startGame && leaderboardScreen)
				{
					if (backButton.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
					{
						startGame = false;
						leaderboardScreen = false;
						break;
					}
				}
			}
			if (hp <= 0)
			{
				if (ev.type == sf::Event::TextEntered) {
					if (ev.text.unicode < 128) {
						if (ev.text.unicode == '\b' && !nickname.empty()) {
							// Handle backspace key
							nickname.pop_back();
						}
						else if (ev.text.unicode != '\r' && ev.text.unicode != '\n') {
							// Append entered character to inputString (excluding Enter key)
							char c = static_cast<char>(ev.text.unicode);
							if (std::regex_match(std::string(1, c), std::regex("[a-z]"))) {
								nickname += c;
							}
						}
					}
				}
				if ((ev.Event::MouseButtonPressed && ev.Event::key.code == sf::Mouse::Left)) {
					sf::FloatRect leaderboardButtonEnd1 = this->leaderboardEnd.getGlobalBounds();
					sf::FloatRect exitGameOverButton = this->exitGameOver.getGlobalBounds();
					sf::FloatRect backButton1 = this->backButton.getGlobalBounds();
					if (leaderboardButtonEnd1.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
					{
						validNickname = std::regex_match(nickname, std::regex("[a-z]+"));
						std::vector<PlayerScore> leaderboard = loadLeaderboard();
						leaderboard.push_back({ nickname, this->points });
						std::ranges::sort(leaderboard, compareScores);
						saveLeaderboard(leaderboard);
						leaderboardScreenEnd = true;

					}
					if (exitGameOverButton.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
					{
						validNickname = std::regex_match(nickname, std::regex("[a-z]+"));
						std::vector<PlayerScore> leaderboard = loadLeaderboard();
						leaderboard.push_back({ nickname, this->points});
						std::ranges::sort(leaderboard, compareScores);
						saveLeaderboard(leaderboard);
						this->window->close();
						
					}
					if (startGame && leaderboardScreenEnd)
					{
						if (backButton1.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
						{
							startGame = true;
							leaderboardScreenEnd = false;
							break;
						}
					}
				}
				nicknameText.setString(nickname);
			}
				
			
			if (ev.Event::MouseButtonPressed && ev.Event::key.code == sf::Mouse::Left) {

				//finding avaliable spots for and palcing the tower there
				for (int i = 0; i < this->avaliableSpotsForTowers.size(); i++)
				{
					sf::FloatRect boundsPlaceForTowers = this->avaliableSpotsForTowers[i].getGlobalBounds();
					if (boundsPlaceForTowers.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
					{
						bounds = this->avaliableSpotsForTowers[i].getPosition();
						this->avaliableSpotsForTowers.erase(this->avaliableSpotsForTowers.begin() + i);
						openToggleTurret = true;
						j = 1;
					}
				}
			}
			if (j == 1) {
				if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Num1 && this->gold >= 200) {
					this->towers.push_back(new Syringe(bounds));
					openToggleTurret = false;
					j = 0;
					this->gold -= 200;
				}
				else if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Num2 && this->gold >= 100) {
					this->towers.push_back(new Pellet(bounds));
					openToggleTurret = false;
					j = 0;
					this->gold -= 100;
				}
				else if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Num3 && this->gold >= 125) {
					this->towers.push_back(new Vaccine(bounds));
					openToggleTurret = false;
					j = 0;
					this->gold -= 125;
				}


			}


			if (ev.Event::MouseButtonPressed && ev.Event::key.code == sf::Mouse::Right) {
				for (int i = 0; i < this->towersForUpgrade.size(); i++) {
					sf::FloatRect boundsTowersForUpgrade = this->towersForUpgrade[i].getGlobalBounds();
					if (boundsTowersForUpgrade.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
						this->towersForUpgrade.erase(this->towersForUpgrade.begin() + i);
						openTurretUpgrade = true;
						z = 1;
						break; // Exit the loop after finding the clicked tower
					}
				}
			}

			if (z == 1) {
				if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Enter && this->gold >= 150) {
					for (int i = 0; i < this->towers.size(); i++) {
						sf::FloatRect boundsTower = this->towers[i]->getBounds();
						if (boundsTower.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
							this->towers[i]->upgrade();  // Call upgrade() on the clicked tower
							this->gold -= 150;
							break; // Exit the loop after upgrading the clicked tower
						}
					}
					openTurretUpgrade = false;
					z = 0;
				}
				//if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Enter && gold >= 150) {
				//	auto mousePosition = sf::Mouse::getPosition();

				//	// Find the tower clicked by checking if its bounds contain the mouse position
				//	auto it = std::find_if(towers.begin(), towers.end(), [&](Tower* tower) {
				//		sf::FloatRect boundsTower = tower->getBounds();
				//		return boundsTower.contains(mousePosition.x, mousePosition.y);
				//		});

				//	if (it != towers.end()) {
				//		// Upgrade the clicked tower
				//		(*it)->upgrade();
				//		gold -= 150;
				//	}

				//	openTurretUpgrade = false;
				//	z = 0;
				//}
			}
		}

			/*std::cout << towers.size() << std::endl;*/
			for (int i = 0; i < towers.size(); i++)
			{
				if (this->towers[i]->attackSpeed > 50.f)
				{
					this->towers[i]->attackSpeed = 0.f;
				}
				//else {
				//	this->towers[i]->attackSpeed += 1.f;
				//}
			}
			auto currentTime1 = std::chrono::steady_clock::now();
			auto elapsedTime1 = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime1 - lastSpawnTime);
			for (int i = 0; i < this->towers.size(); i++) {
				if (this->towers[i]->attackSpeed == 2.f && (this->towers[i]->attackRange == 170.f || this->towers[i]->attackRange == 260.f)) {
					sf::Vector2f towerPosition = this->towers[i]->position;
					float minimumDistance = std::numeric_limits<float>::max();
					Enemy* closestEnemy = nullptr;
					for (Enemy* enemy : enemies) {
						float distanceFromTower = std::sqrt(std::pow(enemy->getPos().x - towers[i]->position.x, 2) + std::pow(enemy->getPos().y - towers[i]->position.y, 2));
						if (distanceFromTower < minimumDistance)
						{
							minimumDistance = distanceFromTower;
							closestEnemy = enemy;
						}
					}
					double dx = closestEnemy->getPos().x - towers[i]->position.x;
					double dy = closestEnemy->getPos().y - towers[i]->position.y;
					double angle = std::atan2(dy, dx) * 180 / 3.14;
					if (minimumDistance < this->towers[i]->attackRange) {
						if (elapsedTime1.count() >= spawnIntervalMillis2) {
							this->bullets.push_back(new VaccineBullet(this->towers[i]->position, angle));
							lastSpawnTime = currentTime1;
						}
					}


				}
				if (this->towers[i]->attackSpeed == 4.f && (this->towers[i]->attackRange == 250.f || this->towers[i]->attackRange == 300.f)) {
					sf::Vector2f towerPosition = this->towers[i]->position;
					float minimumDistance = std::numeric_limits<float>::max();
					Enemy* closestEnemy = nullptr;
					for (Enemy* enemy : enemies) {
						float distanceFromTower = std::sqrt(std::pow(enemy->getPos().x - towers[i]->position.x, 2) + std::pow(enemy->getPos().y - towers[i]->position.y, 2));
						if (distanceFromTower < minimumDistance)
						{
							minimumDistance = distanceFromTower;
							closestEnemy = enemy;
						}
					}
					double dx = closestEnemy->getPos().x - towers[i]->position.x;
					double dy = closestEnemy->getPos().y - towers[i]->position.y;
					double angle = std::atan2(dy, dx) * 180 / 3.14;
					if (minimumDistance < this->towers[i]->attackRange) {
						if (elapsedTime1.count() >= spawnIntervalMillis4) {
							this->bullets.push_back(new SyringeBullet(this->towers[i]->position, angle));
							lastSpawnTime = currentTime1;
						}

					}

				}
				if (this->towers[i]->attackSpeed == 1.f && (this->towers[i]->attackRange == 120.f || this->towers[i]->attackRange == 200.f)) {
					sf::Vector2f towerPosition = this->towers[i]->position;
					float minimumDistance = std::numeric_limits<float>::max();
					Enemy* closestEnemy = nullptr;
					for (Enemy* enemy : enemies) {
						float distanceFromTower = std::sqrt(std::pow(enemy->getPos().x - towers[i]->position.x, 2) + std::pow(enemy->getPos().y - towers[i]->position.y, 2));
						if (distanceFromTower < minimumDistance)
						{
							minimumDistance = distanceFromTower;
							closestEnemy = enemy;
						}
					}
					double dx = closestEnemy->getPos().x - towers[i]->position.x;
					double dy = closestEnemy->getPos().y - towers[i]->position.y;
					double angle = std::atan2(dy, dx) * 180 / 3.14;
					if (minimumDistance < this->towers[i]->attackRange) {
						if (elapsedTime1.count() >= spawnIntervalMillis1) {
							this->bullets.push_back(new PelletBullet(this->towers[i]->position, angle));
							lastSpawnTime = currentTime1;
						}

					}


				}
				for (int k = 0; k < bullets.size(); k++) {
					for (int j = 0; j < enemies.size(); j++) {
						sf::FloatRect bulletBounds = this->bullets[k]->sprite.getGlobalBounds();
						sf::FloatRect enemyBounds = this->enemies[j]->getBounds();
						if (bulletBounds.intersects(enemyBounds)) {
							delete this->bullets[k];
							this->bullets.erase(this->bullets.begin() + k);
							k--;
							this->enemies[j]->loseHp(this->towers[i]->damage);
							if (this->enemies[j]->hp == 0) {
								delete this->enemies[j];
								this->enemies.erase(this->enemies.begin() + j);
								this->gold += enemies[j]->gold;
								j--;  // Decrement the index since the vector has been modified

								break;  // Exit the inner loop since the bullet has been deleted

							}
							break;  // Exit the inner loop since the bullet has hit an enemy
						}
					}
				}
			}
			//
			//update entities
			//

			std::stringstream ss;
			ss << "Health: " << this->hp;
			this->health.setString(ss.str());


			std::stringstream ss1;
			ss1 << "Gold: " << this->gold;
			this->goldText.setString(ss1.str());


			elapsedTime += clock.restart().asSeconds();
			if (elapsedTime >= updateInterval.asSeconds())
			{
				if (this->hp > 0)
					points++;

				elapsedTime -= updateInterval.asSeconds();
			}

			std::stringstream ss2;
			ss2 << "Points: " << this->points;
			this->pointsText.setString(ss2.str());


			this->window->clear();

			if (!startGame && !leaderboardScreen) {
				this->window->draw(this->start);
				this->window->draw(this->startText);
				this->window->draw(this->play);
				this->window->draw(this->playText);
				this->window->draw(this->leaderboardRectangle);
				this->window->draw(this->leaderboardText);
				this->window->draw(this->exit);
				this->window->draw(this->exitText);
			}
			else if (!startGame && leaderboardScreen) {

				displayLeaderboard();
			}
			else
			{
				this->updateEnemies();
				this->map->render(*this->window);

				//Draw all the stuff
				this->window->draw(this->health);
				this->window->draw(this->goldText);

				for (auto* enemies : this->enemies)
				{
					enemies->render(this->window);
				}

				for (auto* tower : this->towers)
				{
					tower->render(this->window);
				}
				for (auto* bullet : this->bullets)
				{
					bullet->update(this->window);
					bullet->render(this->window);
				}
				for (auto i = bullets.begin(); i != bullets.end();)
				{
					if ((*i)->life == 0) {
						delete (*i);
						i = bullets.erase(i);
					}
					else i++;
				}

				if (openToggleTurret) {
					this->window->draw(this->toggleTurret);
				}
				if (openTurretUpgrade) {
					this->window->draw(this->upgrade);
					this->window->draw(this->upgradeText);
				}
				
				if (hp <= 0) {
					this->window->draw(this->endGame);
					this->window->draw(this->gameOverText);
					this->window->draw(this->pointsText);
					this->window->draw(this->enterNicknameText);
					this->window->draw(this->inputbox);
					this->window->draw(this->nicknameText);
					this->window->draw(this->hintNicknameText);
					this->window->draw(this->leaderboardEnd);
					this->window->draw(this->leaderboardEndText);
					this->window->draw(this->exitGameOver);
					this->window->draw(this->exitGameOverText);

					if (leaderboardScreenEnd)
						displayLeaderboard();
				}
								
			}
			this->window->display();
	}
}


void Game::updateEnemies()
{
	// Spawning
	this->spawnTimer += 0.1f;
	if (this->spawnTimer >= this->spawnTimerMax) {
		this->enemies.push_back(new Bacteria(-10.f, 750.f));
		this->enemies.push_back(new Infection(-10.f, 750.f));
		this->enemies.push_back(new Virus(-10.f, 750.f));
		this->spawnTimer = 0.f;
		if (isDurationPassed(std::chrono::minutes(1))) {
			for (auto* enemy : this->enemies) {
				enemy->upgrade();
			}
		}
		if (isDurationPassed(std::chrono::minutes(3))) {
			for (auto* enemy : this->enemies) {
				enemy->upgrade2();
			}
		}
		if (isDurationPassed(std::chrono::minutes(5))) {
			for (auto* enemy : this->enemies) {
				enemy->upgrade3();
			}
		}
	}

	// Update
	unsigned counter = 0;
	for (auto* enemy : this->enemies) {
		enemy->update(this->map);

		if (enemy->getBounds().left + 70.f > this->window->getSize().x) {
			this->hp = hp - enemy->getDamage();
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		++counter;
	}
}








