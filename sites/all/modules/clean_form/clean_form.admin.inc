<?php

function clean_form_admin_settings() {
  $form = array();
  
  $form['toggle_front_page'] = array(
    '#title' => t('Turn Front Page settings On/Off'),
    '#type' => 'radios',
    '#description' => t('Use this to select whether Clean forms is activated or not for the Front Page.'),
    '#options' => array(
      'on' => 'On',
      'off' => 'Off',
    ),
    '#default_value' => variable_get('toggle_front_page', 'on')
  );
  
    
  $form['toggle_product'] = array(
    '#title' => t('Turn Add Product settings On/Off'),
    '#type' => 'radios',
    '#description' => t('Use this to select whether Clean forms is activated or not for adding Products.'),
    '#options' => array(
      'on' => 'On',
      'off' => 'Off',
    ),
    '#default_value' => variable_get('toggle_product', 'on')
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  
  return $form;
}

function clean_form_admin_settings_submit(&$form, &$form_state) {
  variable_set('toggle', array(
    0 => $form_state['values']['toggle_front_page'],
    1 => $form_state['values']['toggle_product'],
  ));
  dsm('The form simplification has been turned ' . $form_state['values']['toggle_front_page'] . ' for the Front Page');
  dsm('The form simplification has been turned ' . $form_state['values']['toggle_product'] . ' for adding Products');
}
