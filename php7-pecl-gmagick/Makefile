#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PECL_NAME:=gmagick
PECL_LONGNAME:=Provides a wrapper to the GraphicsMagick library

PKG_VERSION:=2.0.6RC1
PKG_RELEASE:=1
PKG_HASH:=350cb71a4fbd58e037c7182cafa14e6f6df952126869205918fcc9ec5798e2fa

PKG_NAME:=php7-pecl-$(PECL_NAME)
PKG_SOURCE:=$(PECL_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=http://pecl.php.net/get

PKG_BUILD_DIR:=$(BUILD_DIR)/pecl-php7/$(PECL_NAME)-$(PKG_VERSION)
PKG_BUILD_PARALLEL:=1

PKG_MAINTAINER:=Entware team, https://entware.net

PKG_LICENSE:=PHP-3.01
PKG_LICENSE_FILES:=LICENSE

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(TOPDIR)/feeds/packages/lang/php7/pecl.mk

CONFIGURE_VARS += \
	WAND_BINARY=$(STAGING_DIR_ROOT)/opt/bin/GraphicsMagick-config

TARGET_CPPFLAGS += \
	-I$(STAGING_DIR)/opt/include/GraphicsMagick

$(eval $(call PHP7PECLPackage,$(PECL_NAME),$(PECL_LONGNAME),+graphicsmagick))
$(eval $(call BuildPackage,$(PKG_NAME)))
