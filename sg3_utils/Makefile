# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2019-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=sg3_utils
PKG_VERSION:=1.48
PKG_REV:=c2710e0ac7002193d63e843723e987015ca3b13d
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/hreinecke/sg3_utils.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=f6ce7ce2e72ae616c20e736f0f189c40c64364b137e45e22aecc4726e7c9b464

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/sg3_utils
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Disc
	TITLE:=utilities that send SCSI commands to devices
	URL:=http://sg.danny.cz/sg/sg3_utils.html
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/sg3_utils/description
 This package contains utilities that send SCSI commands to devices. As well as
 devices on transports traditionally associated with SCSI (e.g. Fibre Channel
 (FCP), Serial Attached SCSI (SAS) and the SCSI Parallel Interface(SPI)) many
 other devices use SCSI command sets. ATAPI cd/dvd drives and SATA disks that
 connect via a translation layer or a bridge device are examples of devices
 that use SCSI command sets.
endef

define Package/sg3_utils/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(SED) 's|/bin/bash|/bin/sh|g' \
		$(1)/opt/bin/rescan-scsi-bus.sh
	$(SED) 's|/bin/bash|/bin/sh|g' \
		$(1)/opt/bin/scsi_{logging_level,mandat,readcap,ready,satl,start,stop,temperature}
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib*.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,sg3_utils))
