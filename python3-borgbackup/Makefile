#
# Copyright (C) 2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python3-borgbackup
PKG_VERSION:=1.1.17
PKG_RELEASE:=2

PYPI_NAME:=borgbackup
PKG_HASH:=7ab924fc017b24929bedceba0dcce16d56f9868bf9b5050d2aae2eb080671674

PKG_LICENSE:=BSD-3-Clause
PKG_LICENSE_FILES:=LICENSE

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-borgbackup
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Backup
	DEPENDS:=+python3-light +python3-pkg-resources +python3-packaging +libacl +libopenssl +libstdcpp +zstd
	TITLE:=a deduplicating backup program
	URL:=https://borgbackup.readthedocs.io
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python3-borgbackup/description
 BorgBackup (short: Borg) is a deduplicating backup program. Optionally, it
 supports compression and authenticated encryption.
  The main goal of Borg is to provide an efficient and secure way to backup
 data. The data deduplication technique used makes Borg suitable for daily
 backups since only changes are stored. The authenticated encryption technique
 makes it suitable for backups to not fully trusted targets.
endef

PYTHON3_PKG_SETUP_VARS+= \
	BORG_OPENSSL_PREFIX='$(STAGING_DIR)/opt' \
	BORG_LIBZSTD_PREFIX='$(STAGING_DIR)/opt'

$(eval $(call Py3Package,python3-borgbackup))
$(eval $(call BuildPackage,python3-borgbackup))
