#
# Copyright (C) 2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PECL_NAME:=redis
PECL_LONGNAME:=PHP extension for interfacing with Redis

PKG_VERSION:=4.0.2
PKG_RELEASE:=1
PKG_HASH:=36fa980831091efca6586fa347283f79587293aa93c7d42e948e6137bfd90ac8

PKG_NAME:=php7-pecl-$(PECL_NAME)
PKG_SOURCE:=$(PECL_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=http://pecl.php.net/get

PKG_BUILD_DIR:=$(BUILD_DIR)/pecl-php7/$(PECL_NAME)-$(PKG_VERSION)
PKG_BUILD_PARALLEL:=1

PKG_MAINTAINER:=Entware team, https://entware.net

PKG_LICENSE:=PHPv3.01
PKG_LICENSE_FILES:=

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(TOPDIR)/feeds/packages/lang/php7/pecl.mk


CONFIGURE_ARGS+= \
	--enable-redis-lzf

$(eval $(call PECLPackage,$(PECL_NAME),$(PECL_LONGNAME),+php7-mod-session +redis,25))
$(eval $(call BuildPackage,$(PKG_NAME)))
