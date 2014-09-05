<?php
/**
 * @file
 * All view hooks.
 */

/**
 * Implements hook_views_data()
 */ 
function eve_recruitment_views_data() {
	$data = array();
	
	// Standard handlers
	$id_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field',
			'click sortable' => TRUE,
		),
		'filter' => array('handler' => 'views_handler_filter_numeric'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument_numeric'),
	);
	$decimal_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field_numeric',
			'click sortable' => TRUE,
		),
		'filter' => array('handler' => 'views_handler_filter_numeric'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument_numeric'),
	);
	$float_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field_numeric',
			'float' => TRUE,
			'click sortable' => TRUE,
		),
		'filter' => array('handler' => 'views_handler_filter_numeric'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument_numeric'),
	);
	$string_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field',
			'click sortable' => TRUE,
		),
		'filter' => array('handler' => 'views_handler_filter_string'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument_string'),
	);
	$date_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field_date',
			'click sortable' => TRUE,
		),
		'filter' => array('handler' => 'views_handler_filter_date'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument'),
	);
	$bool_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field_boolean',
			'click sortable' => TRUE,
		),
		'filter' => array(
			'handler' => 'views_handler_filter_boolean_operator',
		//	'label' => '', The label needs to be defined in each field separately.
			'accept null' => TRUE,
			'use equal' => TRUE,
		),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument'),
	);

	$data['eve_recruitment']['table']['group'] = t('Recruitment');
	$data['eve_recruitment']['table']['base'] = array(
		'field' => 'ref_id',
		'title' => t('Recruitment'),
		'help' => t('Recruitment database of EVE Online characters.'),
		'weight' => 10,
	);

	$field_data = array(
		'title' => t('Reference ID'),
		'help' => t('Unique ID of recruitment entry.'),
	);
	$data['eve_recruitment']['ref_id'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Name'),
		'help' => t('Name of EVE Online character being recruited.'),
	);
	$data['eve_recruitment']['name'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Date Added'),
		'help' => t('Date and time when the name was added to the database.'),
	);
	$data['eve_recruitment']['added_date'] = array_merge($date_handlers, $field_data);

	$field_data = array(
		'title' => t('Date Mailed'),
		'help' => t('Date and time when the recruitment email was sent to the character.'),
	);
	$data['eve_recruitment']['mailed_date'] = array_merge($date_handlers, $field_data);

	$data['eve_recruitment']['added_by'] = array(
		'title' => t('Added By'),
		'help' => t('User who added the character name to the database.'),
		'relationship' => array(
			'label' => t('Added By'),
			'base' => 'users',
			'base field' => 'uid',
		),
	);

	$data['eve_recruitment']['mailed_by'] = array(
		'title' => t('Mailed By'),
		'help' => t('User who sent the recruitment letter to the character.'),
		'relationship' => array(
			'label' => t('Mailed By'),
			'base' => 'users',
			'base field' => 'uid',
		),
	);

	return $data;
}
