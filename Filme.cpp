    if (subtipo == "Filme")
    {
      cout << "Filme " << id << ":";
      cout << nome;
      cout << " (" << ano << "), ";
      cout << genero;
      cout << ", " << filme_duracao << " min, ";
      cout << "nota: " << get_media_avaliacao() << std::endl;
    }