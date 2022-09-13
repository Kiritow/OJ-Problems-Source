    update salary set sex = case sex
    when 'f' then 'm'
    when 'm' then 'f'
    end
