import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

enum Direction {
    LEFT,
    FORWARD,
    RIGHT,
}

interface Room {
    public String getKey();

    public String getName();

    public String getDescription();

    public void enter(GameState gameState);
}

class UsualRoom implements Room {
    public String getKey() {
        return "usual";
    }

    public String getName() {
        return "The usual room, nothing interesting here";
    }

    public String getDescription() {
        return "However, the loneliness is striking your soul hard";
    }

    public void enter(GameState gameState) {
        System.out.println("You stumble into the usual room, nothing interesting");
    }
}

class PerkRoom implements Room {
    private Random random = new Random();

    public String getKey() {
        return "perk";
    }

    public String getName() {
        return "The perk room, guaranteed rewards?";
    }

    public String getDescription() {
        return "It can't be that easy, right?";
    }

    public void enter(GameState gameState) {
        System.out.println("You stumble into the perk room, it's either a godsend, or hell");

        double deathMultiplier = this.random.nextDouble(2);
        int plusLives = this.random.nextInt(20) - 10;

        System.out.println(String.format("The RNG gods rolled a *= %1.2f for dying", deathMultiplier));
        System.out.println(String.format("The RNG gods rolled a += %d for lives", plusLives));

        gameState.deathPercentage *= deathMultiplier;
        gameState.lives += plusLives;
    }
}

class BossRoom implements Room {
    private Random random = new Random();

    public String getKey() {
        return "boss";
    }

    public String getName() {
        return "The boss room, I don't like this";
    }

    public String getDescription() {
        return "You feel an evil presence watching you.. You don't know what it is, but it is at least as strong as you";
    }

    public void enter(GameState gameState) {
        System.out.println("You stumble into the boss room");

        System.out.println("The fight begins");
        if (this.random.nextDouble(1) < 0.5) {
            System.out.println("Shame, but you lost the fight, the beast marked you");
            gameState.deathPercentage += 0.1;
            return;
        }

        System.out
                .println(
                        "You won the fight, the gained confidence minimizes your death percentages, and you gain 1 extra life");
        gameState.lives++;
        gameState.deathPercentage *= 0.1;
    }
}

class GameState {
    private Random random = new Random();

    public double deathPercentage = 0.05;
    public int turnCount = 0;
    public int lives = 3;

    public boolean didGameEnd() {
        return lives <= 0;
    }

    public void makeTurn() {
        this.turnCount++;
        this.deathPercentage += 0.01 * Math.log(this.turnCount);
        this.didDie();
    }

    public void printInfo() {
        System.out.println(String.format("""
                    [
                        Death on enter: %1.1f%% [%s]
                        Lives: %d
                    ]
                """, this.deathPercentage * 100, this.getDeathChanceText(), this.lives));
    }

    private void didDie() {
        boolean died = this.random.nextDouble(1) < this.deathPercentage;

        if (died) {
            this.lives--;
            System.out.println("You feel as though you lost a part of yourself when entering a room, -1 life");
        }
    }

    private String getDeathChanceText() {
        if (this.deathPercentage < 0.2) {
            return "KMR";
        }

        if (this.deathPercentage > 0.6) {
            return "!!!";
        }

        return "OK";
    }

}

class ChatBot {
    private String username;
    private Random random;

    private GameState gameState;

    public ChatBot() {
        this.random = new Random();
        this.username = "";
        this.gameState = new GameState();

        this.username = this.readLine("What's your username?");
        if (this.username.isBlank()) {
            panic("provide a username");
        }
    }

    private void clearTerminal() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public void start() {
        while (true) {
            this.gameState.makeTurn();
            this.gameState.printInfo();

            Room[] rooms = this.getRoomSelections();

            System.out.println(String.format("You have %d options:", rooms.length));

            for (Room room : rooms) {
                System.out.println(String.format("""
                        [%s]: %s
                        %s
                        """, room.getKey(), room.getName(), room.getDescription()));
            }

            String roomKey = this.readLine("Your choice?");
            boolean foundRoom = false;

            this.clearTerminal();

            for (Room room : rooms) {
                if (!room.getKey().equals(roomKey)) {
                    continue;
                }

                foundRoom = true;
                room.enter(this.gameState);
                break;
            }

            if (!foundRoom) {
                System.out.println("The company does not like corrupt inputs, -1 life");
                this.gameState.lives--;
            }

            if (this.gameState.didGameEnd()) {
                System.out.println("Game over");
                break;
            }
        }
    }

    private void panic(String msg) {
        System.err.println(msg);
        System.exit(1);
    }

    private Room[] getRoomSelections() {
        Room[] rooms = new Room[2];

        for (int i = 0; i < 2; i++) {
            int random = this.random.nextInt(3);

            switch (random) {
                case 0:
                    rooms[i] = new UsualRoom();
                    break;
                case 1:
                    rooms[i] = new PerkRoom();
                    break;
                case 2:
                    rooms[i] = new BossRoom();
                    break;
            }

        }

        return rooms;
    }

    private String readLine(String text) {
        System.out.println(String.format("[chatbot]: %s", text));

        if (!this.username.isBlank()) {
            System.out.print(String.format("[%s]: ", this.username));
        }

        BufferedReader stdinReader = new BufferedReader(new InputStreamReader(System.in));

        try {
            return stdinReader.readLine().trim();
        } catch (IOException error) {
            System.err.println(error);
        }

        return "";
    }
}

public class Main {
    public static void main(String[] args) {
        ChatBot chatbot = new ChatBot();
        chatbot.start();
    }
}
