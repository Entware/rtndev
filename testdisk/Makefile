#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=testdisk
PKG_VERSION:=7.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://www.cgsecurity.org
PKG_HASH:=1413c47569e48c5b22653b943d48136cb228abcbd6f03da109c4df63382190fe

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
