# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2024 Entware

# Abandoned in 2014

include $(TOPDIR)/rules.mk

PKG_NAME:=ext4magic
PKG_VERSION:=0.3.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/ext4magic
PKG_HASH:=8d9c6a594f212aecf4eb5410d277caeaea3adc03d35378257dfd017ef20ea115

PKG_LICENSE:=GPL-2.0-or-later
PKG_LICENSE_FILES:=COPYING
PKG_MAINTAINER:=Entware team, https://entware.net

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/ext4magic
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Filesystem
  TITLE:=disk utility to recover files
  URL:=https://ext4magic.sourceforge.net/ext4magic_en.html
  DEPENDS:=+libe2p +libext2fs +libmagic +zlib
endef

define Package/ext4magic/description
  Linux admin tool, can help to recover deleted or overwritten files
  on ext3 and ext4 filesystems.
endef

CONFIGURE_ARGS += \
	LIBS="-lcom_err"

define Package/ext4magic/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/ext4magic $(1)/opt/sbin
endef

$(eval $(call BuildPackage,ext4magic))
