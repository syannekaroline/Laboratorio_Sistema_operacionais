#!/bin/sh

cd ~/lab02/
zip Modelo -r Producao/ && zip Modelo -r Producao/
zip Producao -r Producao
##########################################
caminho1="/home/syannetavares/lab02/Modelo.zip"
caminho2="/home/syannetavares/lab02/Producao.zip"

#Gerar as chaves
key1=$(sha256sum $caminho1 | awk '{ print $1 }')
key2=$(sha256sum $caminho2 | awk '{ print $1 }')

#Comparar as chave
if [ $key1 = $key2 ]; then
echo "Iguais"
else
echo "Diferentes"
#sendemail -f syanne.tavares@icen.ufpa.br -t syanne.tavares@icen.ufpa.br -u "Atenção aos arquivos de Produção" -m "Atenção!! Os arquivos de Produção estão modificados!!!" -s cupijo.ufpa.br:587 -xu syanne.tavares@icen.ufpa.br -xp 
echo "removendo o arquivo de producao"
rm -rf Producao
echo "Extraindo modelo"
unzip Modelo.zip 
echo "O diretório de Produção Oficial foi restaurado!!"
fi

rm -rf Producao.zip
rm -rf Modelo.zip
