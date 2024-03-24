import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.HashMap;
import com.google.gson.Gson;

interface Comparator<T> {
    int run(T a, T b);
}

public class Main {
    static <T extends Comparable<T>> void shellSort(T[] arr, Comparator<T> comparator) {
        int gap = arr.length / 2;

        while (gap != 0) {
            for (int i = gap; i < arr.length; i++) {
                int j = i;

                while (j - gap >= 0 && comparator.run(arr[j], arr[j - gap]) > 0) {
                    T temp = arr[j - gap];
                    arr[j - gap] = arr[j];
                    arr[j] = temp;

                    j -= gap;
                }
            }

            gap /= 2;
        }
    }

    public static void main(String[] args) {
        PhoneNumData phoneNumData = new PhoneNumData();
        BillData billData = new BillData();

    }
}

class PhoneNum {
    String phone;
    Integer personId;
    String personName;

    PhoneNum(
            String phone,
            Integer personId,
            String personName) {
        this.phone = phone;
        this.personId = personId;
        this.personName = personName;
    }
}

class PhoneNumData {
    HashMap<String, PhoneNum> data;

    PhoneNumData() throws IOException {
        data = new HashMap<>();

        String jsonString = Files.readString(Path.of("./phone_num.json"));

        Gson gson = new Gson();

        PhoneNum[] parsed = gson.fromJson(jsonString, PhoneNum[].class);

        for (PhoneNum num : parsed) {
            data.put(num.phone, num);
        }
    }
}

class Bill {
    String month;
    String phone;
    String amount;

    Bill(Integer month, String phone, Integer amount) {
        this.month = month;
        this.phone = phone;
        this.amount = amount;
    }
}

class BillData {
    ArrayList<Bill> bills;

    BillData() {
        data = new ArrayList<>();

        String jsonString = Files.readString(Path.of("./bill.json"));

        Gson gson = new Gson();

        this.bills = gson.fromJson(jsonString, new TypeToken<ArrayList<Bill>>() {
        }.getType());
    }
}