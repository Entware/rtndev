# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2024 Entware

include $(TOPDIR)/rules.mk

PECL_NAME:=ssh2
PECL_LONGNAME:=Bindings for the libssh2 library

PKG_VERSION:=1.6.0
PKG_RELEASE:=1

PKG_NAME:=php8-pecl-$(PECL_NAME)
PKG_SOURCE:=$(PECL_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_SUBDIR:=$(PECL_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/php/pecl-networking-ssh2.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=4b8098d6efc1b41fb66cb04495926e92ed84ba3b
PKG_MIRROR_HASH:=79559bee338c42a94d9a0fb2c00d8033df23d61d592951dd50eb4129604d8b84

PKG_BUILD_DIR:=$(BUILD_DIR)/pecl-php8/$(PECL_NAME)-$(PKG_VERSION)

PKG_LICENSE:=PHP-3.01
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=Entware team, https://entware.net

PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(TOPDIR)/feeds/packages/lang/php8/pecl.mk

CONFIGURE_ARGS += \
	--with-ssh2=$(STAGING_DIR)/opt

$(eval $(call PHP8PECLPackage,$(PECL_NAME),$(PECL_LONGNAME),+libssh2,20))
$(eval $(call BuildPackage,$(PKG_NAME)))
