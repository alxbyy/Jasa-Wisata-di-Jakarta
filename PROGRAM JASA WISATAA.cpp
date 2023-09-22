#include <stdio.h>
#include <string.h>


char * nama_paket[100];
char * fasilitas[100];
struct Daftar_Pembayaran_Travel
{
	char nama_peserta[100], fasilitas;
	int jumlah_biaya;
}peserta;

int budget_min(int pesanan_termurah,int layanan_termurah){
	int hasil;
	hasil = pesanan_termurah + layanan_termurah;
	return hasil;
}


int main()
{
	Daftar_Pembayaran_Travel peserta[10];
	char kode_tambahan;
	int kode_paket, tarif_paket, tarif_tambahan, pajak[100], jumlah_tarif[100],jumlah_pelanggan,budgetminimal;
	printf("\n                                     Travelako                               ");
	printf("\n  __________________________________________________________________________________");
	printf("\n | Kode\t\t  Tempat Wisata\t\t\t\t  Jam Buka\t Tarif\t    |");
	printf("\n | Pesanan\t\t                \t\t            \t\t    |");
	printf("\n  __________________________________________________________________________________");
	printf("\n | 01\t\t  Ancol - Moja Museum             \t 06.00-21.00 \t Rp. 200.000|");
	printf("\n | 02\t\t  JSky Ferris Wheel - Haluu World \t 10.00-21.30 \t Rp. 450.000|");
	printf("\n | 03\t\t  Como Park - Jakarta Aquarium -  \t 10.00-20.00 \t Rp. 600.000|");
	printf("\n |   \t\t  Taman Octagon Wave              \t   \t                    |");
	printf("\n  __________________________________________________________________________________");
	
	printf("\n\n\n Layanan Tambahan :");
	printf("\n  ______________________________________");
	printf("\n | Kode\t       Fasilitas\tTarif   |");
	printf("\n | Layanan\t            \t        |");
	printf("\n  ______________________________________");
	printf("\n | A\t      Home Stay        1.500.000|");
	printf("\n | B\t      Sewa Kendaraan     500.000|");
	printf("\n | C\t      Kuliner            150.000|");
	printf("\n | D\t      Pelayanan Medis    300.000|");
	printf("\n  ______________________________________\n\n");
	
	int pesanan_termurah = 200000;
	int layanan_termurah = 150000;
	budgetminimal = budget_min(pesanan_termurah,layanan_termurah);
	printf(" Budget minimal pelanggan = %d", budgetminimal);
	printf("\n\n Masukkan jumlah pelanggan : ");
	scanf("%d", &jumlah_pelanggan);
	printf("\n\n\n ----------------------------------------------------------------------------------");
	printf("\n                               INPUT PEMBAYARAN TRAVELAKO                                 ");
	printf("\n ----------------------------------------------------------------------------------");
	for(int i=1; i<=jumlah_pelanggan; i++)
	{
		printf("\n %d.", i);
		printf("\n Nama Pelanggan	: ");scanf("%s", peserta[i].nama_peserta);
		ulang  :
		printf(" Kode Pesanan	: ");scanf("%d", &kode_paket);
			if(kode_paket==01||kode_paket==1)
			{
				nama_paket[i]="Ancol - Moja Museum                 \t";
				tarif_paket=200000;
			}
			else if(kode_paket==02||kode_paket==2)
			{
				nama_paket[i]="JSky Ferris Wheel - Haluu World     \t";
				tarif_paket=450000;
			}
			else if(kode_paket==03||kode_paket==3)
			{
				nama_paket[i]="ComoPrk - JKT Aquarium - Tmn Octagon\t";
				tarif_paket=600000;
			}
			else
			{
				printf(" Pesanan Tidak Tersedia\a\a\n"); goto ulang;
			}
			printf(" Paket wisata	: %s\n", nama_paket[i]);
			ulangan:
			printf(" Kode Layanan	: ");scanf("%s", &kode_tambahan);
				if(kode_tambahan=='a'||kode_tambahan=='A')
				{
					fasilitas[i]="Home Stay\t";
					tarif_tambahan=1500000;
				}
				else if(kode_tambahan=='b'||kode_tambahan=='B')
				{
					fasilitas[i]="Sewa Kendaraan\t";
					tarif_tambahan=500000;
				}
				else if(kode_tambahan=='c'||kode_tambahan=='C')
				{
					fasilitas[i]="Kuliner    \t";
					tarif_tambahan=150000;
				}
				else if(kode_tambahan=='d'||kode_tambahan=='D')
				{
					fasilitas[i]="Pelayanan Medis    ";
					tarif_tambahan=300000;
				}
				else
				{
					printf(" Paket Layanan Tidak Tersedia\a\a\n"); goto ulangan;
				}
		printf(" Fasilitas	: %s", fasilitas[i]);
		jumlah_tarif[i]=tarif_paket+tarif_tambahan;
		pajak[i]=0.1*jumlah_tarif[i];
		peserta[i].jumlah_biaya=jumlah_tarif[i]+pajak[i];
		printf("\n\n ---------------------------------------------------------------------------");
	}
	printf("\n -----------------------------------------------------------------------------------");
	printf("\n\n\n\n                           DAFTAR PEMBAYARAN TRAVELAKO                       ");
	printf("\n  ------------------------------------------------------------------------------------------------------");
	printf("\n | No  Nama\t Nama Pesanan\t\t\t         Fasilitas\t         Tarif\t   Pajak  Total |");
	printf("\n |     Peserta\t         \t\t\t         Tambahan\t          Awal             Biaya|");
	printf("\n  ------------------------------------------------------------------------------------------------------");
	for(int i=1; i<=jumlah_pelanggan; i++)
	printf("\n | %d   %s\t %s %s\t  %d   %d   %d|", i, peserta[i].nama_peserta, nama_paket[i], fasilitas[i], jumlah_tarif[i], pajak[i], peserta[i].jumlah_biaya);
	printf("\n  ------------------------------------------------------------------------------------------------------\n\n\n");
	
	return 0;
	
}
