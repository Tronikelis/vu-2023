package com.donatas.one;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

import com.google.gson.Gson;

interface Comparator<T> {
    int run(T a, T b);
}

public class App {
    static <T> void shellSort(T[] arr, Comparator<T> comparator) {
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

    public static void main(String[] args) throws IOException {
        PhoneNumData phoneNumData = new PhoneNumData();
        BillData billData = new BillData();

        Bill[] sortedBills = new Bill[billData.bills.size()];
        sortedBills = billData.bills.toArray(sortedBills);

        // Use the programmed sorting algorithm to sort the list of data from the second
        // table by two fields:

        // first by personId
        shellSort(sortedBills, (a, b) -> {
            Integer aPersonId = phoneNumData.data.get(a.phone).personId;
            Integer bPersonId = phoneNumData.data.get(b.phone).personId;

            return aPersonId.compareTo(bPersonId);
        });

        shellSort(sortedBills, (a, b) -> {
            return a.month.compareTo(b.month);
        });

        for (Bill bill : sortedBills) {
            PhoneNum phoneNum = phoneNumData.data.get(bill.phone);

            System.out.println(
                    "[ " +
                            phoneNum.personId +
                            ", " +
                            phoneNum.personName +
                            ", " +
                            bill.month.toString() +
                            ", " +
                            bill.phone +
                            ", " +
                            bill.amount.toString()
                            +
                            " ]"

            );
        }

        HashMap<Integer, HashSet<Integer>> personIdToMonths = new HashMap<>();
        HashMap<Integer, PhoneNum> personIdToPhoneNum = new HashMap<>();

        for (PhoneNum phoneNum : phoneNumData.data.values()) {
            personIdToPhoneNum.put(phoneNum.personId, phoneNum);

            HashSet<Integer> current = personIdToMonths.get(phoneNum.personId);

            if (current == null) {
                current = new HashSet<>();
                personIdToMonths.put(phoneNum.personId, current);
            }

            for (Bill bill : billData.bills) {
                if (bill.phone.equals(phoneNum.phone)) {
                    continue;
                }

                current.add(bill.month);
            }
        }

        for (Map.Entry<Integer, HashSet<Integer>> entry : personIdToMonths.entrySet()) {
            Integer personId = entry.getKey();
            HashSet<Integer> months = entry.getValue();

            for (Integer month : months) {
                Integer total = 0;

                for (Bill bill : billData.bills) {
                    Integer billPersonId = phoneNumData.data.get(bill.phone).personId;

                    if (!month.equals(bill.month) || !billPersonId.equals(personId)) {
                        continue;
                    }

                    total += bill.amount;
                }

                System.out.println(
                        "personId = " + personId.toString() + ", " +
                                "personName = " + personIdToPhoneNum.get(personId).personName + ", " +
                                "month = " + month.toString() + ", " +
                                "totalAmount = " + total.toString());
            }
        }

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
    Integer month;
    Integer amount;
    String phone;

    Bill(Integer month, String phone, Integer amount) {
        this.month = month;
        this.phone = phone;
        this.amount = amount;
    }
}

class BillData {
    ArrayList<Bill> bills;

    BillData() throws IOException {
        String jsonString = Files.readString(Path.of("./bill.json"));

        Gson gson = new Gson();

        Bill[] bills = gson.fromJson(jsonString, Bill[].class);

        this.bills = new ArrayList<>(Arrays.asList(bills));
    }
}