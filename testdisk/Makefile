# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=testdisk
PKG_VERSION:=7.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://www.cgsecurity.org
PKG_HASH:=f8343be20cb4001c5d91a2e3bcd918398f00ae6d8310894a5a9f2feb813c283f

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/testdisk
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Disc
	DEPENDS:=+libncursesw +libext2fs +ntfs-3g +zlib $(ICONV_DEPENDS)
	TITLE:=data recovery software
	URL:=https://www.cgsecurity.org/wiki/TestDisk
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/testdisk/description
 TestDisk is powerful free data recovery software! It was primarily designed
 to help recover lost partitions and/or make non-booting disks bootable again
 when these symptoms are caused by faulty software: certain types of viruses
 or human error (such as accidentally deleting a Partition Table). Partition
 table recovery using TestDisk is really easy.
endef

define Package/testdisk/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/testdisk $(1)/opt/bin
endef

$(eval $(call BuildPackage,testdisk))
