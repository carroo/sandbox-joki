

nip = []
kriteria = []
bobot = []
predikat = []
nilai = []
menu = 0  
submenu = 0 


while menu != 4:
    print('Menu')
    print('1. Kriteria')
    print('2. Masukan NIP')
    print('3. Nilai')
    print('4. Keluar')
    menu = int(input('Masukkan menu: '))

    if menu == 1:
        while submenu != 3 :
            print('Kriteria')
            print('-'*45)
            print("| {:<10} | {:<15} | {:<10} |".format("Index", "Kriteria", "Bobot"))
            print('-'*45)
            for i in range(len(kriteria)):
                print("| {:<10} | {:<15} | {:<10} |".format(i+1, kriteria[i], bobot[i]))
            print('-'*45)
            print('1. Input')
            print('2. Delete')
            print('3. Kembali')
            submenu = int(input('Masukkan submenu: '))

            if submenu == 1:
                new_kriteria = input('Masukkan kriteria baru: ')
                new_bobot = int(input('Masukkan bobot kriteria: '))
                if sum(bobot) + new_bobot > 100:
                    print('Total bobot melebihi 100. Kriteria tidak dapat ditambahkan.')
                else:
                    kriteria.append(new_kriteria)
                    bobot.append(new_bobot)
                    for i in range(len(nip)):
                        nilai[i].append(0)
                    print('Kriteria berhasil ditambahkan!')

            elif submenu == 2:
                del_index = int(input('Masukkan indeks kriteria yang akan dihapus: '))
                if 1 <= del_index <= len(kriteria):
                    del kriteria[del_index - 1]
                    del bobot[del_index - 1]
                    for i in range(len(nip)):
                        del nilai[i][del_index - 1]
                    print('Kriteria berhasil dihapus!')
                else:
                    print('Indeks kriteria tidak valid.')

            else:
                print('Menu tidak valid!')
    elif menu == 2 :
        while submenu != 3 :
            print('Nomer Induk Pegawai (NIP)')
            print('-'*32)
            print("| {:<10} | {:<15} |".format("Index", "NIP"))
            print('-'*32)
            for i in range(len(nip)):
                print("| {:<10} | {:<15} |".format(i+1, nip[i]))
            print('-'*32)
            print('1. Input')
            print('2. Delete')
            print('3. Kembali')
            submenu = int(input('Masukkan submenu: '))

            if submenu == 1:
                new_nip = input('Masukkan NIP baru: ')
                nip.append(new_nip)
                nilai.append([0] * len(kriteria))
                predikat.append(0)
                print('NIP berhasil ditambahkan!')
            elif submenu == 2:
                del_index = int(input('Masukkan indeks NIP yang akan dihapus: '))
                if 1 <= del_index <= len(nip):
                    del nip[del_index - 1]
                    del nilai[del_index - 1]
                    del predikat[del_index-1]
                    print('NIP berhasil dihapus!')
                else:
                    print('Indeks NIP tidak valid.')
            else:
                print('Menu tidak valid!')
    elif menu == 3 : 
        while submenu != 2 :
            print('Nilai')
            print()
            header = "| {:<10} |".format("NIP")
            for k, b in zip(kriteria, bobot):
                header += " {:<8}({}%) |".format(k, b)
            header += " {:<10} |".format("NilaiAkhir")
            
            print(header)
            print('-' * (15 * (len(kriteria) + 2)))

            for i in range(len(nip)):
                if any(nilai):
                    row = "| {:<10} |".format(nip[i])
                    predikat[i] = 0
                    for j in range(len(kriteria)):
                        predikat[i] += round((nilai[i][j] * bobot[j] / 100), 3)
                        row += " {:<13} |".format(nilai[i][j])
                    row += " {:<10} |".format(predikat[i])
                    print(row)

            print('-' * (15 * (len(kriteria) + 2)))
            print()
            print('predikat')
            header = "| {:<10} |".format("NIP")
            for k, b in zip(kriteria, bobot):
                header += " {:<8}({}%) |".format(k, b)
            header += " {:<10} |".format("NilaiAkhir")
            header += " {:<10} |".format("Predikat")
            
            print(header)
            print('-' * (16 * (len(kriteria) + 2)))

            for i in range(len(nip)):
                if any(nilai):
                    row = "| {:<10} |".format(nip[i])
                    for j in range(len(kriteria)):
                        if nilai[i][j] > 9:
                            p = "A"
                        elif nilai[i][j] > 8:
                            p = "B"
                        elif nilai[i][j] > 7:
                            p = "C"
                        else:
                            p = "D"
                        row += " {:<13} |".format(p)
                    if predikat[i] > 9:
                        pa = "A"
                        pak = "Sangat Baik"
                    elif predikat[i] > 8:
                        pa = "B"
                        pak = "Baik"
                    elif predikat[i] > 7:
                        pa = "C"
                        pak = "Cukup"
                    else:
                        pa = "D"
                        pak = "Kurang"
                    row += " {:<10} |".format(pa)
                    row += " {:<10} |".format(pak)
                    print(row)

            print('-' * (16 * (len(kriteria) + 2)))
            print()
            print('1. Masukan ulang nilai. ')
            print('2. Kembali. ')
            submenu = int(input('masukan submenu : '))
            if submenu == 1 :
                for i in range(len(nip)):
                    for j in range(len(kriteria)):
                        nilai_input = float(input(f"Masukkan nilai untuk NIP {nip[i]} dan kriteria {kriteria[j]}: "))
                        nilai[i][j] = nilai_input
            elif submenu != 2:
                print('Menu tidak valid!')
    else:
        print('Menu tidak valid!')
    submenu = 0
