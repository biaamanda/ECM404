import os
import shutil
from typing import Optional, List

def needs_organization(list_dir: str) -> bool:
    """Check if the directory needs organization by looking for exercise folders with main.c"""
    if not os.path.exists(list_dir):
        return False
        
    exercise_dirs = [d for d in os.listdir(list_dir) 
                    if os.path.isdir(os.path.join(list_dir, d)) 
                    and d.startswith('ex')]
                    
    for ex_dir in exercise_dirs:
        ex_path = os.path.join(list_dir, ex_dir)
        if os.path.exists(os.path.join(ex_path, 'main.c')):
            return True
    return False

def organize_list(list_dir: str) -> int:
    """Organize a single list directory. Returns number of exercises organized."""
    if not os.path.exists(list_dir):
        print(f"O diretório {list_dir} não existe!")
        return 0
        
    exercises_organized = 0
    exercise_dirs = [d for d in os.listdir(list_dir) 
                    if os.path.isdir(os.path.join(list_dir, d)) 
                    and d.startswith('ex')]
    
    for ex_dir in exercise_dirs:
        ex_path = os.path.join(list_dir, ex_dir)
        main_file = os.path.join(ex_path, 'main.c')
        
        if os.path.exists(main_file):
            new_filename = f"{ex_dir}.c"
            new_filepath = os.path.join(list_dir, new_filename)
            
            try:
                shutil.move(main_file, new_filepath)
                print(f"Arquivo movido: {main_file} → {new_filepath}")
                
                shutil.rmtree(ex_path)
                print(f"Diretório removido: {ex_path}")
                exercises_organized += 1
                
            except Exception as e:
                print(f"Erro ao processar {ex_path}: {str(e)}")
    
    return exercises_organized

def get_available_lists() -> List[str]:
    """Get all L* directories in current path"""
    return sorted([d for d in os.listdir('.') 
                  if os.path.isdir(d) and d.startswith('L')])

def main():
    available_lists = get_available_lists()
    
    if not available_lists:
        print("Nenhum diretório L* encontrado no diretório atual!")
        return
        
    print("\nListas disponíveis:", ", ".join(available_lists))
    print("\nOpções:")
    print("1. Organizar todas as listas")
    print("2. Organizar uma lista específica")
    
    while True:
        choice = input("\nEscolha uma opção (1 ou 2): ").strip()
        if choice in ['1', '2']:
            break
        print("Opção inválida. Por favor, digite 1 ou 2.")
    
    lists_to_organize = []
    if choice == '1':
        lists_to_organize = available_lists
    else:
        while True:
            list_num = input("\nDigite o número da lista (exemplo: para L1 digite 1): ").strip()
            target_dir = f"L{list_num}"
            if target_dir in available_lists:
                lists_to_organize = [target_dir]
                break
            print(f"Lista L{list_num} não encontrada. Listas disponíveis:", ", ".join(available_lists))
    
    total_organized = 0
    for list_dir in lists_to_organize:
        if needs_organization(list_dir):
            print(f"\nOrganizando {list_dir}...")
            exercises_organized = organize_list(list_dir)
            total_organized += exercises_organized
            print(f"Organizados {exercises_organized} exercícios em {list_dir}")
        else:
            print(f"\n{list_dir} já está organizado ou não contém exercícios para organizar")
    
    if total_organized == 0:
        print("\nNenhuma organização necessária. Todos os diretórios especificados já estão organizados!")
    else:
        print(f"\nOrganização concluída! Total de exercícios organizados: {total_organized}")

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nOperação cancelada pelo usuário")
    except Exception as e:
        print(f"\nOcorreu um erro inesperado: {str(e)}")