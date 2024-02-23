program UndanganProgram;

type
  Undangan = record
    Kode: string;
    Jenis: string;
    Nama: string;
    TanggalAcara: string;
    BanyakPeserta: integer;
  end;

const
  MaxUndangan = 100;

var
  DataUndangan: array[1..MaxUndangan] of Undangan;
  JumlahUndangan: integer;

procedure TambahDataUndangan;
begin
  if JumlahUndangan < MaxUndangan then
  begin
    writeln('Masukkan data undangan:');
    JumlahUndangan := JumlahUndangan + 1;

    write('Kode Undangan: ');
    readln(DataUndangan[JumlahUndangan].Kode);

    write('Jenis Undangan: ');
    readln(DataUndangan[JumlahUndangan].Jenis);

    write('Nama Undangan: ');
    readln(DataUndangan[JumlahUndangan].Nama);

    write('Tanggal Acara: ');
    readln(DataUndangan[JumlahUndangan].TanggalAcara);

    write('Banyak Peserta: ');
    readln(DataUndangan[JumlahUndangan].BanyakPeserta);

    writeln('Data undangan berhasil ditambahkan.');
  end
  else
    writeln('Maaf, kapasitas undangan sudah penuh.');
end;

procedure LihatDataUndangan;
var
  i: integer;
begin
  writeln('Data Undangan:');
  for i := 1 to JumlahUndangan do
  begin
    writeln('Kode: ', DataUndangan[i].Kode);
    writeln('Jenis: ', DataUndangan[i].Jenis);
    writeln('Nama: ', DataUndangan[i].Nama);
    writeln('Tanggal Acara: ', DataUndangan[i].TanggalAcara);
    writeln('Banyak Peserta: ', DataUndangan[i].BanyakPeserta);
    writeln('--------------------------------------');
  end;
end;

procedure EditDataUndangan;
var
  KodeUndangan: string;
  i: integer;
begin
  writeln('Masukkan Kode Undangan yang akan di-edit: ');
  readln(KodeUndangan);

  for i := 1 to JumlahUndangan do
  begin
    if DataUndangan[i].Kode = KodeUndangan then
    begin
      writeln('Masukkan data baru untuk undangan ', KodeUndangan);
      write('Jenis Undangan: ');
      readln(DataUndangan[i].Jenis);

      write('Nama Undangan: ');
      readln(DataUndangan[i].Nama);

      write('Tanggal Acara: ');
      readln(DataUndangan[i].TanggalAcara);

      write('Banyak Peserta: ');
      readln(DataUndangan[i].BanyakPeserta);

      writeln('Data undangan berhasil di-edit.');
      exit;
    end;
  end;

  writeln('Undangan dengan Kode ', KodeUndangan, ' tidak ditemukan.');
end;

procedure HapusDataUndangan;
var
  KodeUndangan: string;
  i: integer;
begin
  writeln('Masukkan Kode Undangan yang akan dihapus: ');
  readln(KodeUndangan);

  for i := 1 to JumlahUndangan do
  begin
    if DataUndangan[i].Kode = KodeUndangan then
    begin
      DataUndangan[i] := DataUndangan[JumlahUndangan];
      JumlahUndangan := JumlahUndangan - 1;
      writeln('Data undangan berhasil dihapus.');
      exit;
    end;
  end;

  writeln('Undangan dengan Kode ', KodeUndangan, ' tidak ditemukan.');
end;

procedure Sorting;
var
  i, j: integer;
  Temp: Undangan;
begin
  for i := 1 to JumlahUndangan - 1 do
    for j := i + 1 to JumlahUndangan do
      if DataUndangan[i].BanyakPeserta > DataUndangan[j].BanyakPeserta then
      begin
        Temp := DataUndangan[i];
        DataUndangan[i] := DataUndangan[j];
        DataUndangan[j] := Temp;
      end;

  writeln('Data undangan berhasil diurutkan berdasarkan banyak peserta.');
end;

procedure Searching;
var
  KodeUndangan: string;
  i: integer;
begin
  writeln('Masukkan Kode Undangan yang akan dicari: ');
  readln(KodeUndangan);

  for i := 1 to JumlahUndangan do
  begin
    if DataUndangan[i].Kode = KodeUndangan then
    begin
      writeln('Data Undangan ditemukan:');
      writeln('Kode: ', DataUndangan[i].Kode);
      writeln('Jenis: ', DataUndangan[i].Jenis);
      writeln('Nama: ', DataUndangan[i].Nama);
      writeln('Tanggal Acara: ', DataUndangan[i].TanggalAcara);
      writeln('Banyak Peserta: ', DataUndangan[i].BanyakPeserta);
      exit;
    end;
  end;

  writeln('Undangan dengan Kode ', KodeUndangan, ' tidak ditemukan.');
end;

procedure MenuUtama;
var
  PilihanMenu: integer;
begin
  repeat
    writeln('Menu:');
    writeln('1. Tambah Data Undangan');
    writeln('2. Lihat Data Undangan');
    writeln('3. Edit Data Undangan');
    writeln('4. Hapus Data Undangan');
    writeln('5. Sorting Banyak Peserta');
    writeln('6. Searching');
    writeln('7. Keluar');
    write('Pilih menu: ');
    readln(PilihanMenu);

    case PilihanMenu of
      1: TambahDataUndangan;
      2: LihatDataUndangan;
      3: EditDataUndangan;
      4: HapusDataUndangan;
      5: Sorting;
      6: Searching;
      7: begin
            writeln('1. Muhammad Hafiz Hafiyyan (10123096)');
            writeln('2. Mohamad Rifaldy Firdaus (10123095)');
            writeln('3. Tira (10123112)');
            writeln('4. Raffi Zahran Gunawan (10123124)');
            writeln('Terima kasih. Program selesai.');
         end;
    else
      writeln('Menu tidak valid. Silakan pilih menu lain.');
    end;

  until PilihanMenu = 7;
end;

begin
  JumlahUndangan := 0;
  MenuUtama;
end.
