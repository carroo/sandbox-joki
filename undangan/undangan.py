from PIL import Image, ImageDraw, ImageFont

class Undangan:
    def __init__(self, kode, jenis, nama, tanggal_acara, banyak_peserta):
        self.kode = kode
        self.jenis = jenis
        self.nama = nama
        self.tanggal_acara = tanggal_acara
        self.banyak_peserta = banyak_peserta

MaxUndangan = 100
DataUndangan = [None] * MaxUndangan
JumlahUndangan = 0

def tambah_data_undangan():
    global JumlahUndangan
    if JumlahUndangan < MaxUndangan:
        print("Masukkan data undangan:")
        JumlahUndangan += 1

        kode = input("Kode Undangan: ")
        jenis = input("Jenis Undangan: ")
        nama = input("Nama Undangan: ")
        tanggal_acara = input("Tanggal Acara: ")
        banyak_peserta = int(input("Banyak Peserta: "))

        DataUndangan[JumlahUndangan - 1] = Undangan(kode, jenis, nama, tanggal_acara, banyak_peserta)
        print("Data undangan berhasil ditambahkan.")
    else:
        print("Maaf, kapasitas undangan sudah penuh.")

def lihat_data_undangan():
    print("Data Undangan:")
    for undangan in DataUndangan[:JumlahUndangan]:
        print(f"Kode: {undangan.kode}")
        print(f"Jenis: {undangan.jenis}")
        print(f"Nama: {undangan.nama}")
        print(f"Tanggal Acara: {undangan.tanggal_acara}")
        print(f"Banyak Peserta: {undangan.banyak_peserta}")
        print("--------------------------------------")

def edit_data_undangan():
    kode_undangan = input("Masukkan Kode Undangan yang akan di-edit: ")
    for undangan in DataUndangan[:JumlahUndangan]:
        if undangan.kode == kode_undangan:
            print(f"Masukkan data baru untuk undangan {kode_undangan}")
            undangan.jenis = input("Jenis Undangan: ")
            undangan.nama = input("Nama Undangan: ")
            undangan.tanggal_acara = input("Tanggal Acara: ")
            undangan.banyak_peserta = int(input("Banyak Peserta: "))
            print("Data undangan berhasil di-edit.")
            return
    print(f"Undangan dengan Kode {kode_undangan} tidak ditemukan.")

def hapus_data_undangan():
    kode_undangan = input("Masukkan Kode Undangan yang akan dihapus: ")
    global JumlahUndangan
    for i in range(JumlahUndangan):
        if DataUndangan[i].kode == kode_undangan:
            DataUndangan[i] = DataUndangan[JumlahUndangan - 1]
            JumlahUndangan -= 1
            print("Data undangan berhasil dihapus.")
            return
    print(f"Undangan dengan Kode {kode_undangan} tidak ditemukan.")

def sorting():
    global JumlahUndangan
    DataUndangan[:JumlahUndangan] = sorted(DataUndangan[:JumlahUndangan], key=lambda x: x.banyak_peserta)
    print("Data undangan berhasil diurutkan berdasarkan banyak peserta.")


def searching():
    print("Pilih kriteria pencarian:")
    print("1. Berdasarkan Kode Undangan")
    print("2. Berdasarkan Nama Undangan")
    pilihan_cari = int(input("Pilihan: "))

    if pilihan_cari == 1:
        kode_undangan = input("Masukkan Kode Undangan yang akan dicari: ")
        for undangan in DataUndangan[:JumlahUndangan]:
            if undangan.kode == kode_undangan:
                print("Data Undangan ditemukan:")
                print(f"Kode: {undangan.kode}")
                print(f"Jenis: {undangan.jenis}")
                print(f"Nama: {undangan.nama}")
                print(f"Tanggal Acara: {undangan.tanggal_acara}")
                print(f"Banyak Peserta: {undangan.banyak_peserta}")
                return
        print(f"Undangan dengan Kode {kode_undangan} tidak ditemukan.")

    elif pilihan_cari == 2:
        nama_undangan = input("Masukkan Nama Undangan yang akan dicari: ")
        for undangan in DataUndangan[:JumlahUndangan]:
            if undangan.nama == nama_undangan:
                print("Data Undangan ditemukan:")
                print(f"Kode: {undangan.kode}")
                print(f"Jenis: {undangan.jenis}")
                print(f"Nama: {undangan.nama}")
                print(f"Tanggal Acara: {undangan.tanggal_acara}")
                print(f"Banyak Peserta: {undangan.banyak_peserta}")
                return
        print(f"Undangan dengan Nama {nama_undangan} tidak ditemukan.")

    else:
        print("Pilihan tidak valid. Pencarian dibatalkan.")


def printUndangan():
    global JumlahUndangan

    if JumlahUndangan == 0:
        print("Belum ada data undangan.")
        return

    # Create a blank image
    image = Image.new('RGB', (600, 300), 'white')
    draw = ImageDraw.Draw(image)
    font = ImageFont.load_default()

    y_position = 10

    for undangan in DataUndangan[:JumlahUndangan]:
        draw.text((10, y_position), f"Kode: {undangan.kode}", fill='black', font=font)
        draw.text((10, y_position + 20), f"Jenis: {undangan.jenis}", fill='black', font=font)
        draw.text((10, y_position + 40), f"Nama: {undangan.nama}", fill='black', font=font)
        draw.text((10, y_position + 60), f"Tanggal Acara: {undangan.tanggal_acara}", fill='black', font=font)
        draw.text((10, y_position + 80), f"Banyak Peserta: {undangan.banyak_peserta}", fill='black', font=font)
        draw.line([(0, y_position + 100), (600, y_position + 100)], fill='black', width=2)

        y_position += 120

    image.save("undangan_image.png")
    print("Data undangan berhasil di-generate ke dalam gambar (undangan_image.png).")


def menu_utama():
    global JumlahUndangan
    while True:
        print("Menu:")
        print("1. Tambah Data Undangan")
        print("2. Lihat Data Undangan")
        print("3. Edit Data Undangan")
        print("4. Hapus Data Undangan")
        print("5. Sorting Banyak Peserta")
        print("6. Searching")
        print("7. Print Undangan")
        print("8. Keluar")
        pilihan_menu = int(input("Pilih menu: "))

        if pilihan_menu == 1:
            tambah_data_undangan()
        elif pilihan_menu == 2:
            lihat_data_undangan()
        elif pilihan_menu == 3:
            edit_data_undangan()
        elif pilihan_menu == 4:
            hapus_data_undangan()
        elif pilihan_menu == 5:
            sorting()
        elif pilihan_menu == 6:
            searching()
        elif pilihan_menu == 7:
             printUndangan()
        elif pilihan_menu == 8:
            print("Terima kasih. Program selesai.")
            print("1. Muhammad Hafiz Hafiyyan (10123096")
            print("2. Mohamad Rifaldy Firdaus (10123095)")
            print("3. Tira (10123112)")
            print("4. Raffi Zahran Gunawan (10123124)")
            break
        else:
            print("Menu tidak valid. Silakan pilih menu lain.")

if __name__ == "__main__":
    JumlahUndangan = 0
    menu_utama()
