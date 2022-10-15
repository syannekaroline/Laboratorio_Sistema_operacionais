#!/bin/sh

cd ~/labSO/lab02/
tar -czf Producao.tar.gz Producao/

##########################################
Producao="/home/syannetavares/labSO/lab02/Producao.tar.gz"

#Gerar as chaves
key1=$(sha256sum $Producao | awk '{ print $1 }')
key2="e8143d6e27c4ca2737888e7baf559dcdc4a8163460f33a4c85e8c1e3bd080148" #chave gerada do Modelo.tar.gz

#Comparar as chave
if [ $key1 = $key2 ]; then
echo "Iguais"
else
echo "Diferentes"
#sendemail -f syanne.tavares@icen.ufpa.br -t syanne.tavares@icen.ufpa.br -u "Atenção aos arquivos de Produção" -m "Atenção!! Os arquivos de Produção estão modificados!!!" -s cupijo.ufpa.br:587 -xu syanne.tavares@icen.ufpa.br -xp 
echo "removendo o arquivo de producao"
rm -rf Producao/
echo "Extraindo modelo"
tar -xzf Modelo.tar.gz 
echo "O diretório de Produção Oficial foi restaurado!!"
fi
rm Producao.tar.gz
