# Tucil1_13521043
IF2211 Strategi Algoritma - Tugas Kecil 1

Nigel Sahl (13521043) - Mahasiswa Semester 4 di Teknik Informatika ITB Angkatan 2021


## Table of Contents
- [General Info](#general-information)
- [Deskripsi Singkat Program](#Deskripsi-Singkat-Program)
- [Features](#features)
- [Screenshots](#screenshots)
- [Program Requirements](#Program-Requirements)
- [Cara menjalankan program](#cara-menjalankan-program)
- [Project Status](#project-status)
- [Room for Improvement](#room-for-improvement)


## General Information
Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka random sehingga mendapatkan hasil akhir sejumlah 24. Permainan ini menarik cukup banyak peminat dikarenakan dapat meningkatkan kemampuan berhitung serta mengasah otak agar dapat berpikir dengan cepat dan akurat. Permainan Kartu 24 biasa dimainkan dengan menggunakan kartu remi. Kartu remi terdiri dari 52 kartu yang terbagi menjadi empat suit (sekop, hati, keriting, dan wajik) yang masing-masing terdiri dari 13 kartu (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). Yang perlu diperhatikan hanyalah nilai kartu yang didapat (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). As bernilai 1, Jack bernilai 11, Queen bernilai 12, King bernilai 13, sedangkan kartu bilangan memiliki nilai dari bilangan itu sendiri. Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas.


## Deskripsi Singkat Program
Program terdiri dari tiga opsi pada Main Menu yaitu:
1. Input 4 Cards : memasukkan 4 buah kartu dari 13 pilihan kartu (Cards : A,2,3,4,5,6,7,8,9,10,J,K,Q)
2. Generate 4 Random Numbers : menghasilkan 4 buah angka secara random
3. Exit : keluar dari program
   Jika pengguna memilih opsi 1 atau 2, program akan melanjutkan pada algoritma Brute Force. Algoritma tersebut secara singkat yakni dengan melakukan permutasi kepada 4 angka baik dari opsi 1 maupun 2. Setelah itu program mengkombinasikan operasi dasar yaitu penjumlahan (+), pengurangan (-), perkalian (×), divisi (/). Terakhir, program akan memasangkan deretan ekspresi tersebut (angka-angka dan operasi-operasi dasar) dengan dua buah kurung buka dan kurung tutup lalu mengevaluasi hasilnya. Apabila hasilnya adalah 24 maka ekspresi matematika tersbut adalah salah satu solusi. Di akhir program akan menampilkan banyak solusi dan deretan solusi-solusi yang ada serta waktu eksekusi algoritma Brute Force.


## Features
1. Input 4 Cards
2. Generate 4 random numbers
3. Display all the solutions of 24 Card Game
4. Save all the solutions


## Screenshots
![Example screenshot 1](./doc/pic1.png)

![Example screenshot 2](./doc/pic2.png)


## Program Requirements
Program membutuhkan beberapa library yang digunakan yaitu:
- stdio.h
- stdlib.h
- string.h
- time.h


## Cara menjalankan program
1. Buka terminal pada direktori folder src yang berisi main.c
2. Jika menggunakan terminal pada Ubuntu atau WSL jalankan program dengan command "gcc main.c ADT_MesinKata/mesinkarakter.c ADT_MesinKata/mesinkata.c ADT_MesinKata/string.c -lm -o p && ./p". Jika menggunakan terminal lain jalankan dengan command "gcc main.c ADT_MesinKata/mesinkarakter.c ADT_MesinKata/mesinkata.c ADT_MesinKata/string.c -lm -o p", setelah itu ketikan command "./p" atau ".\p" pada terminal.
3. Terdapat beberapa tiga buah opsi yang dapat dipilih yaitu :

   a. Jika pengguna ingin memasukkan keempat pilihan kartunya sendiri, pengguna dapat memilih nomor 1 (1. Input 4 Cards). .... .Setelah selesai pengguna dapat memilih opsi 3 untuk exit dan opsi 0 untuk kembali ke Main Menu.

   b. Jika pengguna menggunakan empat kartu acak, pengguna dapat memilih nomor 2 (2. Generate 4 Random Numbers). .Setelah selesai pengguna dapat memilih opsi 3 untuk exit dan opsi 0 untuk kembali ke Main Menu.

   c. Jika pengguna ingin keluar pengguna dapat memilih nomor 3 (3. Exit).


## Project Status
Project is: _complete_


## Room for Improvement
Room for improvement:

- speed up the execution of the program
- correction of the program's Brute Force algorithm
